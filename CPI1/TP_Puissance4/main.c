#include <stdio.h>
#include "puissance4.h"
#include<stdlib.h>


int main (){
    printf("C'est le puissance 4 !\n\n");

    int lignes = 6;
    int colonnes = 7;
    int **tabMain = NULL;
    int joueur;
    int pionPlace;
    int gagner;


    joueur = ChoixJoueur();
    tabMain = Allouer(lignes, colonnes);
    Initialisation(tabMain, lignes, colonnes);
    pionPlace = Jouer(tabMain,lignes, colonnes, joueur);
    gagner = AGagne(tabMain, lignes, colonnes);
    TourDeJeu(tabMain, lignes, colonnes, gagner, joueur);
    Affichage(tabMain, lignes, colonnes);
    
    
    Libere(tabMain, lignes, colonnes);

    return 0;
}
    