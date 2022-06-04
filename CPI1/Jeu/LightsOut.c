#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 5 //Taille du tableau
#define O 'O' // Case eteinte 
#define X 'X' //Case allumé
#define LUMIERE 11

typedef char tab[N][N];

void Ini(tab);
void AfficheT(tab);
void PlaceLumiere(tab);
void Jeu(tab);
void Changement(tab, int, int);
void Swap(int, int, tab);

/*Fonction principal*/
int main(){
    tab T; // Tableau de jeu
    srand(time(NULL));
    Ini(T); // Initialisation des tableaux (X)
    PlaceLumiere(T); //Placement des lumiere
    Jeu(T); //Variable Jeu


    return 0;
}


/*Procedure pour initalisé le tableau*/
void Ini(tab T){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            T[i][j] = O;
        }
    }
}

/*Procedure pour afficher le tableau*/
void AfficheT(tab T){
int i,j;
int c = 0;
    printf("  ");
    for (c=0;c<N;c++){
        printf("%d ",c);
    }
    c = 0;
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d ",c);
        c++;
        for(j=0;j<N;j++){
            printf("%c ",T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*Procedure pour changer l'etats des lumieres*/
void Swap(int i, int j, tab T){
    if ((T[i][j]) == X)
    {
        T[i][j] = O;
    }
    else 
    {
        if (((T[i][j]) == O))
        {
            T[i][j] = X;
        }
    } 
}


/*Procedure qui place les lumieres de maniere aleatoire*/
void PlaceLumiere(tab T){
    int i,j;
    int cl; //compteur de lumieres

    for(cl=0;cl<LUMIERE;cl++){
        i = rand()%N;
        j = rand()%N;
        if (T[i][j] == X){
            while(T[i][j] == X){
                i = rand()%N;
                j = rand()%N;
            }
            T[i][j] = X;
        }
        else{
            T[i][j] = X;
        }
    }
}




/*Procedure pour changer l'etats des lumieres sur les cases autour de la case sélectionné*/
void Changement(tab T, int i, int j)
{

    if (j==0){
        if (i == 0){
            Swap(i+1, j, T);
            Swap(i, j+1, T);
        }
        else
        {
            if (i == N-1){
                Swap(i-1, j, T);
                Swap(i, j+1, T);
            }
            else
            {
                Swap(i-1, j, T);
                Swap(i+1, j, T);
                Swap(i, j+1, T);
            }
            
        }
        
    }
    else
    {
        if (i == 0){
            if (j == 0){
                Swap(i+1, j, T);
                Swap(i, j+1, T);
            }
            else
            {
                if (j == N-1){
                    Swap(i+1, j, T);
                    Swap(i, j-1, T);
                }
                else
                {
                    Swap(i+1, j, T);
                    Swap(i, j-1, T);
                    Swap(i, j+1, T);
                }
                
            }
            
        }
        else
        {
            if (j == N-1)
            {
                Swap(i+1, j, T);
                Swap(i-1, j, T);
                Swap(i, j-1, T);
            }
            else
            {
                if (i == N-1)
                {
                    Swap(i-1, j, T);
                    Swap(i, j+1, T);
                    Swap(i, j-1, T);
                }
                else
                {
                    Swap(i+1, j, T);
                    Swap(i-1, j, T);
                    Swap(i, j-1, T);
                    Swap(i, j+1, T);
                }
                
                
            }
            
            
        }
        
    }
}






/*Procedure jeu*/
void Jeu(tab T){
    int colonne;
    int ligne;
    int compteur = LUMIERE; //Pour compter combien de case allumée il y a
    
    while (compteur != 0)
    {
        AfficheT(T);   //Affichage du plateau
        printf("Ligne : ");
        scanf("%d",&ligne);
        while ((ligne < 0) || (ligne >= N)){
            printf("Ligne invalide : ");
            scanf("%d",&ligne);
        }
    
        printf("Colonne : ");
        scanf("%d",&colonne);
        while ((colonne < 0) || (colonne >= N)){
            printf("Colonne invalide : ");
            scanf("%d",&colonne);
        }
        printf("\n");
        if (T[ligne][colonne] == X)
        {
            T[ligne][colonne] = O;
            Changement(T,ligne,colonne);
        }

        else 
        {
            if ((T[ligne][colonne] == O))
            {
                T[ligne][colonne] = X;
                Changement(T, ligne, colonne);
            }
        }
        /*printf("%d\n",compteur);*/
    } 
    if (compteur == 0){
        printf("Vous avez gagné! ");
   
    }
}
