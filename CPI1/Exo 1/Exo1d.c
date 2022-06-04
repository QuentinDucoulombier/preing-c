#include <stdio.h>

int main() {
    int age;
    char prenom[50];
    char nom[50];

    printf("Entrer votre nom\n");
    scanf("%s", nom);

    printf("Entrer votre prenom\n");
    scanf("%s", prenom);

    do
    {
        printf("Entrer votre age\n");
        scanf ("%d", &age);
    } while ((age<0) || (age>128));
    
    printf("Voici ce que vous avez entré:\n");
    printf("nom: %s\n", nom);
    printf("Prenom: %s\n", prenom);
    printf("Age: %d\n", age);
    return 0;
}