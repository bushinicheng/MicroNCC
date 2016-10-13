CC=gcc
LEX=flex
YACC=bison

LFILE=lexical.l
YFILE=syntax.y

OBJ_DIR=obj/
TEST_DIR=test/
TARGET=compiler

$(TARGET):
	mkdir -p $(OBJ_DIR)
	$(LEX) -o $(LFILE:.l=.c) $(LFILE)
	$(YACC) $(YFILE) --defines=$(YFILE:.y=.h) -o $(YFILE:.y=.c)
	$(CC) $(YFILE:.y=.c) $(LFILE:.l=.c) -o $(TARGET) -lfl

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
