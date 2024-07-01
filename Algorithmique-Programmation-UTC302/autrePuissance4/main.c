//
//  main.c
//  autrePuissance4
//
//  Created by Ibrahima BA on 19/06/2024.
// Site : https://www.developpez.net/forums/d1931201/c-cpp/c/debuter/verification-partie-gagnee-puissance-4-a/

/* Appel de bibliothèque C */
#include <stdio.h>
#include <math.h>
 
#define J1 'X'
#define J2 'O'
#define VIDE ' '
 
#define COL 7
#define LIG 6
 
int choix_colonne , choix_ligne ;
int C , L ;
char grille[LIG][COL];
int win , ega ;
char re = '\0' ;
int v , n ;
 
int main(void)
{
    // DECLARATION DES FONCTIONS APPELLEES
    void initialiser_grille ( char (*grille)[COL] ) ;
    void affiche_grille ( char (*grille)[COL] ) ;
    int verification_colonne ( char (*grille)[COL] , int choix );
    int verification_egalite ( char (*grille)[COL] );
    int demande_colonne_joueur ( int k );
    int verication_partie_gagne ( char (*grille)[COL] , int y , int x);
    void inserer_pion ( char (*grille)[COL] , char symbole , int choix_colonne );
 
    // DECLARATION DES VARIABLES de la fonction main
    int f ;
    // INITIALISER LES VARIABLES
    f=1 ;
    // APPEL DES FONCTIONS
    do
    {
        initialiser_grille ( grille );
 
        do
        {
 
            printf("\nJoueur 1 a vous de jouer!\n");
            inserer_pion ( grille , J1 , demande_colonne_joueur ( COL-1 ) );
 
            win = verication_partie_gagne(grille,L,C);
 
            if ( win == 1 )
            {
                printf("Felicitations! Joueur 1 , vous remportez la partie!");
            }
 
            if ( win != 1 )
            {
                printf("\nJoueur 2 a vous de jouer!\n");
                inserer_pion ( grille , J2 , demande_colonne_joueur ( COL-1 ) );
 
                if ( win == 1 )
                {
                    printf("Felicitations! Joueur 2 , vous remportez la partie!");
                }
            }
 
            ega = verification_egalite (grille) ;
            if ( ega == 1)
            {
                printf("\nMatch Nul!");
            }
        }
        while( ega != 1 );
        //printf("Voulez-vous rejouer la partie? Si oui saisir 1. Choix :",re);
        scanf("%s",&re);
    }
 
    while ( re == 'o');
 
    //SAISIE DES DONNEES
 
    //TRAITEMENT DES DONNEES
 
    //EDITION DES RESULTATS
 
    // SORTIR DE LA FONCTION main()
    printf("\n\n");
    return(0) ;
}
 
// AUTRES FONCTIONS
 
void initialiser_grille ( char (*grille)[COL] )
{
    // Remplissage de la grille pour le debut du jeu : chaque case contient un espace
    int i , j ;
 
    for(i=0 ; i<LIG ; i++)
    {
        for(j=0 ; j<COL ; j++)
        {
            grille[i][j] = VIDE ;
        }
    }
}
 
void affiche_grille ( char (*grille)[COL] )
{
    // Affichage de la grille
    int a , b ;
 
    printf("\n| 0 | 1 | 2 | 3 | 4 | 5 | 6 |\n");
    printf("|---|---|---|---|---|---|---|\n");
    for(a=0; a<LIG; a++)
    {
        printf("|");
        for(b=0 ; b<COL ; b++)
        {
            printf(" %c |", grille[a][b]);
        }
        printf("\n");
        printf("|---|---|---|---|---|---|---|\n");
    }
    printf("| 0 | 1 | 2 | 3 | 4 | 5 | 6 |\n");
}
 
int verification_colonne ( char (*grille)[COL] , int choix_colonne )
{
    if ( ( grille [0][choix_colonne] == J1 ) || ( grille [0][choix_colonne] == J2 ) )  //Verifie si colonne est pleine
    {
        printf("\nLa colonne est pleine!");
        return 1 ;
    }
 
 
    if ( ( choix_colonne > 6 ) || ( choix_colonne < 0 ) )  //Verifie si la saisie de colonne est correcte
    {
        printf("\nVueillez saisir une colonne correcte!");
        return 1 ;
    }
}
 
int verification_egalite ( char (*grille)[COL] )
{
    if ( ( grille[0][0] == J1 || grille[0][0] == J2 ) && ( grille[0][1] == J1 || grille[0][1] == J2 ) && ( grille[0][2] == J1 || grille[0][2] == J2 ) && ( grille[0][3] == J1 || grille[0][3] == J2 )
            && ( grille[0][4] == J1 || grille[0][4] == J2 )&& ( grille[0][5] == J1 || grille[0][5] == J2 )&& ( grille[0][6] == J1 || grille[0][6] == J2 )  )
        return 1 ;
}
 
 
int demande_colonne_joueur ( int k )
{
    // Demande saisi de colonne à l'utilisateur tant que la colonne choisi n'est pas valide
    do
    {
        affiche_grille ( grille );
        printf ("\nChoisissez colonne a jouer : ");
        scanf( "%d" , &choix_colonne );
    }
    while ( verification_colonne ( grille , choix_colonne ) == 1 );
    return choix_colonne;
}
 
void inserer_pion ( char (*grille)[COL] , char symbole , int choix_colonne )
{
 
    for ( choix_ligne=5 ; choix_ligne>=0 ; choix_ligne-- )
    {
        if ( grille[choix_ligne][choix_colonne]==VIDE)
        {
            if ( symbole==J1 )
            {
                grille[choix_ligne][choix_colonne]=J1;
                break ;
            }
 
            if ( symbole==J2 )
            {
                grille[choix_ligne][choix_colonne]=J2;
                break ;
            }
        }
    }
}
 
int verication_partie_gagne ( char (*grille)[COL] , int y , int x)
{
    int k ;
 
    for(k=0 ; k<COL ; k++)
    {
        if ( y>=3 ) //Verification alignement vertical
        {
            if( grille[y][x]==J1 && grille[y-1][x]==J1 && grille[y-2][x]==J1 && grille[y-3][x]==J1
                    || grille[y][x]==J2 && grille[y-1][x]==J2 && grille[y-2][x]==J2 && grille[y-3][x]==J2)
                return 1 ;
        }
 
 
        else if ( x<=3 ) //Verification alignement horizontal
        {
            if( grille[y][x]==J1 && grille[y][x+1]==J1 && grille[y][x+2]==J1 && grille[y][x+2]==J1
                    || grille[y][x]==J2 && grille[y][x+1]==J2 && grille[y][x+2]==J2 && grille[y][x+2]==J2)
                return 1 ;
        }
 
 
 
        else if ( y>=3 ) //Verification alignement diagonal montant
        {
            if( grille[y][x]==J1 && grille[y-1][x+1]==J1 && grille[y-2][x+2]==J1 && grille[y-3][x+3]==J1
                    || grille[x][y]==J2 && grille[x+1][y-1]==J2 && grille[x+2][y-2]==J2 && grille[x+3][y-3]==J2)
                return 1 ;
        }
 
 
        else if ( y<=2 ) //Verification alignement diagonal montant
        {
            if( grille[y][x]==J1 && grille[y+1][x+1]==J1 && grille[y+2][x+2]==J1 && grille[y+3][x+3]==J1
                    || grille[y][x]==J2 && grille[y+1][x+1]==J2 && grille[y+2][x+2]==J2 && grille[y+3][x+3]==J2)
                return 1 ;
        }
 
        else
            return 0 ;
    }
}
