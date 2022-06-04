#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int trait;
    int point;
} Maya;

Maya creerMaya(int a,int b)
{
    Maya res;
    res.trait = a;
    res.point =b;
    return res;

};

Maya plus(Maya m1, Maya m2){
    int a,b;
    a=m1.trait + m2.trait +(m1.point + m2.point)/5;
    b=(m1.point + m2.point)%5;
    return creerMaya(a,b);
}
Maya moins(Maya m1, Maya m2);
    int a,b;
    a=m1.trait - m2.trait;
    b=(m1.point + m2.point);
    if (a==0) return creerMaya(0,b);
    else if (b<0) return creerMaya(a-1; b+5);
    else return creerMaya(a,b);
    return creerMaya(a,b);
}

void afficherMaya(Maya c,d){
    printf("Le nombre de traits est %d \n", c.trait );
    printf("Le nombre de points est %d\n", c.point);

}

int main() {
    int 
    Maya a,b,c,d;
    a=creerMaya(10,2);
    b=creerMaya(2,10);
    c=plus(a,b);
    d=moins(a,b);
    afficherMaya(c);
    
   return(0);
}