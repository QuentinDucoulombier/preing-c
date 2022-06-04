exe: files.o main.o
	gcc -Wall files.o main.o -o exe

files.o: files.c files.h
	gcc -c files.c -o files.o

main.o: main.c files.h
	gcc -c main.c -o main.o