#ifndef _FILES_H_
#define _FILES_H_

typedef struct Personne
{
    char* nom;
    struct Personne* precedent;

}Personne;


typedef Personne* File;





void Enfiler(File* f, char* potion);
void Afficher(File f);
char* DefilerF(File *f);
int CompterF (File f);
File* Inverser(File* f);
void Vider(File* f);

#endif