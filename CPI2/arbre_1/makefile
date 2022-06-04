exe: arbre.o main.o
	gcc -Wall arbre.o main.o -o exe

arbre.o: arbre.c arbre.h
	gcc -c arbre.c -o arbre.o

main.o: main.c arbre.h
	gcc -c main.c -o main.o