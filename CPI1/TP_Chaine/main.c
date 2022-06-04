#include "liste.h"
#include <stdio.h>



int main(){


    teteListe Liste = NULL;


    /* Initialisation de ma liste 1 */
    AjouterDebut(&Liste, 2);
    AjouterDebut(&Liste, 5);
    AjouterDebut(&Liste, 4);
    ajouterPos(&Liste, 26, 1);
    ajouterPos(&Liste, 102, 5);
    AjouterFin(&Liste, 103);
    //Affichage(Liste);
    //SupprimerDebut(&Liste);
    //SupprimerFin(&Liste);
    SupprimerPosition(&Liste, 3);
    //Affichage(Liste);

    


    teteListe Liste2 = NULL;

    AjouterDebut(&Liste2, 8);
    AjouterDebut(&Liste2, 14);
    AjouterDebut(&Liste2, 62);
    AjouterFin(&Liste2, 0);
    ajouterPos(&Liste2, 335, 2);
    ajouterPos(&Liste2, 12, 4);

    



    Affichage(Liste);
    printf("taille : %d\n", Taille(Liste));
    
    printf("\n");
    Affichage(Liste2);
    printf("taille : %d\n", Taille(Liste2));

    printf("\n");
    Concatener(&Liste, &Liste2);
    Affichage(Liste);
    printf("taille : %d\n", Taille(Liste));



    int donnee;
    printf("Veuillez rentrer une valeur\n");
    scanf("%d", &donnee);
    int posValeur = RechercherPos(&Liste, donnee);

    if (posValeur != 0)
    {
        printf("ma position est %d\n", posValeur);
    }
    else
    {
        printf("Cette valeur n'est pas dans la chaine\n");
    }

    printf("Le nombre d'occurence est de %d\n", rechercheOccu(Liste, donnee));

    
    
    
    


    return 0;
}