objects = main.o bubble_sort.o select_sort.o insert_sort.o shell_sort.o quick_sort.o merge_sort.o

sort_test : $(objects)
	cc $(objects) -o sort_test

$(objects) : common.h

.PHONY : clean
clean:
	rm sort_test $(objects)
