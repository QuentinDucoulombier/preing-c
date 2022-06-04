exe: fonction.o trisLents.o main.o
	gcc fonction.o trisLents.o main.o -o exe

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -o fonction.o

trisLents.o: trisLents.c trisLents.h
	gcc -c trisLents.c -o trisLents.o

main.o: main.c fonction.h trisLents.h
	gcc -c main.c -o main.o