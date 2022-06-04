#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Fonction et procedure appelé dans le main */

int* Initialisation(int lignes){
    
    int* tab;
    tab = NULL;
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

int* AffectionFusion (int* tabFinal, int taille1, int tailleFinal, int* tab1, int* tab2){
    
    for (int i = 0; i < taille1; i++)
    {
        tabFinal[i] = tab1[i];
    }
    for (int j = taille1; j < tailleFinal; j++)
    {
        tabFinal[j] = tab2[j- taille1];
    }
    return tabFinal;
}


void Affichage (int *tab, int lignes){

    for (int i = 0; i < lignes; i++)
    {
        printf("i=%d valeur=%d",i,tab[i]);
        printf("\n");
    }
}

void Free(int *tab){

    free(tab);
    tab=NULL;
}

/* Le main en gros */

int main(){

    int* tabFusion;
    int* tab1;
    int* tab2;

    srand(time(NULL));
    /* Initialisation de la taille de tableau aleatoire en 0 et 9 */
    int lignes1 = rand() % 10;
    int lignes2 = rand() % 10;
    int lignesFusion = lignes1 + lignes2;
    //printf("%d", lignesFusion);

    /* Initialisation de mes deux tableaux */
    tab1 = Initialisation(lignes1);
    tab2 = Initialisation(lignes2);
    /* Affectation de mes deux tableaux */
    Affectation(tab1, lignes1);
    Affectation(tab2, lignes2);
    /* Affichage de mes deux tableaux */
    printf("----------Tableau 1----------\n");
    Affichage(tab1, lignes1);
    printf("\n");
    printf("----------Tableau 2----------\n");
    Affichage(tab2, lignes2);
    
    

    /* Initialisation/Affection/Affichage de mon tableau Fusion */
    tabFusion = Initialisation(lignesFusion);
    tabFusion = AffectionFusion(tabFusion, lignes1, lignesFusion, tab1, tab2);
    printf("\n");
    printf("---------Tableau Fusion--------\n");
    Affichage(tabFusion, lignesFusion);


    /* On free tout nos tableau */

    Free(tab1);
    Free(tab2);
    Free(tabFusion);


}