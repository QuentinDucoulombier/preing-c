#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UNITEPIXEL 40

static int nbMines, tailleCoteEnNbrCases;

//Choix du niveau de jeu 
void niveauDeJeu ();
// Fonction qui affiche le MODE D'EMPLOI.
//Fonction hasard.
int hasard (int binf, int bsup);
// Met à 0 un tableau d'entiers
void metAFaux (int t[][tailleCoteEnNbrCases+2]);
//Dans le terminal, affiche un tableau d'entiers 0 ou 1
void afficheTabTerminal (int t[][tailleCoteEnNbrCases+2]);
// Met à vrai exactement nbMines cases dans le tableau 
void placeMines (int t[][tailleCoteEnNbrCases+2], int indicek, int x, int y);
// Compte le nombre de mines dans le carré 3*3 centré sur une case désignée par l'utilisateur // Si on clique sur le bouton stop, on arrête le jeu
void compte (int t[][tailleCoteEnNbrCases+2], int *x, int *y, int *mine);
// Affiche la fenêtre graphique avec ses coordonnées
void afficheGraphique ();
// Afficher le nombre de mines adjacentes dans le graphique.
void afficheCase (int i, int j, int n);
// Retourne les coordonnée d'une case cliquée. BoutonSourisGaucheCentreDroite : le clique gauche == 1, centre == 2, droit == 3 ATTENTION À NE PAS FAIRE ROULER LA MOLETTE.
void coordonneesPointGraph (int *pointx,int *pointy, int *BoutonSourisGaucheCentreDroite);
//Dans le jeu de Microsoft, il n'y a jamais de mine dans la première case jouée, la partie ne se termine jamais au premier coup. Faisons de même ^^. Il s'agit donc de déplacer la mine dans une case vide, choisit au hasard. 
void clic1DeplacerMine(int t[][tailleCoteEnNbrCases+2], int x, int y, int progressionDeLaPartie);
//D'après le poly, « Question subsidiaire très difficile ». Dans le démineur de Microsoft TM, le programme aide le joueur toutes les cases d'une mine comportant un 0 visitée par le joueur, ou découverte par ce mécanisme. En effet, le joueur sait très bien qu'il ne risque rien à cliquer sur la voisine d'un 0.
void caseSansMine (int champ[][tailleCoteEnNbrCases+2], int visite[][tailleCoteEnNbrCases+2], int *x, int *y, int *mine, int *progressionDeLaPartie);

