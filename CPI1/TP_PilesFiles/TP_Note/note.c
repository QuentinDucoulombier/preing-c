#include "note.h"
#include <stdio.h>
#include <stdlib.h>


void Empiler(Pile* p, char* nom, char* prenom, float note){

    Copie* nouveau = malloc(sizeof(*nouveau));

    if (nouveau != NULL)
    {
        nouveau -> nom = nom;
        nouveau -> prenom = prenom;
        nouveau -> note = note;
        nouveau -> suivant = *p;
        *p = nouveau;
    }
    
}


void Enfiler(File* f, Pile copieMain, int matiere){

    CopieParMatiere* nouveau;

    nouveau = malloc(sizeof(nouveau));

    if (nouveau != NULL)
    {
        nouveau -> precedent = NULL;
        nouveau -> copie = copieMain;
        nouveau -> matiere = matiere;
    }
    
    if (*f == NULL)
    {
        *f = nouveau;
    }
    else
    {
        CopieParMatiere* temp;
        temp = *f;
        while (temp -> precedent != NULL)
        {
            temp = temp -> precedent;
        }
        temp -> precedent = nouveau;    
    }
}


void AfficherFile(File f, Pile copie){

    File temp = NULL;

    if (f != NULL)
    {
        temp = f;
        while (temp != NULL)
        {
            SwitchMatiere(temp -> matiere);
            
            AfficherPile(copie);

            printf("\n");
            temp = temp -> precedent;
        }
        
    }
    else
    {
        printf("Il n'y a rien dans la file zebi\n");
    }
}




void SwitchMatiere(int nbrematiere){

    switch (nbrematiere)
    {
    case 0:
        printf("La matiere est l'algebre \n");
        break;

    case 1:
        printf("La matiere est l'analyse \n");
        break;
            
    case 2:
        printf("La matiere est la physique \n");
        break;

    case 3:
        printf("La matiere est l'info \n");
        break;

    default:
        printf("Matiere inconnue\n");
                
    }

}



void AfficherPile(Pile p){

    if (p != NULL)
    {
        Pile temp = p;

        while (temp != NULL)
        {
            printf("Nom : %s\n", temp->nom);
            printf("Prenom : %s\n", temp->prenom);
            printf("Note : %f\n", temp->note);
            
            
            temp = temp -> suivant;
            
        }   
    }
}

//TODO faire la fonction Depiler
/*
Pile Depiler(Pile* p){

    if (p == NULL)
    {
        printf("Erreur la pile est vide !!!!\n");
        exit(EXIT_FAILURE);
    }
    
    int noteDepile = 0;
    char* nomDepile;
    char* prenomDepile;

    Copie* elementDepile = *p;
    Pile temp = NULL;


    if (p != NULL && *p != NULL)
    {
        noteDepile = elementDepile -> note;
        nomDepile = elementDepile -> nom;
        prenomDepile = elementDepile -> prenom;
        *p = elementDepile -> suivant;
        free(elementDepile);
    }
    
    return noteDepile;
}





void Vider(Pile* p){

    while(*p != NULL)
    {
        int elt = Depiler(p);
        elt = 0;
    }
    


}
*/