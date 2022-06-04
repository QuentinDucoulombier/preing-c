#include <stdio.h>

typedef enum  {
    VIDE,
    CROIX,
    ROND
 } valeurCase;

int aGagner(valeurCase tableau[100][100], valeurCase symbole) {
    int vertical = 0;
    int horizontal = 0;
    int i = 0;
    //TODO : horizontal, diagonal
    while (vertical ==0 || i<=2) 
    {
        vertical = (tableau[i][0] == symbole) && (tableau[i][1] == symbole) && (tableau[i][2] == symbole);
        i++;
    }
    while (horizontal ==0 || i<=2) 
    {
        horizontal = (tableau[0][i] == symbole) && (tableau[1][i] == symbole) && (tableau[2][i] == symbole);
        i++;
    }
}

void placerCase(valeurCase tableau[100][100], valeurCase symbole) {
    int x;
    int y;
    scanf("%d, &x");
    scanf("%d, &y");
    if (x <= 3 && x >= 1 && y <= 3 && x >= 1)
    {
        tableau[x][y] =  symbole;
    }
    else
    {
        placerCase(tableau, symbole);
    }
    
}

void jouer(valeurCase tableau[100][100]) {
    int nbrTour = 0;
    int aGagne = 0;
    valeurCase joueur;
    while ( aGagner(tableau) || nbrTour == 9)
    {
        afficheTableau (tableau);
        if ( joueur == CROIX) 
        {
            joueur = ROND;
        }
        else
        {
            joueur = CROIX;
        }
        placerCase(tableau, joueur);
        aGagne = aGagner(tableau, joueur);
        nbrTour++;
        
    }
    if (!aGagne){
        printf("Personne n'à gagner\n");

    }else
    {
        printf("Le symbole gagnant est "); //TODO: afficher le symbole du joueur gagant
    }
    


}


int main(int argc, char const *argv[]) {
    valeurCase tab[3][3] = {
        {VIDE, VIDE, VIDE},
        {VIDE, VIDE, VIDE},
        {VIDE, VIDE, VIDE}
    };
    joueur(tableau);

    return 0;


}