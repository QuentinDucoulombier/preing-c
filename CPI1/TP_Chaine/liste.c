#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void AjouterDebut(teteListe* l, int valeur){
    maillon* m;

    m = malloc(sizeof(maillon));
    m -> donnee = valeur;
    m -> suivant = (*l);
    (*l) = m;

}


void AjouterFin(teteListe* l, int valeur){

    maillon* m;
    teteListe temp;

    m = malloc(sizeof(maillon));
    m -> donnee = valeur;
    m -> suivant = NULL;
    temp = (*l);

    if (temp != NULL)
    {
        while (temp -> suivant != NULL)
        {
            temp = temp -> suivant;
        }
        temp -> suivant = m;
    }
    else
    {
        temp = m;
    }
}

void ajouterPos(teteListe* l, int valeur, int pos){
    maillon* m = malloc(sizeof(maillon));
    maillon* mTemp = malloc(sizeof(maillon));
    teteListe temp = (*l);
    int i = 0;

    m -> donnee = valeur;
    m -> suivant = NULL;

    while (temp -> suivant != NULL && i != (pos - 1))
    {
        temp = temp -> suivant;
        i++;
    }

    mTemp = temp -> suivant;
    m -> suivant = mTemp;
    temp -> suivant = m;
    

}

int SupprimerDebut(teteListe* l)
{
    teteListe temp = (*l);
    int eltSuppr = temp -> donnee;
    (*l) = temp -> suivant;
    return eltSuppr;
}

int SupprimerFin(teteListe* l)
{
    teteListe temp = (*l);
    int eltSuppr;

    if (temp != NULL)
    {
        while (temp -> suivant -> suivant != NULL)
        {
            temp = temp -> suivant;

        }
        eltSuppr = temp -> suivant -> donnee;
        temp -> suivant = NULL;
    }
    else
    {
        temp = NULL;
        eltSuppr = -1;
    }
    return eltSuppr;
}

int SupprimerPosition(teteListe* l, int position)
{
    teteListe temp = (*l);
    int eltSuppr;
    int i = 0;

    while ((temp -> suivant != NULL) && (i != (position - 1)))
    {
        temp = temp -> suivant;
        i++;
    }
    eltSuppr = temp -> suivant -> donnee;
    temp -> suivant = temp -> suivant -> suivant;
    return eltSuppr;
    
}




int RechercherPos(teteListe* l, int valeurRecherche){


    int position;
    int trouve = 0;
    teteListe temp = (*l);
    int i = 0;

    while (temp != NULL && !trouve)
    {
        if (temp -> donnee == valeurRecherche)
        {
            position = i;
            trouve = 1;
        }
        else
        {
            temp = temp -> suivant;
            i++;
        }
        
    }

    if (!trouve)
    {
        position = (-1);
    }
}

int rechercheOccu(teteListe l, int valeur){

    teteListe temp;
    int cptOccu;
    cptOccu = 0;
    temp = l;

    while (temp != NULL)
    {
        if (valeur == temp -> donnee)
        {
            cptOccu++;
        }
        temp = temp -> suivant;
    }
    return cptOccu;
}


void Concatener(teteListe* l1, teteListe* l2)
{
    
    teteListe temp1 = (*l1);
    teteListe temp2 = (*l2);
    teteListe temp3 = NULL;

    AjouterDebut(&temp3, temp1 -> donnee);
    temp1 = temp1 -> suivant;
    
    while (temp1 != NULL)
    {
        AjouterFin(&temp3, temp1 -> donnee);
        temp1 = temp1 -> suivant;
    }

    while (temp2 != NULL)
    {
        AjouterFin(&temp3, temp2 -> donnee);
        temp2 = temp2 -> suivant;
    }
    if (temp3 == NULL)
    {
        printf("aucun sens \n\n");
    }
    (*l1) = temp3;

}


void Affichage(teteListe l){

    teteListe temp;
    temp = l;
    int i = 0;

    if (temp == NULL)
    {
        printf("ma liste est vide zebi !\n");
    }
    else
    {
        printf("-----------------\n");
        while (temp != NULL)
        {
            printf("Maillon N°%d: %d\n", i, temp -> donnee);
            temp = temp -> suivant;
            i++;
            
        }
        printf("-----------------\n");
    }
}


int Taille(teteListe l){


    int i = 0;
    teteListe temp = l;

    while (temp != NULL)
    {
        temp = temp -> suivant;
        i++;

    }
    return i;
}
