#include <stdio.h>
#include <stdlib.h>
int main(){
int* p_i1;
int** p_i2;
int*** p_i3;
int a;
int b;
int c;
/* etape n°1 */
a=5;
b=12;
c=6;
printf("a= %d b=%d c=%d \n",a,b,c);
/* etape n°2 */
p_i1=&a;
b=a;
printf("a= %d b=%d c=%d \n",a,b,c);
/* etape n°3 */
p_i2=&p_i1;
c=**p_i2;
printf("a= %d b=%d c=%d \n",a,b,c);
/* etape n°4 */
p_i3=&p_i2;
a=56;
printf("a= %d b=%d c=%d \n",a,b,c);
/* etape n°5 */
***p_i3=45;
b=24;
c=12;
printf("a= %d b=%d c=%d \n",a,b,c);
return 0;
}