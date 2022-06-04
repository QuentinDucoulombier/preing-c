#include "fonctions.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Menu */

int menu(void)
{
    int int_choix;  /* Choix de l'utilisateur */

    do
    {
        printf ("1 - Tableau d'entier\n");
        printf ("2 - Chaine de Caractere\n");
     
        printf ("Quel est votre choix : ");
        scanf ("%d", &int_choix);
        printf("\n");
    } while (((int_choix < 1) || (int_choix > 2)));

    return (int_choix);
    
}


/* Tableau d'entier */

int* Initialisation(int lignes){
    
    int* tab;
    tab=malloc(lignes * sizeof(int));
    return tab;
}

void Affectation (int *tab, int lignes){

    srand(time(NULL));

    for (int i = 0; i < lignes; i++)
    {
        tab[i]=rand() % 101;
    }

}


void Affichage (int *tab, int lignes){

    for (int i = 0; i < lignes; i++)
    {
        printf("i=%d valeur=%d",i,tab[i]);
        printf("\n");
    }
}



/* Tableau de caracteres */

char* InitialisationChaine(int max){

    char*tab;
    tab = (char*) malloc(max *sizeof(char));
    return tab;
}

void AffichageEtAffectationChaine(char *tab, int lignes){
    printf("Veullez saisir une chaine\n");
    scanf("%s", tab);
    printf("Ma chaine : %s \n", tab);

}
