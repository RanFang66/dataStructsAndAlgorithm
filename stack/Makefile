PROGRAM = stack_test

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

PROGRAM : $(C_OBJECTS)
	cc $(C_OBJECTS) -o $(PROGRAM)

$(C_OBJECTS) : stack.h

.PHONY : clean
clean :
	rm $(PROGRAM) $(C_OBJECTS)

