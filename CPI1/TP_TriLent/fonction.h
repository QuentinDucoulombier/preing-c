#ifndef __fonction_H_
#define __fonction_H_

int* Allouer(int taille);
void Initialisation(int taille, int* tab);
void Affichage(int taille, int* tab);
void Copie(int taille, int* tabOriginal, int* tabCopie);
void Echange(int* tab, int i, int j);

void Liberer(int* tab);


#endif