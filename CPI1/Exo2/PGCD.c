#include <stdio.h>

int PGCD(int a, int b) {
    int r;
    while (b>0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}


int main(){
    int c;
    c=PGCD(20,30);
    printf("%d\n", c);

}