all: clean
	gcc print.c linked_list.c -o output

clean:
	rm -f main