int main(void)
{
	//FONCTIONS AFFICHÉES AVANT DE DÉBUTER LE JEU.
	printf ("\n***************** Le jeu du démineur ******************\n");
	// Fonction qui affiche le MODE D'EMPLOI.
	
	printf ("\n\n\n\n");
	//Boucle qui se termine quand on DÉCIDE d'arrêter de jouer. 
	char recommencerJeu ='o';
	while (recommencerJeu=='o'){

		niveauDeJeu ();

		//DÉCLARATION DES VARIABLES
		int champ[tailleCoteEnNbrCases+2][tailleCoteEnNbrCases+2];//La case est-elle minée ? Une case à 1 indique la mine s'y trouve
		int visite[tailleCoteEnNbrCases+2][tailleCoteEnNbrCases+2];//La case a-t-elle été visitée ? 1 = on a déjà visité. Pour la question 10	
		char continuerLaPartie; //Si continuerLaPartie == 'o' (parcequ'on a cliqué sur une mine, ou sur le bouton stop), la partie s'arrête. 
		int x, y; //Coordonnées écran 
		int i, j; //Coordonnées champ 
		int mine; //Le nombre de mines adjacentes à la case désignée à la souris
		int indiceKPourFonctionPlaceMines;
		int progressionDeLaPartie; //Quand progressionDeLaPartie = tailleCoteEnNbrCases ^ 2, on a gagné
		int BoutonSourisGaucheCentreDroite; //Le clique gauche == 1, centre == 2, droit == 3
		srand (time(NULL));

		// Met à 0 un tableau d'entiers de 0 à tailleCoteEnNbrCases + 1
		metAFaux(champ);

		// Met à vrai exactement nbMines cases dans le tableau
		indiceKPourFonctionPlaceMines = 1; //« 1 » car on veut mettre de 1 à nbMines mines. 
		x=0;
		y=0;//Comme ça on envoit 0 à la fonction placeMines, et on peut rentrer dans une de ses boucles. 
		placeMines(champ, indiceKPourFonctionPlaceMines, x, y);

		// Initialisation du tableau visite. Visite == Champ. Comme ça, quand le tableau visite serait tout remplit, on pourra savoir que le jeu est terminé. 
		for (j=1;j<=tailleCoteEnNbrCases;j++)
			for (i=1;i<=tailleCoteEnNbrCases;i++)
				visite[j][i] = champ[j][i];
		// Dans le terminal, affiche un tableau d'entiers 0 ou 1
		afficheTabTerminal (champ);
		// Affiche la fenêtre graphique avec ses coordonnées
		afficheGraphique ();

		continuerLaPartie ='o';//Si continuerLaPartie == 'o' (parcequ'on a cliqué sur une mine, ou sur le bouton stop), la partie s'arrête. 
		//Boucle qui se termine quand on a terminé la partie, SOIT qu'on ait décidé de mettre fin à la partie (continuerLaPartie == 0), SOIT qu'on ait perdu (continuerLaPartie == 'o'), SOIT qu'on ait gagné (progressionDeLaPartie == tailleCoteEnNbrCases*tailleCoteEnNbrCases).
		progressionDeLaPartie = nbMines;
		while (continuerLaPartie =='o' && progressionDeLaPartie < tailleCoteEnNbrCases*tailleCoteEnNbrCases){

			// Retourne les coordonnée d'une case cliquée. BoutonSourisGaucheCentreDroite : le clique gauche == 1, centre == 2, droit == 3. On ne peut pas cliquer dans la marge, sauf dans le bouton stop. ATTENTION À NE PAS FAIRE ROULER LA MOLETTE. 
			coordonneesPointGraph (&x,&y, &BoutonSourisGaucheCentreDroite);

			if (BoutonSourisGaucheCentreDroite == 1) {//Afin de s'assurer qu'on clique bien sur le bouton gauche 

				//Dans le jeu de Microsoft, il n'y a jamais de mine dans la première case jouée, la partie ne se termine jamais au premier coup. Faisons de même ^^. Il s'agit donc de déplacer la mine dans une case vide, choisit au hasard. 
				clic1DeplacerMine (champ, x, y, progressionDeLaPartie );

				// Si on clique sur le bouton stop, on arrête le jeu.
				if (x==tailleCoteEnNbrCases+1 && y==tailleCoteEnNbrCases+1){
					do {
						printf ("\n\nVous avez appuyé sur le bouton stop, souhaitez-vous continuer ? [o/n] ");
						scanf (" %c",&continuerLaPartie);
					} while (continuerLaPartie != 'o' &&  continuerLaPartie != 'n');
					// if (continuerLaPartie == 'n');{
					// 	Clore ()
					// }Si on décommente cette boucle, et qu'on commente le clore tout en bas, ça me fait un core Dump. Bijarre, je ne comprends pas. 
				}

				//Si on tombe sur une mine, on perd la partie. 
				if (champ[y][x] == 1){
					continuerLaPartie='n';
					printf ("\n\nBoom ! Vous êtes tombé sur une mine : perdu :'(.");
					// Clore(); Si on décommente cette boucle, et qu'on commente le clore tout en bas, ça bug de temps en temps. Bijarre, je ne comprends pas. 
				}

				// Si on ne tombe pas sur une mine, on continue la partie. D'après la fonction coordonneesPointGraph, 
				if (continuerLaPartie == 'o' && !(x==tailleCoteEnNbrCases+1 && y==tailleCoteEnNbrCases+1 )){//Coordonnées du bouton stop 
					// Compte le nombre de mines dans le carré 3*3 centré sur une case désignée par l'utilisateur 
					compte (champ, &x,&y,&mine);
					// Afficher le nombre de mines adjacentes dans le graphique
					afficheCase (x,y,mine);
					if (visite[y][x]==0){
						visite[y][x]=1;
						progressionDeLaPartie ++;
					}
					if (mine == 0 )
						caseSansMine ( champ, visite,  &x,  &y, &mine,  &progressionDeLaPartie);
				}

				//D'après le poly, « Question subsidiaire très difficile ». Je ne comprends pas pourquoi. Dans le démineur de Microsoft TM, le programme aide le joueur toutes les cases d'une mine comportant un 0 visitée par le joueur, ou découverte par ce mécanisme. En effe, le joueur sait très bien qu'il ne risque rien à cliquer sur la voisine d'un 0.

				//Si on a gagné la partie, on arrête la partie.
				if (progressionDeLaPartie == tailleCoteEnNbrCases * tailleCoteEnNbrCases){
					printf ("\n\nDéminage réussi ! Bravo, vous avez gagné :=)");
				}
			}

			//Quand on clique sur le bouton droit, on dessine un rectangle plein. C'est l'astuce des drapeaux. « On peut signaler les cases contenant des mines présumées par un drapeau en cliquant sur le bouton droit de la souris — mais ce n'est aucunement obligatoire. Il faut faire attention à ne pas signaler une case saine par un drapeau, car cela peut induire en erreur ; ce n'est toutefois pas aussi pénalisant que de découvrir une mine. » (Source Wikipédia).
			if (BoutonSourisGaucheCentreDroite == 3){
				RectanglePlein (x * UNITEPIXEL , y * UNITEPIXEL , (x+1) * UNITEPIXEL, (y+1)*UNITEPIXEL);
			}
		}
		Clore();
		//Une fois qu'on a terminé la partie, on demande si on veut rejouer.
		do{
			printf("\n\nSouhaitez-vous recommencer le jeu ? [o/n] ");
			scanf (" %c",&recommencerJeu);
			} while (recommencerJeu != 'o' && recommencerJeu != 'n');
	 }
	printf ("\n*************** Fin du jeu ****************\n");
	return 0;
}



