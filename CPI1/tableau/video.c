#include <stdio.h>

int main(){
    
    int tab[3];
    
    for (int i = 0; i < 100; i++)
    {
        tab[i]=i + 1;
    }
    


    for (int i = 0; i < 100; i++)
    {
        printf("Mon nombre tab[%d] vaut %d\n", i, tab[i]);
    }


    return 0;
}