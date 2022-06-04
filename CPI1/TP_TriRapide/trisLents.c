#include "trisLents.h"
#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>



void triSelection(int* tab, int taille){

    for (int i = 0; i < taille - 1; i++)
    {
        int mini = i;
        for (int j = i+1 ; j < taille; j++)
        {
            if(tab[j] < tab[mini]){
                mini = j;
            }
        }
        Echange(tab, i, mini);
    }
    
}

void triInsertion(int* tab, int taille){
    int elementInsere;

    int j;
    for (int i = 1; i < taille; i++)
    {
        elementInsere = tab[i];

        for (j = i; j > 0 && tab[j - 1] > elementInsere; j--)
        {
            tab[j] = tab[j - 1];
        }
        tab[j] = elementInsere;
    }
    

}

void triBulle (int* tab, int taille){

    int compteur = 1;

    while (compteur)
    {
        compteur = 0;
        for (int i = 0; i < taille -1; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                Echange(tab, i, i+1);
                compteur = compteur + 1;
            }
            
        }
        
    }
    
}