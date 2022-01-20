all: clean
	gcc linked_list.c array.c dataCLI.c -o output

clean:
	rm -f main
