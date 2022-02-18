all: clean
	gcc binary_tree.c stack.c linked_list.c queue.c array.c dataCLI.c -o output

clean:
	rm -f main
