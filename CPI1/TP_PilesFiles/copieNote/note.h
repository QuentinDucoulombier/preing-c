#ifndef NOTE_H
#define NOTE_H

typedef struct Copie
{
    char* nom;
    char* prenom;
    float note;
    struct Copie* suivant;

}Copie;

typedef Copie* Pile;


typedef struct scolarite
{
    Pile tasCopie;
    struct scolarite* precede t;

}scolarite;

typedef scolarite* File;