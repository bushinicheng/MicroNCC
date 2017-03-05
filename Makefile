CC := gcc
LD := ld
CFLAGS := -c -std=c11 -O0 -Wall -ggdb -MMD -fno-builtin -fno-stack-protector -include common.h # -m32
LDFLAGS := -r # -m elf_i386 -nostdlib
OBJ_DIR := output
COMPILER := $(OBJ_DIR)/MicroNCC
# add your module name here
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
	@gdb --args $(COMPILER) $(TESTCASE)

run: $(COMPILER)
	@./$(COMPILER) $(TESTCASE)

clean:
	rm -rf $(OBJ_DIR)

count:
	@printf "total lines: "
	@find . -name "*.c" -or -name "*.h" | sed "s/\(.\/test.*\|.\/front\/lexical.c\|.\/front\/syntax.c\|.\/front\/syntax.h\)//g" | xargs cat | wc -l
