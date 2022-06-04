#include<stdio.h>

//int addition (int * x, int * y) {
  //  return *x + *y;

void swap(int * x, int * y){
    int c = *x;
    *x = *y;
    *y = c;
}

int main () {

    int a = 3;
    int b = 2;


    printf("a = %d | b = %d\n",a, b);

    swap(&a,&b);
    printf("Swap...\n");

    printf("a = %d | b = %d\n",a ,b);
    /*
    int resultat = addition(&a, &b);

    printf("a + b = %d\n", resultat);
    */
    return 0;
}