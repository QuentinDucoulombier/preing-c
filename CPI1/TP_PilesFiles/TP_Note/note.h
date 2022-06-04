#ifndef NOTE_H
#define NOTE_H

/* Creation de la Pile Copie */

typedef struct Copie
{
    char* nom;
    char* prenom;
    float note;
    struct Copie* suivant;

}Copie;

typedef Copie* Pile;


enum matiere{

    algebre, analyse, physique, info
};

/* Creation de la File avec tt les CopiePar matiere en gros le prof a plusieurs Pile de copie chacune par matiere differente, ces PiledeCopie de matiere sont donc sous forme de File */

typedef struct CopieParMatiere
{
    int matiere;
    Pile copie;
    struct CopieParMatiere* precedent;
}CopieParMatiere;

typedef CopieParMatiere* File;


void Empiler(Pile* p, char* nom, char* prenom, float note);
void AfficherPile(Pile p);
void Enfiler(File* f, Pile copieMain, int matiere);
void AfficherFile(File f, Pile copie);
void SwitchMatiere(int nbrematiere);
void Vider(Pile* p);


#endif