//niveau de jeu 
void niveauDeJeu (){
	int niveau;
	 //Dans la fonction « afficheGraphique », vu qu'on a définit cara[3], on ne peut pas dépasser 99, car il faut que « cara[2]==""; » 
	do{
		printf ("Quel niveau souhaitez-vous ? [1, 2, 3, 4, 5, 6, 7] ");
		scanf ("%d",&niveau);
	} while (niveau < 1 || niveau > 7 );

	switch (niveau){
		case 1 :
			nbMines = 4;
			tailleCoteEnNbrCases = 7;
		break;
		case 2 :
			nbMines = 8;
			tailleCoteEnNbrCases = 7;
		break;
		case 3 :
			nbMines = 15;
			tailleCoteEnNbrCases = 10;
		break;
		case 4 :
			nbMines = 25;
			tailleCoteEnNbrCases = 10;
		break;
		case 5 :
			nbMines = 25;
			tailleCoteEnNbrCases = 15;
		break;
		case 6 :
			nbMines = 45;
			tailleCoteEnNbrCases = 15;
		break;
		case 7 :
			nbMines = 60;
			tailleCoteEnNbrCases = 15;
		break;
	}
}


// Fonction hasard.
int hasard (int binf, int bsup){
	return rand()/((double)RAND_MAX+1) * (bsup + 1 - binf) + binf;
}

 // Met à 0 un tableau d'entiers
void metAFaux (int t[][tailleCoteEnNbrCases+2]){
	int i, j;
	for (j=0;j<=tailleCoteEnNbrCases+1;j++)
		for (i=0;i<=tailleCoteEnNbrCases+1;i++)
			t[j][i]=0;
	}

// Dans le terminal, affiche un tableau d'entiers 0 ou 1
void afficheTabTerminal (int t[][tailleCoteEnNbrCases+2]){
	int i, j;
	printf ("\n\nLa grille du jeu : tricheur, tu l'as regardé ;=)\n\n");
	//On affiche les numéros des lignes sur la première ligne. 
	printf ("     ");
	for (i=1;i<=tailleCoteEnNbrCases;i++)
		printf(" %2d ",i );
	printf ("\n");
	//On affiche la grile du jeu, et après chaque retour à la ligne on affiche le numéro des colonnes.
	for (j=1;j<=tailleCoteEnNbrCases;j++){
		printf ("\n");
		printf (" %2d  ",j);
		for (i=1;i<=tailleCoteEnNbrCases;i++)
			printf (" %2d ",t[j][i]);
	}
}


