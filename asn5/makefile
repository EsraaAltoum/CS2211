all: a5

a5: main.o list.o memory.o bst.o datatype.o
		gcc main.o list.o memory.o bst.o datatype.o -o a5

main.o: main.c
		gcc -c main.c

memory.o: memory.c
		gcc -c memory.c

bst.o: bst.c
		gcc -c bst.c

datatype.o: datatype.c
		gcc -c datatype.c

clean: 
		rm -r *.o a5
