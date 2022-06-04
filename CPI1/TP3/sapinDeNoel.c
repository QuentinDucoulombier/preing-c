#include<stdio.h>

int main() {
    int taille;
    int i;
    int j;
    int espace;
    int a;
    int nb;

    printf("Quel est la taille du sapin? \n");
    scanf("%d", &taille);
    

    for ( j = 1; j <= (taille*2)-1; j = j+2)
    {
        nb=1;
        espace=taille-j+(taille-2);
        while (espace>0)
        {
            printf(" ");
            espace=espace-2;
        }
        while (nb<=j)
        {
            printf("*");
            nb=nb+1;
        }
        
        printf(" \n");
        
        
    }
        
    for (i=1; i<=2; i++){
        a=1; 
        while (a<(taille)){
            printf(" ");
            a=a+1;
        }
        printf("@ \n");
    }

    return 0;
}