objects = main.o link_list.o

list_test : $(objects)
	cc -o list_test $(objects)

$(objects) : link_list.h

.PHONY : clean
clean :
	rm list_test $(objects)
