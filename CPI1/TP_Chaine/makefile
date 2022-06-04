exe: liste.o main.o
	gcc -Wall liste.o main.o -o exe

liste.o: liste.c liste.h
	gcc -c liste.c -o liste.o

main.o: main.c liste.h
	gcc -c main.c -o main.o