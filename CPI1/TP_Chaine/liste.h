#ifndef LISTES_H
#define LISTES_H

typedef struct maillon{
    int donnee;
    struct maillon* suivant;

}maillon;

typedef maillon* teteListe;

/* Procedure qui Ajoute des valeur dans la liste */
void AjouterDebut(teteListe* l, int valeur);
void AjouterFin(teteListe* l, int valeur);
void ajouterFin(teteListe* l, int valeur);
void ajouterPos(teteListe* l, int valeur, int pos);

/* Procedure qui supprime des valeurs dans la liste */
int SupprimerDebut(teteListe* l);
int SupprimerFin(teteListe* l);
int SupprimerPosition(teteListe* l, int position);

/* Procedure que l'on doit faire en gros */
int RechercherPos(teteListe* l, int valeurRecherche);
int rechercheOccu(teteListe l, int valeur);
void Concatener(teteListe* l1, teteListe* l2);

void Affichage(teteListe l);
int Taille(teteListe);


#endif