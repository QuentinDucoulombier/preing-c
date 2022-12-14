#include <stdio.h> // Fonctions getchar, printf()
#include <stdlib.h> // Fonctions system()
#include <string.h>
#include <time.h>
#define OK 1
int menu();
void jeu();
void regles();
// ---------------------------------------------------------------------------------------------------------------------------------------------
void initCode(char *codeSecret);
void analyserCombinaison(char *comb, char *rep, char *resultat);
int main ()
{
int continuer = 1, choix = 0;
while (continuer) // Boucle permettant de choisir ce que l'on veut faire dans le programme
{
    choix = menu();
    switch (choix)
    {
        case 1:
            jeu();
        break;
    // ----------------------------------
        case 2:
            regles();
        break;
    // ----------------------------------
        case 3:
            // Quitter
            continuer = 0;
        break;
    // ----------------------------------
        default:
            printf("Choix errone\n" );
    }
    // ----------------------------------
} // while
return 0;
}
// ------------------------------------------------------------------------------------------------------------------------------------------------
int menu()
{
         int choix = 0;
       
         system("cls" ); // Nettoyer la console
         printf("======== MENU ========\n\n" );
         printf("(1) : Jouer\n" );
         printf("(2) : Regles du jeu\n" );
         printf("(3) : Quitter\n\n" );
         printf("======================\n\n\n" );
         printf("Que voulez vous faire ?\n\n" );
         scanf("%d", &choix);
       
         return choix;
}
// ------------------------------------------------------------------------------------------------------------------------------------------
void regles()
{
    int choix = 0;
    system("cls" ); //Nettoyer la console
   
    //Affichage des règles du Mastermind
    printf("***********************\n" );
    printf("*REGLES DU MASTERMIND:*\n" );
    printf("***********************\n" );
   
    printf("\nLe programme choisit une combinaison de 4 pions de couleurs au hasard\n" );
    printf("parmi 6 couleurs disponibles.\n" );
    printf("Cette combinaison de pions peut contenir plusieurs fois la meme couleur.\n" );
    printf("L utilisateur essaie de la deviner en proposant au maximum dix combinaisons.\n" );
    printf("Pour chaque tentative le programme indique le nombre de couleurs bien placees\n" );
    printf("(a l aide de pion noir) et le nombre de couleurs mal placees\n" );
    printf("(a l aide de pion blanc). Si le nombre maximal d essais est atteint,\n" );
    printf("le programme indique au joueur qu il a perdu et donne la combinaison.\n\n" );
    printf("------------------------------------------------------------------------------\n\n" );
    printf("Entrez (0) pour revenir au menu principale\n" );
    scanf("%d", &choix);
   
    if (choix == 0)
    {
        menu();
    }
    else
    {
        regles(); // Sve@r, j'avoue ne pas avoir très bien compris ton commentaire pour cette ligne de code .. je ne vois pas le problème.
    }   
             
}
    void verifierCombi(char *comb, char *rep, char *resultat) //Permet de tester la combinaison entrée par le joueur pour voir si elle est sous la bonne forme.
    {
    char repMinuscule[4];
    int a;
    for(a=0;a<4;a++)
    {
     repMinuscule[a]=tolower(rep[a]); //Permet de transformer une majuscule en minuscule, ce qui permettra d'enter à la fois des minuscules et des majuscules comme combinaison
     }
   
    int controle[4] = {0,0,0,0};//sert à vérifier s'il n'y a pas un N à cette position
    int j=0;
    int i;
         for( i = 0;i<4;i++)//Sert à détecter les pions noirs
         {
             if (repMinuscule[i]==comb[i])
             {
              resultat[j] = 'N';
              j++;
              controle[i] = OK; 
             }         
         } 
       
         for(i = 0;i<4;i++)//Sert à détecter les pions blancs
         {
                 if(controle[i]!=OK)
                 {
                       int k;
                       for(k=0;k<4;k++)
                       {
                               if (repMinuscule[k]==comb[i] && controle[i]!=OK)
                               {
                                resultat[j]= 'B';
                                j++;
                                controle[i] = OK;
                               }
                                     
                       }
                 }
         }
    }
