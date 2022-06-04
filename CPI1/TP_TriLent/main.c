#include "fonction.h"
#include "trisLents.h"
#include <stdio.h>


int main(){


    int taille = 50;

    int* tabMainOriginal;
    int* tabMainCopie;


    /*Initialisation... du tabMainOriginal*/
    tabMainOriginal = Allouer(taille);
    Initialisation(taille, tabMainOriginal);
    printf("tableau original\n");
    Affichage(taille, tabMainOriginal);
    

    /*Initialisation... du TabMainCopie*/
    tabMainCopie = Allouer(taille);
    Copie(taille, tabMainOriginal, tabMainCopie);

    triSelection(tabMainCopie, taille);
    printf("\n tri par selection\n");
    Affichage(taille, tabMainCopie);
    Copie(taille, tabMainOriginal, tabMainCopie);

    
    triInsertion(tabMainCopie, taille);
    printf("\n tri par Insertion \n");
    Affichage(taille, tabMainCopie);
    Copie(taille, tabMainOriginal, tabMainCopie);
    

    triBulle(tabMainCopie, taille);
    printf("\n tri par Bulle \n");
    Affichage(taille, tabMainCopie);
    


    Liberer(tabMainOriginal);
    Liberer(tabMainCopie);


    //printf("C'est le TD4");
    return 0;
}