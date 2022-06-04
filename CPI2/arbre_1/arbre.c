#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"


arbre creeArbre(int valeur, arbre filsGauche, arbre filsDroite)
{
    arbre a = NULL;
    a = malloc(sizeof(noeud));
    a -> valeur = valeur;
    a -> fGauche = filsGauche;
    a -> fDroite = filsDroite;
    return a;
}

void infixe(arbre a)
{
    if (a != NULL)
    {
        infixe(a -> fGauche);
        printf("%d\n", a->valeur);
        infixe(a -> fDroite);

    }
}

int hauteur(arbre a)
{
    if (a == NULL)
    {
        return 1;
    }
    else
    {
        return 1 + hauteur(a -> fGauche) + hauteur(a -> fDroite);
    }
}

arbre miroir(arbre a)
{
    if (a != NULL)
    {
        return creeArbre(a -> valeur, miroir(a -> fDroite), miroir(a -> fGauche));
    }
    else
    {
        return NULL;
    }
}

int appartient(int elt, arbre a)
{
    if ((a != NULL) || (a -> valeur == elt))
    {
        return (a -> valeur == elt);
    }
    else
    {
        if (a -> valeur == elt)
        {
            return (a -> valeur == elt);
        }
        else
        {
            return ((appartient(elt, a -> fGauche) || (appartient(elt, a -> fDroite));
        }
    }


}