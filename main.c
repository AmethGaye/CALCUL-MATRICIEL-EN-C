#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100

/*---------------------------LES VARIABLES GLOBAL---------------------------*/

int Mat[N][N];
int T[N][N]; // la transposee
int I[N][N]; // matrice inferieur 
int S[N][N]; // matrice superieur 
int size = 0; // dimension du matrice carrée n x n saisie 

/*-----------------------------LES PRINCIPALES FONCTIONS---------------------------*/
// LECTURE 
void lecture()
{
    int x;
    printf("tapez la Dimension du matrice carree :  ");
    scanf("%d",&size);

    // lecture des donnees 
    for(int i = 0;i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            // demander chaque element du matrice et l'affecter
            printf("element[%d][%d] : ",i,j);
            scanf("%d",&x); 
            Mat[i][j] = x;
        }
    }
}

// AFFICHAGE :
void print(int tab[N][N])
{
    for(int i=0; i<size; i++){
        printf("\t+   ");
        for(int j=0; j < size; j++){
            if(tab[i][j] < 10)
                printf(" %d   ",tab[i][j]);
            else
               printf("%d   ",tab[i][j]); 
        }
        printf("+\n\n");
    }
    system("pause");
}
// TEST : MATRICE IDENTITE 
void matriceIdentite(){
    int isIdentity = 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j && Mat[i][j] != 1){
                isIdentity = 0;
            }else if(i != j && Mat[i][j] != 0){
                isIdentity = 0;
            }
            
        }
    }
    if(isIdentity == 1){
        printf("la matrice donnee est une matrice identite !\n\n");

        print(Mat);
    }else{
        printf("la matrice donnee n'est pas une matrice identite !\n");
    }
}
// TEST : LA SYMETIRE D'UNE MATRICE  
void Symetrie(){
    int test = 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(T[i][j] != Mat[i][j] ){
                test = 0;
                break;
            }
        }
    }
    if(test == 1){
        printf("la matrice donnee est symetrique !\n\n");

        print(Mat);
    }else{
        printf("la matrice n'est pas symetrique !\n");
    }
}

// LA TRANSPOSEE 
void Transposee(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            T[i][j] = Mat[j][i];
        }
    }
    print(T);
}

// MATRICE TRINGULAIRE INFERIEUR
void M_inferieur(){
    for(int i = 0; i<size; i++){
        for(int j = 0; j < size; j++){
            if(j < i){
                I[i][j] = 0;
            }
            else{
                I[i][j] = Mat[i][j];
            }
        }
    }
    print(I);
}

// MATRICE TRINGULAIRE SUPERIEUR 
void M_superieur(){
    for(int i = 0; i<size; i++){
        for(int j = 0; j < size; j++){
            if(j > i){
                S[i][j] = 0;
            }
            else{
                S[i][j] = Mat[i][j];
            }
        }
    }
    print(S);
}


// LA FONCTION MAIN()
int main(){
    int x;
    system("color 02");
    while(1)
    {
        menu :
        system("cls");
        printf("\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t+                 MATRICE CARR%cE              +\n",144);
        printf("\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t+                                             +\n");
        printf("\t\t\t\t+   1 - LECTURE                               +\n");
        printf("\t\t\t\t+   2 - AFFICHAGE                             +\n");
        printf("\t\t\t\t+   3 - TEST                                  +\n");
        printf("\t\t\t\t+   4 - ARITHM%cTIQUE                          +\n",144);
        printf("\t\t\t\t+   5 - TRANSPOS%cE                            +\n",144);
        printf("\t\t\t\t+   6 - TRIANGULARISATION INF%cRIEUR           +\n",144);
        printf("\t\t\t\t+   7 - TRIANGULARISATION SUP%cRIEUR           +\n",144);
        printf("\t\t\t\t+   0 - QUITTER                               +\n");
        printf("\t\t\t\t+                                             +\n");
        printf("\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++\n\n");

        printf("faites un choix (proposez une matrice carree en premier lieux) :  ");
        scanf("%d",&x);
        switch(x){
            case 1 : 
            {   lecture();
                break;
            }

            case 2 : 
            {
                system("cls");
                printf("\t[ MATRICE : ] \n\n");
                print(Mat);
                break;
            }
            
            case 3 : 
            {
                menu2 :
                system("cls");
                printf("\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=\n");
                printf("\t\t\t\t=           TEST MATRICIEL           =\n");
                printf("\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=\n");
                printf("\t\t\t\t=                                    =\n");
                printf("\t\t\t\t=    1 - MATRICE IDENTIT%c            =\n",144);
                printf("\t\t\t\t=    2 - SYM%cTRIE                    =\n",144);
                printf("\t\t\t\t=    3 - MENU PRINCIPAL              =\n");
                printf("\t\t\t\t=    4 - QUITTER                     =\n");
                printf("\t\t\t\t=                                    =\n");
                printf("\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=\n");
                printf("votre choix : ");
                scanf("%d",&x);
                switch(x)
                {
                    case 1 :
                    {
                        matriceIdentite();
                        // system("pause");
                        goto menu2;
                        break;
                    }
                    case 2 :
                    {
                        Symetrie();
                        system("pause");
                        goto menu2;
                        break;
                    }
                    case 3 :
                    {
                        goto menu;
                        break;
                    }
                    case 4 :
                    {
                        system("cls");
                        exit(0);
                        break;
                    }
                    
                }


                break;
            }

            case 4 : 
            {
                break;
            }

            case 5 : 
            {
                system("cls");
                printf("\t[ TRANSPOS%cE : ] \n\n",144);
                Transposee();
                break;
            }
            case 6 : 
            {
                system("cls");
                printf("\t[ TRIANGULAIRE INF%cRIEUR : ] \n\n",144);
                M_inferieur();
                break;
            }

            case 7 : 
            {
                system("cls");
                printf("\t[ TRIANGULAIRE SUP%cRIEUR : ] \n\n",144);
                M_superieur();
                break;
            }
            case 0 : 
            {
                system("cls");
                exit(0);
                break;
            }


        }
    }

    return 0;
}