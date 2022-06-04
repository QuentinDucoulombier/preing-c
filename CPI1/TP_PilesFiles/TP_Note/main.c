#include "note.h"
#include <stdio.h>
#include <stdlib.h>



int main(){

/*
    int max;
    char* nom;
    char* prenom;
    int note;
    printf("--------------Saisie des notes------------\n");
    printf("Veuillez saisir le nomnbre de copies a saisir\n");
    scanf("%d", &max);
    for (int i = 0; i < max; i++)
    {
        
        printf("Veuillez saisir le nom de l'eleve :\n");
        scanf("%s", nom);
        printf("%s\n", nom);
        
        
        printf("Veuillez saisir le prenom de l'eleve :\n");
        scanf("%s", prenom);
        
        printf("Veuillez saisir la note de l'eleve :\n");
        scanf("%d", &note);
    }
    char* nom;
    printf("Veuillez saisir le nom de l'eleve :\n");
    scanf("%s", nom);
    printf("Le nom est : %s\n", nom);
    printf("\n\n")

*/
    Pile pCopie = NULL;
    File MatiereDeLaCopie = NULL;
    int matiere;
    printf("--------------Quelle matiere ?-----------\n");
    printf ("0 - algebre\n");
    printf ("1 - analyse\n");
    printf ("2 - physique\n");
    printf ("3 - info\n\n");

    printf ("Quel est votre choix : ");
    scanf("%d", &matiere);
    SwitchMatiere(matiere);

    printf("\n");
    int max;
    printf("--------------Saisie des notes------------\n\n\n");
    printf("Veuillez saisir le nomnbre de copies a saisir\n\n");
    scanf("%d", &max);
    printf("Vous avez %d copie a saisir\n", max);
    char nom[30] = {0};
    char prenom[30] = {0};
    float note;
    for (int i = 0; i < max; i++)
    {
        printf("---------ELEVE %d--------\n", i);
        printf("Veuillez saisir le nom de l'eleve :\n");
        scanf("%s", nom);
        printf("Veuillez saisir le prenom de l'eleve :\n");
        scanf("%s", prenom);
        printf("Veuillez saisir la note de l'eleve :\n");
        scanf("%f", &note);
        Empiler(&pCopie, nom, prenom, note);
        printf("\n\n");
        
        
    }
    Enfiler(&MatiereDeLaCopie, pCopie, matiere);
    AfficherFile(MatiereDeLaCopie, pCopie);
    //Vider(&pCopie);

/*
    Pile pCopie1 = NULL;
    Pile pCopie2 = NULL;
    File MatiereDeLaCopie = NULL;

    Empiler(&pCopie1, "Ducoulombier", "Quentin", 13.52);
    Enfiler(&MatiereDeLaCopie, pCopie1, analyse);

    
    Empiler(&pCopie2, "Vignal", "Pierrick", 10);
    Enfiler(&MatiereDeLaCopie, pCopie2, analyse);
    
    Enfiler(&MatiereDeLaCopie, pCopie1, algebre);
    
    
    AfficherFile(MatiereDeLaCopie, pCopie1);
*/

    return 0;
}