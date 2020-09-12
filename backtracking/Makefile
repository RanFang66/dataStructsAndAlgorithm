#! Makefile
PROGRAM = subsets
C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

$(PROGRAM) : $(C_OBJECTS)
	cc $(C_OBJECTS) -o $(PROGRAM)

$(C_OBJECTS) : array_list.h

.PHONY : clean
clean :
	rm $(C_OBJECTS) $(PROGRAM)
