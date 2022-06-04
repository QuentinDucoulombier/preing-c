#include <stdio.h>
#include "files.h"


int main(){



    /*  Initialisation des valeur a Null    */
    File queue = NULL;

    Enfiler(&queue, "Harry");
    Enfiler(&queue, "Dean");
    Enfiler(&queue, "Severus");
    Enfiler(&queue, "Neville");

    /*  Question 1  */
    printf("\n");
    printf("------Question 1------\n");
    printf("%s : J'AI ACHETE MA POTION \n", DefilerF(&queue));

    /*  Question 2  */
    printf("\n");
    printf("------Question 2-------\n");
    char* perso2 = DefilerF(&queue);
    printf("%s : J'ai \n", perso2);
    printf("%s : acheté \n", perso2);
    printf("%s : ma \n", perso2);
    printf("%s : ... \n", perso2);
    printf("%s : potion \n", perso2);


    /*  Question 3  */
    printf("\n");
    printf("------Question 3-------\n");
    Enfiler(&queue, perso2);
    Afficher(queue);    

    /*  Question 4  */
    printf("\n");
    printf("------Question 4-------\n");
    printf("%s : j'ai achete ma potion \n", DefilerF(&queue));


    /*  Question 5  */
    printf("\n");
    printf("------Question 5-------\n");
    printf("%s : j'ai achete ma potion \n", DefilerF(&queue));

    /*  Question 6  */
    printf("\n");
    printf("------Question 6-------\n");
    Inverser(&queue);
    Afficher(queue);


    /*  Question 7  */
    printf("\n");
    printf("------Question 7-------\n");
    printf("%s : jaiachetemapotion \n", DefilerF(&queue));

    /*  Question 8  */
    printf("\n");
    printf("------Question 7-------\n");
    int nbre = CompterF(queue);
    printf("Il y a %d dans la queue\n", nbre);

    /*  Question 9  */
    printf("\n");
    printf("------Question 9-------\n");
    Vider(&queue);
    Afficher(queue);

    
/* test    
    Afficher(queue);
    Inverser(&queue);
    printf("\n");
    DefilerF(&queue);
    Afficher(queue);
    printf("Compter = %d\n", CompterF(queue));
    Vider(&queue);
    printf("\n");
    Afficher(queue);
*/
    return 0;
}