void initCode(char *codeSecret) //Fonction permettant de générer un code de 4 couleurs avec les initiales des 6 couleurs proposées.
{
int i;
srand (time(NULL));
/* initialiser le code secret avec un choix de 6 couleurs */
for (i = 0; i < 4 ; i++)
{
 switch (rand() % 6)
 {
  case 0: codeSecret[i] = 'r'; break;
  case 1: codeSecret[i] = 'b'; break;
  case 2: codeSecret[i] = 'v'; break;
  case 3: codeSecret[i] = 'j'; break;
  case 4: codeSecret[i] = 'o'; break;
  case 5: codeSecret[i] = 'm'; break;
 }
} 
}
// ------------------------------------------------------------------------------------------------------------------------------------------
    void jeu()
    {
        int essais=0,choix=0, ligne=9,continuer=1,verif=0,a; // "entrer" dans la boucle jeu
        char tab[10][8]={
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},//Sv@r, 42:*  46:.  j'initialise les valeurs de mon tableau avec ces 2 éléments
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46}
                        };
        char comb[5];
        initCode(comb);
                system("cls" ); // Nettoyer la console
// -----------------------------------------------------------------------------------------------------------------------------------------------------
            // Jeu du MASTERMIND
            char rep[5]={'\0'};
            while (essais <= 10)
            {
                char resultat[4]={46,46,46,46};
                int i, j, t, test=0, L=1, verif=0; // L : numéroter la ligne du tableau à partir de 10. ligne -> monter d'une ligne lorsque l'on entre une combinaison
               
                int a,b; // variable pour la vérification des combinaisons entrées
                system("cls" ); // Nettoyer la console
                printf("\nCouleurs disponibles : \n" );
                printf("=========================================================\n" );
                printf("r=Rouge - v=Vert - b=Bleu - j=Jaune - o=Orange - m=Marron \n" );
                printf("=========================================================\n\n" );
                // affichage du tableau
                for (i=0;i<=9;i++)
                {
                    printf ("[%3d]-[",L);
                    for (j=0;j<=7;j++)
                    {
                        printf ("(%c)",tab[i][j]);
                    }
                    printf (" ]\n" );
                    L++;
                }
                //printf("\n Les caracteres saisit sont: %c%c%c%c", rep[0],rep[1],rep[2],rep[3]);
                //printf("\n comb : %c%c%c%c",comb[0],comb[1],comb[2],comb[3]);
            // --------------------------------------------------------------------------------------------------------
                // Entrer une combinaison
                while (verif != 4)
                {
                    verif=0;
                    printf("\n\nEssai n# %d: \n",essais);
                    scanf("%s",&rep);
                    fflush(stdin); /*j'ai essayé en utilisant a la place while(fgetc(stdin)!=EOF); mais le problème est qu'alors la combinaison que je rentre ne s'introduit plus dans le tableau .. */
                    // vérification de la combinaison entrée
                    for (a=0;a<=3;a++)
                    {
                        if (rep[a]=='r' || rep[a]=='v' || rep[a]=='b' || rep[a]=='j' || rep[a]=='o' || rep[a]=='m' || rep[a]=='R' || rep[a]=='V' || rep[a]=='B' || rep[a]=='J' || rep[a]=='O' || rep[a]=='M' )
                        {
                            verif++;
                        }
                        else
                        {
                            verif--;
                        }
                    }
                    if (verif !=4)
                    {
                        printf("\nCombinaison impossible. Recommencez !" );
                    }
                }
               
               
                verifierCombi(comb,rep,resultat);
               
               
                tab[essais][0]=rep[0];
                tab[essais][1]=rep[1];
                tab[essais][2]=rep[2];
                tab[essais][3]=rep[3];
                tab[essais][4]=resultat[0];
                tab[essais][5]=resultat[1];
                tab[essais][6]=resultat[2];
                tab[essais][7]=resultat[3];
             
              if (resultat[0]=='N' && resultat[1]=='N' && resultat[2]=='N' && resultat[3]=='N')// Si 4 'N' alors le joueur a trouvé le code secret
                {
                   essais=99;
                                     }
                else{
                     essais++;
                }
    }           
               
               
            // ---------------------------------------------------------------------------------------
            // Jeu terminé
            if (essais == 99) // si essais == 99, alors le joueurs a trouvé la combinaison
            {
                printf("Jeu termine" );
                printf("\n\n  ****** B R A V O *****\n" );
                printf("\n **!!! VOUS AVEZ TROUVE LA COMBINAISON !!!**\n" );
                printf("\n\n*********************************************************\n" );
                printf("---- Entrez (0) pour revenir au menu principal ou (1) pour rejouer : " );
                scanf ("%d",&choix);
            }
            else
            {
                system("cls" ); // Nettoyer la console
                printf("Jeu termine" );
                printf("\n\n*********************************************************\n" );
                printf("---- Entrez (0) pour revenir au menu principal ou (1) pour rejouer : " );
                scanf ("%d",&choix);
            }
            // ---------------------------------------------------------------------------------------
        if (choix == 0)
        {
            menu();
        }
        else
        {
            jeu();
        }
 
}