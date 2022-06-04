#include "trisRapide.h"
#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

/*
void TriRapide(int* tab, int debut, int fin)
{
    int pivot;
    if (debut < fin)
    {
        
        pivot = Partitionner(tab, debut, fin);
        TriRapide(tab, debut, pivot - 1);
        TriRapide(tab, pivot + 1, fin);
    }
}


int Partitionner(int* tab, int debut, int fin)
{
    int pivot = tab[fin];
    int i = debut - 1;
    

    for (int j = debut; j < fin; j++)
    {
        if (tab[j] <= pivot)
        {
            i++;
            Echange(tab, i, j);
        }
        
    }
    Echange(tab, i+1, fin);
    return (i + 1);
    
}
*/

void TriRapide(int* tab, int debut, int fin)
{
    int pivot;

    if (debut<fin)
    {
        pivot = Partitionner(tab, debut, fin);
        TriRapide(tab, debut, pivot);
        TriRapide(tab, pivot+1, fin);
    }
}


int Partitionner(int* tab, int debut, int fin){
    int pivot;
    int i,j;

    pivot = tab[debut];
    i=debut-1;
    j=fin+1;

    while (i<j)
    {
        do
        {
            j--;
        } while (tab[j]>pivot);
        do
        {
            i++;
        } while (tab[i]<pivot);
        if (i<j)
        {
            Echange(tab, i, j);
        }

    }
    return j;
}


void TriFusion(int* tab, int debut, int fin){

    int milieu;
    
    if (debut < fin)
    {
        milieu = (debut + fin) / 2;
        TriFusion(tab, debut, milieu);
        TriFusion(tab, milieu + 1, fin);
        Fusionner(tab, debut, milieu, fin);
        
    }
    
}

void Fusionner(int* tab, int debut, int milieu, int fin){

    int i = 0;
    int max = fin - debut;
    int gauche = debut;
    int droite = milieu + 1;
    int* tabTemporaire = Allouer(fin);


    
    while ((gauche <= milieu) && (droite <= fin))
    {
        if (tab[gauche] < tab[droite])
        {
            tabTemporaire[i] = tab[gauche];
            gauche ++;
        }
        else
        {
            tabTemporaire[i] = tab[droite];
            droite ++;

        }
        i ++;  
    }
    
    while (gauche <= milieu)
    {
        tabTemporaire[i] =  tab[gauche];
        gauche ++;
        i ++;
    }

    while (droite <= fin)
    {
        tabTemporaire[i] = tab[droite];
        droite ++;
        i ++;
    }
    
    for (i = 0; i < max + 1; i++)
    {
        tab[i + debut] = tabTemporaire[i];
    }

}
