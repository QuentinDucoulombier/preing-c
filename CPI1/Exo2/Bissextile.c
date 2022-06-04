#include <stdio.h>

int main() {

    int bool;
    int annee;
    int mois;
    int jour;
    int bon;


//année
    printf("Veuillez saisir une annee\n");
    scanf("%d", &annee);


    if (((annee%4)==0) && (((annee%100)!=0) || ((annee%40)==0))) {
        bool=1;
    }
    

//mois
    do
    {
        printf("Veuillez saisir un mois\n");
        scanf("%d", &mois);
    } while ((mois<1) || (mois>12));
    
    if ((bool==1) && (mois==2)){
        bool=2;
    }


//jour et verification de la saisie
    do
    {
        printf("Veuillez saisir un jour\n");
        scanf("%d", &jour);
    } while ((jour<1) || (jour>31));
    
    if ((bool==2) && (jour>29)){
        printf("Il y a une erreur de saisie\n");
        bon=0;
    
    }
    
    if ((bool!=2) && (mois==2) && (jour>28)){
        printf("Il y a une erreur de saisie\n");
        bon=0;
    }
    if (((mois==4) || (mois==6) || (mois==9) || (mois==11)) && (jour>30)){
        printf("Il y a une erreur de saisie\n");
        bon=0;
    }

    if (bon!=0){
        printf("Il n'y pas d'erreur de saisie\n");
    }
    
    
    
}