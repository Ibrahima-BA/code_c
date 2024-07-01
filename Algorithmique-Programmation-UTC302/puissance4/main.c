//
//  main.c
//  puissance4
//
//  Created by Ibrahima BA on 08/06/2024.
// Site à voir : https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/5147_tp-un-puissance-4/#6-correction-2


#include <stdlib.h>
#include <stdio.h>

#define LARGEUR 7
#define HAUTEUR 6

void affiche(int plateau[LARGEUR][HAUTEUR]){
    printf("---------------\n");
    for (int h = 0; h < HAUTEUR; h++) {
        printf("|");
        for (int l = 0; l < LARGEUR; l++) {
            if(plateau[l][h] == 1){
                printf("X");
            }
            else if(plateau[l][h] == -1){
                printf("O");
            }
            else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n---------------\n");
    }
}

void init(int plateau[LARGEUR][HAUTEUR]){
    for (int h = 0; h < HAUTEUR; h++) {
        for (int l = 0; l < LARGEUR; l++) {
            plateau[l][h] = 0;
        }
    }
}

int partieTermine(int plateau[LARGEUR][HAUTEUR], int joueurCourant){
    return 0;
}

int getPlaceLibre(int plateau[LARGEUR][HAUTEUR], int colonne){
    int hauteur = 0;
    while(plateau[colonne][hauteur] == 0 && hauteur < HAUTEUR){
        hauteur++;
    }
    return hauteur-1;
}


int main ()
{
    int plateau[LARGEUR][HAUTEUR];
    int joueur = 1;
    int colonne;
    
    init(plateau);
    //plateau[5][0] = 1;
    affiche(plateau);
    int partieTerminee = 0;
    while(partieTerminee == 0){
        int coupOK = 0;
        do{
            printf("Joueur %d veuillez saisir deux coordonnees : \n", joueur == 1 ? 1 : 2);
            scanf("%d", &colonne);
            if(plateau[colonne-1][0] == 0){ // choisir une colonne et gestion de gravité
                int hauteur = getPlaceLibre(plateau, colonne-1);
                plateau[colonne-1][hauteur] = joueur;
                printf("Colonne %d hauteur %d\n", colonne-1, hauteur);
                coupOK = 1;
            }
        }while (coupOK == 0);

        affiche(plateau);
        partieTerminee = partieTermine(plateau, joueur);
        joueur = joueur * -1;
    }
    
    if(partieTerminee == 3){
        printf("Match nul qui porte bien son nom");
    }
    else{
        printf("Joueur %d a gagne\n", partieTerminee);
    }
    
    return 0;
}
