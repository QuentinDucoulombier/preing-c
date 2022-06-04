#include<stdio.h>

int main() {
    int a;
    int * pa;
    pa = &a;
    *pa =30;

    printf ("a = %d\n",a);
    printf("=> %p\n", pa);
    printf("la valeur demandé est %d\n", *pa);
    return 0;

}