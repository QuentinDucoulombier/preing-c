#include<stdio.h>
#include<stdlib.h>
#include "fonctions.h"



int main (){


    int lignes = 11;
    int int_choix; 
    int* tab2;
    char* tab3;

    int_choix = menu();
    switch (int_choix) {
    case 1 : tab2=Initialisation(lignes);

        Affectation(tab2, lignes);

        Affichage (tab2, lignes);
        free(tab2);
        tab2=NULL;
	    break;
    case 2 : tab3=InitialisationChaine(lignes);
        AffichageEtAffectationChaine(tab3, lignes);
        free(tab3);
        tab3=NULL;
	    break;
	
    default :
	    break;
    }


    
    return 0;
}