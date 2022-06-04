#include<stdio.h>

void amstrong(){


    int nombre;

    printf("saisir un nombre\n");
    scanf("%d", &nombre);

    int sauvegarde = nombre;
    int somme = 0;
    while (sauvegarde > 0)
    {
        int chiffre = sauvegarde % 10;
        somme = somme + chiffre * chiffre * chiffre;
        sauvegarde = sauvegarde /10;

    }
    
    if (somme == nombre)
    {
        printf("%d est un nombre d'Amstrong\n", nombre);
    }

    else
    {
        printf("%d n'est pas un nombre d'Amstrong\n", nombre);
    }


}

int main() {
    amstrong();
}