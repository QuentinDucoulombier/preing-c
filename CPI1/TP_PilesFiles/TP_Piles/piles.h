#ifndef PILES_H
#define PILES_H

typedef struct ElementP
{
    int fleche;
    struct ElementP* suivant;
    
}ElementP;

typedef ElementP* Pile;

enum fleche{

    rouge, verte, bleue
};


void Empiler(Pile* p, int valeur);
void AfficherP(Pile p);
void AfficherFinal(Pile pLink, Pile pKilton, Pile pZelda);
int Depiler(Pile* p);
int Compter (Pile p);
Pile InverserP(Pile* p1, Pile* p2);
void DoublerP(Pile* p);
void Vider(Pile* p);


#endif