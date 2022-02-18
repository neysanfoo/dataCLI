all: clean
	gcc stack.c linked_list.c queue.c array.c dataCLI.c -o output

clean:
	rm -f main
