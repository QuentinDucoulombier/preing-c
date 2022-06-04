#include<stdio.h>
#include<stdlib.h>
#include<time.h>



#define P 'P'
#define I 'I'

/*Menu pour choisir quel type de tableau choisir*/

int menu(void)
{
    int choix;  /* Choix de l'utilisateur */

    do
    {
        printf ("1 - Tableau 2D d'entier\n");
        printf ("2 - Chaine 2D de Caractere\n");
     
        printf ("Quel est votre choix : ");
        scanf ("%d", &choix);
        printf("\n");
    } while (((choix < 1) || (choix > 2)));

    return (choix);
    
}



/*Ensemble de fonction pour le Tableau 2D d'entier*/

int** Allouer2D(int lignes, int colonnes){
    int** tab;
    tab=malloc(lignes *sizeof(int*));
    for (int i = 0; i < lignes; i++)
    {
        tab[i]= malloc(colonnes * sizeof(int));
    }
    return tab;

}

void Affectation(int** tab, int lignes, int colonnes){

    srand(time(NULL));

    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            tab[i][j]=rand() % 101;
        }
        
    }
    

}
void Affichage (int** tab, int lignes, int colonnes){
    for (int i = 0; i < lignes; i++)
    {
        printf("|");
        for (int j = 0; j < colonnes; j++)
        {
            printf(" %d | ", tab[i][j]);
        }
        printf("\n");
    }
}

/*Ensemble de fonction pour le Tableau 2D de chaine de caracteres*/

char** Allouer2DChaine(int lignes, int colonnes){
    char**tab;
    tab = (char**) malloc(lignes * sizeof (char*));
    for (int i = 0; i < lignes; i++)
    {
        tab[i] = (char*) malloc(colonnes * sizeof(char));
    }
    return tab;


}

void AffectationChaine(char** tab, int lignes, int colonnes){

    for (int i = 0; i < lignes; i+=2)
    {
        for (int j = 0; j < colonnes; j++)
        {
            tab[i][j] = P;
        }
            
    }
    for (int i = 1; i < lignes; i+=2)
    {
        for (int j = 0; j < colonnes; i++)
        {
            tab[i][j] = I;
        }
        
    }
    

}

void AffichageChaine (char** tab, int lignes, int colonnes){
    for (int i = 0; i < lignes; i++)
    {
        printf("|");
        for (int j = 0; j < colonnes; j++)
        {
            printf(" %c | ", tab[i][j]);
        }
        printf("\n");
    }
}


int main (){

    int lignes = 3;
    int colonnes = 4;
    int **tabMain;
    char ** tabMainCh;
    int choix;

    choix = menu();
    switch (choix)
    {
    case 1:
        tabMain = Allouer2D(lignes, colonnes);
        Affectation(tabMain, lignes, colonnes);
        Affichage(tabMain, lignes, colonnes);

        for (int i = 0; i < lignes; i++)
        {
            free(tabMain[i]);
        
        }
        free(tabMain);
        tabMain=NULL;
        break;

    case 2:
        tabMainCh = Allouer2DChaine(lignes, colonnes);
        AffectationChaine(tabMainCh, lignes, colonnes);
        AffectationChaine(tabMainCh, lignes, colonnes);
    
        for (int i = 0; i < lignes; i++)
        {
            free(tabMainCh[i]);
        
        }
        free(tabMainCh);
        tabMainCh = NULL;
        break;

    default:
        break;
    }


    return 0;
}