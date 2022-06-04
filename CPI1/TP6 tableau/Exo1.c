#include <stdio.h> // Fonctions getchar, printf()
#include <stdlib.h> // Fonctions system()
#include <string.h>
#include <time.h>
#define OK 1

//void afficherTableau(char tab){
        
//  for (int i = 0; i < 12; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {   
//            printf("%c", tab[i][j]);
//        }
//    printf("\n");    
//    }
int creCombChiffre (int comb){
    scrand( time( NULL ) );
    comb[4];
    for (int i = 0; i < 4; i++)
    {
        comb[i] = rand() % 6;
    }
    return comb;

}




int main(){
    int combSecretChiffre[4]; 

    char tab[12][8]= {
    
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
        {42,42,42,42,46,46,46,46},
    };



    combSecretChiffre=creCombChiffre(combSecretChiffre);
    for (int i = 0; i < 4; i++)
    {
        print("%d\n", combSecretChiffre[i]);
    }
    


    //afficherTableau(tab[][]);
    //for (int i = 0; i < 12; i++)
    //{
    //    for (int j = 0; j < 8; j++)
    //    {   
    //        printf("%c", tab[i][j]);
    //    }
    //printf("\n");    
    //}

    return 0;
}



