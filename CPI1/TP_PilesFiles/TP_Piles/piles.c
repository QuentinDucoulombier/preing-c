#include "piles.h"
#include <stdio.h>
#include <stdlib.h>


void Empiler(Pile* p, int valeur){

    ElementP* nouveau = malloc(sizeof(nouveau));

    if (nouveau != NULL)
    {
        nouveau -> fleche = valeur;
        nouveau -> suivant = *p;
        *p = nouveau;
    }
    
}


int Depiler(Pile* p){

    if (p == NULL)
    {
        printf("Erreur la pile est vide !!!!\n");
        exit(EXIT_FAILURE);
    }
    
    int nombreDepile = 0;
    ElementP* elementDepile = *p;

    if (p != NULL && *p != NULL)
    {
        nombreDepile = elementDepile -> fleche;
        *p = elementDepile -> suivant;
        free(elementDepile);
    }
    
    return nombreDepile;
}


int Compter (Pile p){
    int res = 0;


    if (p != NULL)
    {
        Pile temp = p;
        while (temp != NULL)
        {
            res++;
            temp = temp -> suivant;
        }
    }
    return res;
}


Pile InverserP(Pile* p1, Pile* p2){

    float elt;
    if (*p1 == NULL)
    {
        free(*p1);
        return *p2;
    }
    else
    {
        elt = Depiler(p1);
        Empiler(p2, elt);
        return (InverserP(p1,p2));
    }
}




void DoublerP(Pile* p){

    Pile temp1 = NULL;
    Pile temp2 = NULL;
    int valeurTemp;

    while (*p != NULL)
    {
        valeurTemp = Depiler(p);
        Empiler(&temp1, valeurTemp); 
        Empiler(&temp2, valeurTemp);
    }
    
    while (temp1 != NULL)
    {
        Empiler(p, Depiler(&temp1));
    }
    
    while (temp2 != NULL)
    {
        Empiler(p, Depiler(&temp2));
    }
    
}



void Vider(Pile* p){

    while(*p != NULL)
    {
        int elt = Depiler(p);
        elt = 0;
    }
    
}

/*
    if (p != NULL)
    {
        
        ElementP* temp = *p;
        temp = InverserP(&p, &temp);
        for (int i = 0; i <= max; i++)
        {
            Empiler(p, temp->fleche);
            temp = temp->suivant;
        }
    }
}
*/
void AfficherP(Pile p){

    if (p != NULL)
    {
        Pile temp = p;
        
        while (temp != NULL)
        {
            switch (temp -> fleche)
            {
            case 0:
                printf("\e[1;31m}------->\e[0m \n");
                break;

            case 1:
                printf("\e[1;32m}------->\e[0m \n");
                break;
            
            case 2:
                printf("\e[1;34m}------->\e[0m \n");
                break;

            default:
                printf("Couleur inconnue\n");
                
            }
            temp = temp -> suivant;
        } 
    }
    else
    {
        printf("C'est vide\n");
        
    }
}

void AfficherFinal(Pile pLink, Pile pKilton, Pile pZelda){
    printf("Les fleches de Link sont:\n");
    AfficherP(pLink);
    printf("\n");

    printf("Les fleches de Klinton sont:\n");
    AfficherP(pKilton);
    printf("\n");

    printf("Les fleches de Zelda sont:\n");
    AfficherP(pZelda);

}
