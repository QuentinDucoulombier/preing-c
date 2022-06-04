#include <stdio.h>
#include "arbre.h"

int main()
{
    arbre tree = creeArbre(15, creeArbre(12, NULL, creeArbre(5, NULL, NULL)), creeArbre(9, creeArbre(56, NULL, NULL), creeArbre(8, NULL, NULL)));
    infixe(tree);
    printf("la hauteur est de %d\n", hauteur(tree));
    infixe(miroir(tree));
    printf("%d \n", appartient(5, tree));
    return 0;
}

