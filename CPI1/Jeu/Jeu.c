#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5 //Taille du plateau
#define X 'X' //case allumée
#define O 'O' // case éteinte
#define Light 5

typedef char tab[N][N];

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

void Ini(tab T){ //Initialisation du tableau
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            T[i][j] = O;
        }
    }
}

void AffichTab(tab T){ //Affichage du tableau
    int i,j;
    int c = 0;
    printf(" ");
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

void PlaceLumiere(tab T){ //placement des cases allumées
    int i, j;
    int cl; //Compteur de lumière
    for ( cl = 0; cl < Light; cl++)
    {
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

void Chang(tab T, int i, int j){
    if (j==0){
        if (i==0){
            Swap(i+1, j, T);
            Swap(i, j+1, T);
        }
        else
        {
            if (i== N-1){
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
                    Swap(i-1, j, T);
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
            Swap(i+1, j, T);
            Swap(i-1, j, T);
            Swap(i, j-1, T);
            Swap(i, j+1, T);
        }
        
    }
}

void jeu(tab T){
    int win = 0;
    int colonne;
    int ligne;
    int compteur = Light; //Pour compter combien de case allumée il y a
    printf("\n~Lights Out~\n\n");
    while ((win == 0 ) && (compteur != 0))
    {
        AffichTab(T);
        printf("Ligne : ");
        scanf("%d",&ligne);
        while ((ligne < 0) || (ligne >= N)){
            printf("Ligne invalide refaites une saisie : ");
            scanf("%d",&ligne);
        }
        
        printf("Colonne: ");
        scanf("%d", &colonne);
        while ((colonne < 0) || (colonne >=N))
        {
            printf("Colonne invalide refaites une saisie: ");
            scanf("%d", &colonne);
        }
        printf("\n");

        if (T[ligne][colonne] == X)
        {
            T[ligne][colonne] = O;
            Chang(T,ligne,colonne);
        }

        else 
        {
            if ((T[ligne][colonne] == O))
            {
                T[ligne][colonne] = X;
                Chang(T, ligne, colonne);
            }
        }
    } 
    if (compteur == 0){
        win = 1;
    }
    if (win == 1){
        printf("Vous avez gagné! ");
    }
}

int main(){
    srand(time(NULL));
    tab T;
    Ini(T);
    PlaceLumiere(T);
    jeu(T);
    return 0;
}