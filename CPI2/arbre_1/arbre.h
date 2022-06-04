#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud noeud;

struct noeud
{
    int valeur;
    noeud* fGauche;
    noeud* fDroite;
};

typedef noeud* arbre;

arbre creeArbre(int valeur, arbre filsGauche, arbre filsDroite);

void infixe(arbre a);

int hauteur(arbre a);

arbre miroir(arbre a);

int appartient(int elt, arbre a);

#endif