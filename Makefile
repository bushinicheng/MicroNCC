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

.PHONY:test

test:$(TARGET)
	bash test.sh $(TARGET)

clean:
	rm -rf $(OBJ_DIR)
