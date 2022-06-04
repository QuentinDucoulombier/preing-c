#include <stdio.h>
#define True 1
#define False 0

typedef int entier;
typedef int bool;

int main() {
    int a = 10;

    printf("a vaut %d\n", a);

    bool monBooleen = True;
    if (monBooleen)
        printf("Salut !\n");
    return 0;

}