exe: fonction.o trisLents.o  trisRapide.o main.o
	gcc -Wall fonction.o trisLents.o trisRapide.o main.o -o exe

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -o fonction.o

trisLents.o: trisLents.c trisLents.h
	gcc -c trisLents.c -o trisLents.o

trisRapide.o: trisRapide.c trisRapide.h
	gcc -c trisRapide.c -o trisRapide.o

main.o: main.c fonction.h trisLents.h
	gcc -c main.c -o main.o