#include<stdio.h>
#include<stdlib.h>

int** Alouer2D(int lignes, int colonne){
    int** tab;
    tab=malloc(lignes *sizeof(int*));
    for (int i = 0; i < colonne; i++)
    {
        tab[i]= malloc(colonne * sizeof(int));
    }
    return tab;

}
void Affectation(int tab, int lignes, int colonne){
    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; i < colonne; j++)
        {
            tab
        }
        
    }
    

}

int main (){

    int lignes = 3;
    int colonne = 4;
    int tabMain**;
    tabMain = Alouer2D(lignes, colonne);
    



    return 0;
}