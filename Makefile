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

$(foreach part,$(ALL_PARTS),$(eval $(part): $($(part)_PART_OBJ)))

# final target file: executable file
$(COMPILER): $(foreach part,$(ALL_PARTS),$($(part)_PART_OBJ))
	@$(CC) $^ -o $(COMPILER)

gdb: $(COMPILER)
	@gdb $(COMPILER)

run: $(COMPILER)
	@./$(COMPILER)

clean:
	rm -rf $(OBJ_DIR)
