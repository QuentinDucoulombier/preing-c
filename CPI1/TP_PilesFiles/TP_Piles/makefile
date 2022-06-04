exe: piles.o main.o
	gcc -Wall piles.o main.o -o exe

piles.o: piles.c piles.h
	gcc -c piles.c -o piles.o

main.o: main.c piles.h
	gcc -c main.c -o main.o