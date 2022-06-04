/**
 * @file 2-exempleMenu.c
 * @author Florent Devin <florent.devin@eisti.fr>
 * @version 0.1
 * @date 04 novembre 2019 - 20:35:29
 * @brief Programme d'exemple
 */

/**
 * @page exemple_desc.c
 * @section un Introduction
 * Ce programme est la pour faire une demonstration sur l'utilisation
 * des differents concepts vus en cours. En plus de cela, il y a
 * aussi des exemples d'utilisation de doxygen...
 *
 * @section oups Objectif du programme
 * Le programme affiche un menu, demande le choix a l'utilisateur, et
 * affiche le choix de celui-ci. C'est un programme tres simple.

 * @section deux Algorithme
 * Voici une facon de presenter un algorithme. L'algorithme ici
 * presente est celui qui est traduit par la suite.
 *
@verbatim
ecrire ("1 - coucou")
ecrire ("2 - salut")
ecrire ("3 - bonjour")
ecrire ("4 - adiou")
ecrire ("Quel est votre choix")
lire(valeurChoix)
choix valeurChoix de
  1 :
    ecrire ("Coucou")
  2 :
    ecrire ("Salut")
  3 :
    ecrire ("Bonjour")
  4 :
    ecrire ("Adiou");
fin choix
@endverbatim
 */
/* Inclusion des entetes de librairie */
#include <stdio.h>
#include <stdlib.h>


/**
 * @fn int menu(void)
 * @author Florent Devin <fd@eisti.eu>
 * @version 0.1
 * @date 04 novembre 2019 - 20:37:45 2019
 *
 * @brief Affiche le menu et retourne le choix de l'utilisateur
 *
 *
 * @return le choix de l'utilisateur
 */

int menu(void)
{
     int int_retour; /* Valeur de retour */
     int int_choix;  /* Choix de l'utilisateur */

     /* Affichage du menu */
     printf ("1 - coucou\n");
     printf ("2 - salut\n");
     printf ("3 - bonjour\n");
     printf ("4 - adiou\n\n");

     /* Demande du choix a l'utilisateur */
     printf ("Quel est votre choix : ");
     int_retour = scanf ("%d", &int_choix);

     /* Verification de l'entree */
     if (int_retour == 0) {
	  printf ("Probleme de saisie\n");
	  exit (EXIT_FAILURE);
     }
     return (int_choix);
}



/**
 * @fn int main (void)
 * @author Florent Devin <florent.devin@eisti.fr>
 * @version 0.1
 * @date 04 novembre 2019 - 20:46:23 - 397ms
 *
 * @brief Fonction principale
 *
 *
 * @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 * @remarks
 */

int main (void)
{
     int int_choix;  /* Choix de l'utilisateur */

     int_choix = menu();
     /* Affichage du message en fonction du choix */
     switch (int_choix) {
     case 1 : 	printf ("Coucou\n");
	  break;
     case 2 : 	printf ("Salut\n");
	  break;
     case 3 : 	printf ("Bonjour\n");
	  break;
     case 4 : 	printf ("Adiou\n");
	  break;
	  /* Dans le cas par defaut, on ne fait rien */
     default :
	  break;
     }

     /* Fin du programme, Il se termine normalement, et donc retourne 0 */
     return (EXIT_SUCCESS);
}
