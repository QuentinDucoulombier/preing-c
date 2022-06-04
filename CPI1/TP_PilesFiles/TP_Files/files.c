#include <stdio.h>
#include <stdlib.h>
#include "files.h"


void Enfiler(File* f, char* valeur){

    Personne* nouveau;
    
    nouveau = malloc(sizeof(nouveau));

    if (nouveau != NULL)
    {
        nouveau -> precedent = NULL;
        nouveau -> nom = valeur;
    }
    

    if (*f == NULL)
    {
        *f = nouveau;
    }
    else
    {
        Personne* temp;
        temp = *f;
        while (temp -> precedent != NULL)
        {
            temp = temp -> precedent;
        }
        temp -> precedent = nouveau;
    }
}


void Afficher(File f){
    File temp = NULL;

    if (f != NULL)
    {
        temp = f;
        while (temp != NULL)
        {
            printf("%s\n", temp ->nom);
            temp = temp -> precedent;
        }
        
    }
    else
    {
        printf("Il n'y a rien dans la file zebi\n");
    }

}

char* DefilerF(File *f){


    if (f  == NULL)
    {
        printf("erreur");
        exit(EXIT_FAILURE);
    }
    
    char* NomDefile;

    if (*f != NULL)
    {
        NomDefile = (*f) -> nom;
        Personne* temp = (*f) -> precedent;
        free(*f);
        *f=temp;

    }
    return NomDefile;
    
}

int CompterF (File f){

    int res = 0;
    File temp;

    if (f != NULL)
    {
        temp = f;

        while (temp != NULL)
        {
            res++;
            temp = temp -> precedent;
        }
        
    }
    return res;

}



File* Inverser(File* f){

    char* elt;

    if (*f == NULL)
    {
        return f;
    }
    else
    {
        elt = DefilerF(f);
        f = Inverser(f);
        Enfiler(f,elt);
        return f;
    }
}



/*
void Inverser(File *f){


    if (*f != NULL)
    {
        char* elt = DefilerF(f);
        Inverser(f);
        Enfiler(f, elt);

    }
}
*/


void Vider(File* f){

    char* elt;

    while (*f != NULL)
    {
        elt = DefilerF(f);
    
    }
    elt = NULL;
}
