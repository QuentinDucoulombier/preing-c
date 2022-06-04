#include "piles.h"
#include <stdio.h>


int main(){

    Pile p= NULL ;

    Pile pLink = NULL;
    Pile pKilton = NULL;
    Pile pZelda = NULL;


    /*---------On empile les fleches-----------*/

    /*Fleche de Link*/
    Empiler(&pLink, rouge);
    Empiler(&pLink, verte);
    Empiler(&pLink, rouge);
    Empiler(&pLink, bleue);
    Empiler(&pLink, verte);
    Empiler(&pLink, verte);
    Empiler(&pLink, verte);


    /*Fleche de Kliton*/
    Empiler(&pKilton, verte);
    Empiler(&pKilton, verte);
    Empiler(&pKilton, verte);
    Empiler(&pKilton, bleue);
    Empiler(&pKilton, bleue);
    Empiler(&pKilton, bleue);
    Empiler(&pKilton, rouge);


    /*Fleche de Zelda*/
    Empiler(&pZelda, rouge);
    Empiler(&pZelda, rouge);
    Empiler(&pZelda, verte);
    Empiler(&pZelda, rouge);
    Empiler(&pZelda, verte);

    /*Affichage*/
    AfficherFinal(pLink, pKilton, pZelda);



    //printf(("Je depile %d\n"), Depiler(&pLink));
    for (int i = 0; i < 2; i++)
    {
        Empiler(&pKilton, Depiler(&pLink));
    }
    

    /*Affichage*/
    printf("\n\n");
    printf("------------Question 3-------------\n");
    printf("\n\n");
    AfficherFinal(pLink, pKilton, pZelda);


    for (int j = 0; j < 3; j++)
    {
        Depiler(&pKilton);
    }
    


    printf("\n\n");
    printf("------------Question 4-------------\n");
    printf("\n\n");
    AfficherFinal(pLink, pKilton, pZelda);

    printf("\n\n");
    printf("------------Question 5-------------\n");
    printf("\n\n");
    printf("Le nombre de fleche de Zelda est de %d\n", Compter(pZelda));
    printf("Le nombre de fleche de Kilton est de %d\n", Compter(pKilton));

    printf("\n");

    if (Compter(pZelda) > Compter(pKilton))
    {
        printf("Zelda a plus de fleche de Kilton\n");
    }
    if (Compter(pKilton) > Compter(pZelda))
    {
        printf("Kilton a plus de fleche\n");
    }
    if (Compter(pKilton) == Compter(pZelda))
    {
        printf("ils ont le meme nombre de fleches\n");
    }
    

    printf("\n\n");
    printf("------------Question 6-------------\n");
    printf("\n\n");
    Empiler(&pLink, bleue);
    Empiler(&pLink, verte);
    printf("Les fleches de Link sont donc:\n");
    AfficherP(pLink);
    printf("\n");
    

    printf("\n\n");
    printf("------------Question 7-------------\n");
    printf("\n\n");
    for (int i = 0; i < 4; i++)
    {
        Empiler(&pKilton, Depiler(&pLink));
    }
    AfficherFinal(pLink, pKilton, pZelda);
    

    printf("\n\n");
    printf("------------Question 8-------------\n");
    printf("\n\n");
    for (int i = 0; i < 2; i++)
    {
        Empiler(&pZelda, Depiler(&pLink));
    }
    AfficherFinal(pLink, pKilton, pZelda);

    printf("\n\n");
    printf("------------Question 9-------------\n");
    printf("\n\n");
    Pile pTemp = NULL;
    pZelda = InverserP(&pZelda, &pTemp);
    AfficherFinal(pLink, pKilton, pZelda);
    
    printf("\n\n");
    printf("------------Question 10-------------\n");
    printf("\n\n");
    DoublerP(&pLink);
    AfficherFinal(pLink, pKilton, pZelda);


    printf("\n\n");
    printf("------------Question 11-------------\n");
    printf("\n\n");
    Vider(&pLink);
    Vider(&pZelda);
    Vider(&pKilton);
    AfficherFinal(pLink, pKilton, pZelda);



    return 0;
}