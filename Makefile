CC=gcc
LEX=flex
YACC=bison

LFILE=lexical.l
YFILE=syntax.y
LCFILE=$(LFILE:.l=.c)
YCFILE=$(YFILE:.y=.c)
YHFILE=$(YFILE:.y=.h)
CFILES=$(shell find . -name "*.c")
HFILES=$(shell find . -name "*.h")
CFLAGS=-O2 -std=c99

OBJ_DIR=obj/
TEST_DIR=test/
COMPILER=compiler

all:$(COMPILER)

$(LCFILE):$(LFILE)
	$(LEX) -o $(LCFILE) $(LFILE)

$(YHFILE) $(YCFILE):$(YFILE)
	$(YACC) $(YFILE) --defines=$(YHFILE) -o $(YCFILE)

$(COMPILER):$(YFILE) $(LFILE) $(CFILES) $(HFILES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFILES) -o $(COMPILER) -lfl

.PHONY:test test-lex clean

test:$(COMPILER)
	bash test.sh $(COMPILER)

test-lex:
	mkdir -p $(OBJ_DIR)
	$(LEX) -o $(LFILE:.l=.c) $(LFILE)
	$(CC) $(LFILE:.l=.c) component.c -o $(COMPILER) -lfl
	bash test.sh $(COMPILER)

clean:
	rm -rf $(COMPILER)
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_DIR)*.err $(TEST_DIR)*.out
