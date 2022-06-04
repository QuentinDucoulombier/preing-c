#include<stdio.h>
/*
    procedure echange
*/

void Echange(int * x, int * y) {
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

/*
    Programme principal
*/

int main (){
    int a = 5;
    int b = 7;

    printf("Avant l'echange la valeur de a est %d et b =%d\n", a, b);
    Echange(&a,&b);
    printf("Apres l'echange la valeur de a est %d et b est %d\n", a ,b);
    
    return 0;


}