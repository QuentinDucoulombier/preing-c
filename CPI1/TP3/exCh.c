/**
 * @file exCh.c
 * @brief Mon programme exemple de saisie de chaînes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @fn int main (int argc, char** argv)
 * @author peio loubière <peio.loubiere@cuy.fr>
 * @version 0.1
 * @date 1 novembre 2020
 *
 * @brief Fonction principale
 *
 *
 * @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 * @remarks
 */
int main(int argc, char** argv) {
  // gère la variable chaine pour fgets
  char chaine1[12]; 
  
  // gère la variable pour getline
  char chaine2[12]; 
  size_t taille;  // taille allouée
  char* ch = chaine2; // pointeur

  printf("Veuillez saisir une chaîne \n");
  fgets(chaine1, sizeof chaine1, stdin);
  printf("Vous avez saisi : %s \n", chaine1);

  printf("Veuillez saisir une autre chaîne \n");
  getline(&ch, &taille, stdin);
  printf("Vous avez saisi : %s\n", chaine2);
  printf("Vous avez saisi : %s\n", ch);

  return EXIT_SUCCESS;
}