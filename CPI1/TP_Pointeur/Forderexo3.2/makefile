exe: fonctions.o main.o
	gcc fonctions.o main.o -o exe

fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c  -o fonctions.o

main.o: main.c fonctions.h
	gcc -c main.c -o main.o