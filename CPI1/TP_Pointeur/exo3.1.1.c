#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (){

    srand(time(NULL));

    int* tab;
    tab = NULL;

    int lignes;
    printf("combien de lignes voullez vous ?\n");
    scanf("%d", &lignes);
    tab = malloc(lignes *sizeof(int));
    for (int i = 0; i < lignes; i++)
    {
        tab[i]=rand() % 101;
        printf("i=%d valeur=%d",i,tab[i]);
        printf("\n");
    }
    free(tab);
    tab=NULL;

    
    return 0;
}