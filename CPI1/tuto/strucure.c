#include <stdio.h>
#include <string.h>

typedef struct {
    char titre[100];
    char auteur[100];
    int annee;

} Livre;





void afficherLivre(Livre livre) {
    printf("Titre : %s\n", livre.titre);
    printf("Auteur : %s\n", livre.auteur);
    printf("Année : %d\n", livre.annee);
    
}

int main(){
    Livre livre1;
    livre1.annee = 1997;
    strcpy(livre1.titre, "Harry Potter");
    strcpy(livre1.auteur, "JK Rowling");

    Livre livre2;
    livre2.annee = 1943;
    strcpy(livre2.titre, "Le Petit Prince");
    strcpy(livre2.auteur, "Antoine de Saint Exupéry");

    afficherLivre(livre1);
    afficherLivre(livre2);
    return 0;
}