// Met au hasard à vrai exactement nbMines cases dans le tableau. Je l'ai trouvé tout seul, mais d'après Wikipédia Fr, si y'a trop de mines je vais faire ramer mon ordi. À refaire avec un autre algo. 
void placeMines (int t[][tailleCoteEnNbrCases+2], int indicek, int x, int y){
	int i,j;
	//Quand on a placé toutes les mines, on termine la fonction. 
	while(indicek<=nbMines){
		//do {
			j=hasard(1,tailleCoteEnNbrCases);
			i=hasard(1,tailleCoteEnNbrCases);
		// } while (i == x &&  j == y);  //Boucle utile pour la fonction « clic1DeplacerMine ». Pour pas que la mine soit remise au même endroit.
		if (t[j][i]!=1){
			t[j][i]=hasard(0,1);
			if(t[j][i]==1)
				indicek = indicek + 1;
		}
	}
}


// Compte le nombre de mines dans le carré 3*3 centré sur une case désignée par l'utilisateur.
void compte (int t[][tailleCoteEnNbrCases+2], int *x, int *y, int *mine){
	int i,j;
	// Note : dans les cases du bord, il y a forcément 0, vu que j'aie initialisé le tableau grille ainsi. 
	//La fonction :
	*mine=0;
	for (j=*y - 1; j<=*y + 1 ; j++)
		for (i=*x -1 ; i <= *x + 1; i++)
			if (t[j][i]==1)
				*mine = *mine + 1;

	switch (*mine){
		case 0 :
			printf ("\nAutour de la case de coordonnées (%d,%d), aucune mine n'est présente.",*x,*y);
		break;
		case 1 :
			printf ("\nAutour de la case de coordonnées (%d,%d), une seule mine est présente.",*x,*y);
		break;
		default :
			printf ("\nAutour de la case de coordonnées (%d,%d), %d mines sont présentes.",*x,*y, *mine);
		break;
	}
}


// Affiche la fenêtre graphique avec ses coordonnées
void afficheGraphique (){
	int i;
	char cara[3]="";


	Initialiser (UNITEPIXEL*tailleCoteEnNbrCases+(2*UNITEPIXEL),UNITEPIXEL*tailleCoteEnNbrCases+(2*UNITEPIXEL));
	//Pour les lignes
	for (i=0;i<=tailleCoteEnNbrCases;i++)
		Ligne (UNITEPIXEL,i*UNITEPIXEL + UNITEPIXEL,tailleCoteEnNbrCases*UNITEPIXEL + UNITEPIXEL,i*UNITEPIXEL + UNITEPIXEL);
	for (i=1;i<=tailleCoteEnNbrCases;i++){
		sprintf (cara, "%d",i);
		Ecrire (UNITEPIXEL/2+(i*UNITEPIXEL),UNITEPIXEL/2,cara);
	}

	//Pour les colonnes
	for (i=0;i<=tailleCoteEnNbrCases;i++)
		Ligne (i*UNITEPIXEL + UNITEPIXEL,UNITEPIXEL,i*UNITEPIXEL + UNITEPIXEL,tailleCoteEnNbrCases*UNITEPIXEL + UNITEPIXEL);

	for (i=1;i<=tailleCoteEnNbrCases;i++){
		sprintf (cara, "%d",i);
		Ecrire (UNITEPIXEL/2,UNITEPIXEL/2+(i*UNITEPIXEL),cara);
	}

	//Titre 
	Ecrire ( tailleCoteEnNbrCases*UNITEPIXEL /2 - (20*4),UNITEPIXEL*tailleCoteEnNbrCases+(2*UNITEPIXEL) - 10, "Trouver des mines dans un champs de mine");
	Ecrire ( tailleCoteEnNbrCases*UNITEPIXEL /2 - 8,UNITEPIXEL*tailleCoteEnNbrCases+(2*UNITEPIXEL) - 20, " Jeu le demineur");

	//Bouton stop 
	Ecrire ((tailleCoteEnNbrCases+1)*UNITEPIXEL + UNITEPIXEL/3 ,(tailleCoteEnNbrCases+1)*UNITEPIXEL + UNITEPIXEL/2,"Stop");
}

