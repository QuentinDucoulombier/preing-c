#include "fonction.h"
#include "trisLents.h"
#include "trisRapide.h"
#include <stdio.h>
#include <time.h>


int main(){


    int taille = 100;

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
    Copie(taille, tabMainOriginal, tabMainCopie);


    TriRapide(tabMainCopie, 0, taille - 1);
    printf("\n tri Rapide \n");
    Affichage(taille, tabMainCopie);
    Copie(taille, tabMainOriginal, tabMainCopie);

    TriFusion(tabMainCopie, 0, taille - 1);
    printf("\n tri Fusion \n");
    Affichage(taille, tabMainCopie);


    /*-------Horloge----------*/


    clock_t t1,t2;
    float temps_total;

    /*Tri par selection*/

    t1=clock();
    triSelection(tabMainCopie, taille);
    t2=clock();
    temps_total= (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("Le tri par selection a mis %f de secondes à s'executer \n",temps_total);
    Copie(taille, tabMainOriginal, tabMainCopie);


    /*Tri par insertion*/
    
    t1=clock();
    triInsertion(tabMainCopie, taille);
    t2=clock();
    temps_total= (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("Le Tri par Insertion a mis %f de secondes à s'executer \n",temps_total);
    Copie(taille, tabMainOriginal, tabMainCopie);


    /*Tri a bulle*/

    t1=clock();
    triBulle(tabMainCopie, taille);
    t2=clock();
    temps_total= (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("Le Tri a bulle a mis %f de secondes à s'executer \n",temps_total);
    Copie(taille, tabMainOriginal, tabMainCopie);

    /*Tri Rapide*/


    t1=clock();
    TriRapide(tabMainCopie, 0, taille - 1);
    t2=clock();
    temps_total= (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("Le Tri rapide a mis %f de secondes à s'executer \n",temps_total);
    Copie(taille, tabMainOriginal, tabMainCopie);


    /*Tri Fusion*/

    t1=clock();
    TriFusion(tabMainCopie, 0, taille - 1);
    t2=clock();
    temps_total= (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("Le Tri fusion a mis %f de secondes à s'executer \n",temps_total);


    Liberer(tabMainOriginal);
    Liberer(tabMainCopie);


    //printf("C'est le TD4");
    return 0;

}