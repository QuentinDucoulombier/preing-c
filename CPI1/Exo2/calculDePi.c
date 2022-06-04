#include <stdio.h>
#include <math.h>

int main() {
    
    int n = (-1);

    float pi = 0;
    
    for (int i = 1; i < 300; i+=2)
    {
        n=n*(-1);
        pi=pi+((n)/(i));
        printf("%f\n", pi);
 
    }
    
    pi=4*(pi);
    printf("%f\n", pi);
    return 0;
}