// Afficher le nombre de mines adjacentes dans le graphique
void afficheCase (int i, int j, int n){
	char str[2];
	str[0] = '0'+ n;
	str[1] = '\0';
	EcrireDessus( UNITEPIXEL * i+UNITEPIXEL/2-5,
					UNITEPIXEL * j +UNITEPIXEL/2 + 5,
					str);
}

// Retourne les coordonnée d'une case cliquée. BoutonSourisGaucheCentreDroite : le clique gauche == 1, centre == 2, droit == 3. On ne peut pas cliquer dans la marge, sauf dans le bouton stop. ATTENTION À NE PAS FAIRE ROULER LA MOLETTE. 
void coordonneesPointGraph (int *pointx,int *pointy, int *BoutonSourisGaucheCentreDroite){
	int x, y;
	do {
		AttendreClicXY (&x,&y,&*BoutonSourisGaucheCentreDroite);
		*pointx=x/UNITEPIXEL;
		*pointy=y/UNITEPIXEL;
	}while ((*pointx>tailleCoteEnNbrCases || *pointy >tailleCoteEnNbrCases || *pointx<1 || *pointy<1) && (*pointx != tailleCoteEnNbrCases + 1 || *pointy != tailleCoteEnNbrCases + 1)); // Quand on clique dans la marge, on retourne dans la boucle, sauf si on clique sur stop 
}

//Dans le jeu de Microsoft TM, il n'y a jamais de mine dans la première case jouée, la partie ne se termine jamais au premier coup. Faisons de même ^^. Il s'agit donc de déplacer la mine dans une case vide, choisit au hasard.
void clic1DeplacerMine(int t[][tailleCoteEnNbrCases+2], int x, int y, int progressionDeLaPartie){
	int indiceKPourFonctionPlaceMines;
	if (progressionDeLaPartie == nbMines) //Si c'est le premier coup
		if (t[y][x] == 1 ){
			printf ("\n\nMalchance :=|,vous êtes tombé sur une mine au premier coup. Déplacement de la mine sur une autre case non minée.");
			t[y][x] = 0; //On supprime la mine de la case cliquée
			indiceKPourFonctionPlaceMines = nbMines;
			placeMines(t, indiceKPourFonctionPlaceMines, x, y); //On met la mine ailleurs
			afficheTabTerminal (t);
        
	}
}

//D'après le poly, « Question subsidiaire très difficile ». Dans le démineur de Microsoft TM, le programme aide le joueur toutes les cases d'une mine comportant un 0 visitée par le joueur, ou découverte par ce mécanisme. En effet, le joueur sait très bien qu'il ne risque rien à cliquer sur la voisine d'un 0.
void caseSansMine (int champ[][tailleCoteEnNbrCases+2], int visite[][tailleCoteEnNbrCases+2], int *x, int *y, int *mine, int *progressionDeLaPartie){
	int i,j;
	for (j=*y - 1; j<=*y + 1 ; j++)
		for (i=*x -1 ; i <= *x + 1; i++){
			//On regarde ce qu'il y a autour des cases qui n'appartiennent pas à la marge. 
			if (i<=tailleCoteEnNbrCases && j <=tailleCoteEnNbrCases && i>=1 && j>=1){
					if (visite [j][i] == 0){
					// Compte le nombre de mines dans le carré 3*3 centré sur une case désignée par l'utilisateur 
					compte (champ, &i,&j,&*mine);
					// Afficher le nombre de mines adjacentes dans le graphique
					afficheCase (i,j,*mine);
					if (visite[j][i]==0){
						visite[j][i]=1;
						*progressionDeLaPartie = *progressionDeLaPartie + 1;
					}
				//Si dans une des cases adjacentes, c'est marqué 0, on rentre à nouveau dans la fonction caseSansMine. 
				if (*mine == 0)
				 	caseSansMine (champ, visite, &i, &j, &*mine, &*progressionDeLaPartie);
				}
			}
		}
}
