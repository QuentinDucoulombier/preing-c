#include "fonction.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int* Allouer(int taille){
    int* tab;
    tab = malloc(taille *sizeof(int));
    return tab;
}

void Initialisation(int taille, int* tab){
    for (int i = 0; i < taille; i++)
    {
        tab[i]=rand()%100;
    }
    
}

void Affichage(int taille, int* tab){
    for (int i = 0; i < taille; i++)
    {
        printf(" | %d",tab[i]);
    }
    printf(" |\n");

}

void Copie(int taille, int* tabOriginal, int* tabCopie){

    for (int i = 0; i < taille; i++)
    {
        tabCopie[i] = tabOriginal[i];
    }
    
}

void Echange(int* monTab, int i, int j){

    int x = monTab[i];
    monTab[i] = monTab[j];
    monTab[j]= x;

}


void Liberer(int* tab){

    free(tab);
    tab=NULL;
}

