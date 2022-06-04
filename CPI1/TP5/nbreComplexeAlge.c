#include <stdio.h>

typedef struct 
{
    float a;
    float b;
} ComlexeFormeAlgebrique;


typedef struct 
{
    float r;
    float theta;
} ComplexeFormeExponentielle;

int estImaginairePur(ComplexeFormeAlgebrique z){
    return ((z.a == 0) && (z.b !=0));

}

