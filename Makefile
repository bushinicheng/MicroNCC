CC=gcc
LEX=flex
YACC=bison

LFILE=lexical.l
YFILE=syntax.y
CFILES=$(shell find . -name "*.c")
HFILES=$(shell find . -name "*.h")
CFLAGS=-O2 -std=c99

OBJ_DIR=obj/
TEST_DIR=test/
TARGET=compiler

$(TARGET):$(YFILE) $(LFILE) $(CFILES) $(HFILES)
	mkdir -p $(OBJ_DIR)
	$(LEX) -o $(LFILE:.l=.c) $(LFILE)
	$(YACC) $(YFILE) --defines=$(YFILE:.y=.h) -o $(YFILE:.y=.c)
	$(CC) $(CFILES) -o $(TARGET) -lfl

.PHONY:test test-lex test-unit

test:$(TARGET)
	bash test.sh $(TARGET)

test-unit:
	#

test-lex:
	mkdir -p $(OBJ_DIR)
	$(LEX) -o $(LFILE:.l=.c) $(LFILE)
	$(CC) $(LFILE:.l=.c) component.c -o $(TARGET) -lfl
	bash test.sh $(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_DIR)*.err $(TEST_DIR)*.out
