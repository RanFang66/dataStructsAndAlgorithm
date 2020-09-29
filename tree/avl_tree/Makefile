#! Makefile

PROGRAM = avl_test
C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

$(PROGRAM) : $(C_OBJECTS)
	cc -o $(PROGRAM) $(C_OBJECTS)

$(C_OBJECTS) : avl_tree.h

.PHONY : clean
clean :
	rm $(PROGRAM) $(C_OBJECTS)