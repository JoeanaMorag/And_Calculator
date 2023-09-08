my_and: my_and.o
	gcc -ansi -Wall -g my_and.o -o my_and
my_and.o: my_and.c 
	gcc -c -ansi -Wall my_and.c -o my_and.o
