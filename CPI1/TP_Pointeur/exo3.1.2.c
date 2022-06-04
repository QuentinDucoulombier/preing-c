#include<stdio.h>
#include<stdlib.h>

int main (){


    char* tab;

    int max = 11;
    tab = (char*) malloc(max *sizeof(char));
    
    printf("Veullez saisir une chaine\n");
    scanf("%s", tab);
    printf("Ma chaine : %s \n", tab);

    free(tab);
    tab=NULL;

    
    return 0;
}