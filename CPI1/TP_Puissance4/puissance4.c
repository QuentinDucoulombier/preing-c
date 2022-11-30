#include "puissance4.h"
#include<stdio.h>
#include<stdlib.h>

/*Rajout a la mano*/
#include <time.h>

/* toutes mes signatures/prototypes de fonctions/méthodes + leur corps */

int** Allouer(int lignes, int colonnes){
    int** tab;
    tab=malloc(lignes *sizeof(int*));
    for (int i = 0; i < lignes; i++)
    {
        tab[i]= malloc(colonnes * sizeof(int));
    }
    return tab;

}




void Initialisation(int** tab, int lignes, int colonnes){


    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            tab[i][j]=-1;
        }
        
    }


//test a effacer
/*
    for (int i = 1; i < 4; i++)
    {
        tab[lignes-i][3]=2;
    }



   for (int j = 1; j < 4; j++)
   {
       tab[lignes-1][colonnes-j]=2;
   }



    tab[3][2]=1;
    tab[4][1]=1;
    tab[5][0]=1;
*/
}



void Affichage (int** tab, int lignes, int colonnes){
    for (int i = 0; i < lignes; i++)
    {
        printf("| ");
        for (int j = 0; j < colonnes; j++)
        {
            if (tab[i][j]==-1)
            printf("  | ");
            if (tab[i][j]==1)
            printf("X | ");
            if (tab[i][j]==2)
            printf("O | ");
        }
        printf("\n");
    }
    
}



int ChoixJoueur(void){
    int joueur;


    do
    {
        printf("Quel joueur commence ? (1 ou 2): \n");
        scanf("%d", &joueur);
    } while ((joueur < 1) || (joueur > 2));

    if (joueur == 1)
    {
        printf("Le joueur 1 commence !, son symbole sera X");
    }
    else
    {
        printf("Le joueur 2 commence !, son symbole sera O");
    }
    printf("\n\n");


    printf("-------------------------------------\n");
    printf("-------------Debut du jeu------------\n");
    printf("-------------------------------------\n\n");

    return(joueur);
}



int AGagne(int** tab, int lignes, int colonnes){
    
    int gagnant = -1;


    /*Lignes*/

    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes-3; j++)
        {
            if ((tab[i][j] != -1) && (tab[i][j] == tab[i][j+1]) && (tab[i][j] == tab[i][j+2]) && (tab[i][j] == tab[i][j+3]))
            {
                gagnant = tab[i][j];
            }
        }       
    }


    /*Colonnes*/
    for (int j = 0; j < colonnes; j++)
    {
        for (int i = 0; i < lignes-3; i++)
        {
            if ((tab[i][j] != -1) && (tab[i][j] == tab[i+1][j]) && (tab[i][j] == tab[i+2][j]) && (tab[i][j] == tab[i+3][j]))
            {
                gagnant = tab[i][j];
            }
        } 
    }

    /*Diagonale 1*/

    for (int i = 0; i < lignes-3; i++)
    {
        for (int j = 0; j < colonnes-3; j++)
        {
            if ((tab[i][j] != -1) && (tab[i][j] == tab[i+1][j+1]) && (tab[i][j] == tab[i+2][j+2]) && (tab[i][j] == tab[i+3][j+3]))
            {
                gagnant = tab[i][j];
            }
        }

    }

    /*Diagonale 2*/

    for (int i = 0; i < lignes-3; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            if ((tab[i][j] != -1) && (tab[i][j] == tab[i+1][j-1]) && (tab[i][j] == tab[i+2][j-2]) && (tab[i][j] == tab[i+3][j-3]))
            {
                gagnant = tab[i][j];
            }
        }

    }
    
    if ((gagnant == 1) || (gagnant == 2))
    {
        printf("le gagnant est le joueur %d\n", gagnant);
    }


    return(gagnant);

}





void TourDeJeu(int** tab, int lignes, int colonnes, int gagnant, int joueur){

    int max=lignes*colonnes;
    printf("max %d\n", max);
    int compteur = 0;
    
    

    while ((gagnant == -1) || (compteur == max))
    {
        AGagne(tab, lignes, colonnes);
        printf("---------------------------------------\n\n");
        if (joueur == 1)
        {
            printf("C'est au tour du joueur 2\n\n");
            Jouer(tab, lignes, colonnes, 2);
            gagnant = AGagne(tab, lignes, colonnes);
            printf("---------------------------------------\n\n");
            printf("C'est au tour du joueur %d\n\n", joueur);
            Jouer(tab, lignes, colonnes, joueur);
            gagnant = AGagne(tab, lignes, colonnes);
            
        }
        else
        {
            printf("C'est au tour du joueur 1\n\n");
            Jouer(tab, lignes, colonnes, 1);
            gagnant = AGagne(tab, lignes, colonnes);
            printf("---------------------------------------\n\n");
            printf("C'est au tour du joueur %d\n\n", joueur);
            Jouer(tab, lignes, colonnes, joueur);
            gagnant = AGagne(tab, lignes, colonnes);
        }
        compteur+=2;
        printf("compteur = %d\n", compteur);

    }

    if(compteur == max)
    {
        printf("il y a match nul\n");
    }
    

}


int Jouer(int** plateau,int lignes,int colonnes, int joueur){
    int ligneLocal;
    int colonneLocal;
    int chiffreRetourner = 0;
   
    Affichage(plateau, lignes, colonnes);
    printf("\n");
    
    printf("Veuillez saisir la colonne : ");
    scanf("%d",&colonneLocal);
    while ((colonneLocal < 0) || (colonneLocal > colonnes-1)){
        printf("Colonne invalide : ");
        scanf("%d",&colonneLocal);
    }
    printf("\n");

    ligneLocal = lignes-1;

    if (plateau[0][colonneLocal] != -1){
        printf ("Cette colonne est pleine (tu passes donc ton tour !)\n");
        chiffreRetourner = 0;

    }
    else
    {
        while ((plateau[ligneLocal][colonneLocal] == 1) || (plateau[ligneLocal][colonneLocal] == 2))
        {
            if (ligneLocal >= 0)
            {
                ligneLocal = ligneLocal-1;
            }
        }
        plateau[ligneLocal][colonneLocal]= joueur;
        chiffreRetourner = 1;
    
    }
    
    return(chiffreRetourner);
}




void Libere (int** tab, int lignes, int colonnes){

    for (int i = 0; i < lignes; i++)
    {
        free(tab[i]);
        
    }
    free(tab);
    tab=NULL;

}

