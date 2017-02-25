CC := gcc
LD := ld
CFLAGS := -c -std=c11 -O2 -MMD -fno-builtin -fno-stack-protector -include common.h # -m32
LDFLAGS := -r # -m elf_i386 -nostdlib
OBJ_DIR := output
COMPILER := $(OBJ_DIR)/MicroNCC
# add your target here
ALL_PARTS := front lib entry

.PHONY: count run clean gdb $(ALL_PARTS)

all: $(COMPILER)

include Makefile.build
include $(patsubst %,%/Makefile.part,$(ALL_PARTS))

# use your own testcase
TESTCASE := test/more.c

# add your part target rule here
front: $(front_PART_OBJ)
lib: $(lib_PART_OBJ)
entry: $(entry_PART_OBJ)
#$(eval $(foreach part,$(ALL_PARTS),"\n"$(part): $($(part)_PART_OBJ)))

# final target file: executable file
$(COMPILER): $(front_PART_OBJ) $(lib_PART_OBJ) $(entry_PART_OBJ)
	$(CC) $^ -o $(COMPILER)

gdb: $(COMPILER)
	@gdb $(COMPILER)

run: $(COMPILER)
	./$(COMPILER)

clean:
	rm -rf $(OBJ_DIR)
