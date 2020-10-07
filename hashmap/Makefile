#! Makefile

PROGRAM = hash_test
C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

$(PROGRAM) : $(C_OBJECTS)
	cc $(C_OBJECTS) -o $(PROGRAM)

$(OBJECTS) : hashmap.h hash_func.h

.PHONY : clean

clean :
	rm $(C_OBJECTS) $(PROGRAM)