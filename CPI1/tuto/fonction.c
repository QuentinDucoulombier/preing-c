#include <stdio.h>

void afficherBonjour(){
    printf("Bonjour\n");

}

int carre(int n) {
    return n * n;
}

int main (){

    int c;
   

    printf("Saisie ton nombre fdp\n");
    scanf("%d", &c);
    printf("carré de %d = %d\n", c, carre(c));

    return 0;
}