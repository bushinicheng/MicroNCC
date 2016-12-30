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
CFLAGS=-O2 -std=c11

OBJ_DIR=output/
TEST_DIR=test/
COMPILER=compiler

#CMM=test/simple.cmm
#CMM=test/token.cmm
CMM=test/testerr.cmm

all:$(COMPILER)

$(LCFILE):$(LFILE)
	$(LEX) -o $(LCFILE) $(LFILE)

$(YHFILE) $(YCFILE):$(YFILE)
	$(YACC) -v $(YFILE) --defines=$(YHFILE) -o $(YCFILE)

$(COMPILER):$(YFILE) $(LFILE) $(CFILES) $(HFILES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CFILES) -o $(COMPILER) -lfl

ast.h:syntax.y
	python genast.py > ast.h

.PHONY:run run-ast run-rdu test test-lex clean count

run:$(COMPILER)
	./$(COMPILER) $(CMM)

run-ast:$(COMPILER)
	./$(COMPILER) --print-ast $(CMM)

run-rdu:$(COMPILER)
	./$(COMPILER) --print-reduce $(CMM)

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

count:
	@printf "total lines: "
	@find . -name "*.[chl]" | sed "s/.\/\(lexical.c\|syntax.c\)//g" | xargs cat | wc -l
