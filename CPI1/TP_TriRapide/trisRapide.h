#ifndef __trisRapide_H_
#define __trisRapide_H_

/*Ensemble de fonctions pour le tri Rapide*/
void TriRapide(int* tab, int debut, int fin);
int Partitionner(int* tab, int debut, int fin); 


/*Ensemble de fonctions pour le tri Fusion*/
void TriFusion(int* tab, int debut, int fin);
void Fusionner(int* tab, int debut, int milieu, int fin);

#endif