exe: note.o main.o
	gcc -Wall note.o main.o -o exe

note.o: note.c note.h
	gcc -c note.c -o note.o

main.o: main.c note.h
	gcc -c main.c -o main.o