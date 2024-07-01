// https://www.mycompiler.io/view/8FIppaDzVyn

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



    char** initialise_grille () {
        char** grille = malloc(6*sizeof(char**));
        for (int i = 0; i < 6; i++) {
            grille[i] = malloc(7*sizeof(char**));
            for (int j = 0; j < 7; j++) {
                grille[i][j] = '.';
            }
        }
        return grille;
    }
    
    void libere(char** grille) {
        for (int i = 0; i < 6; i++) {
             free(grille[i]);
             }
        free(grille);
    }

    void affiche_grille (char** grille) {
       printf("| 0   1   2   3   4   5   6 |");
            for (int i = 0; i < 6; i++) {
                printf("\n+---+---+---+---+---+---+---+ \n|");
                for (int j = 0; j < 7; j++) {
                    printf(" %c |", grille[i][j]);
                }
            }
        printf("\n+---+---+---+---+---+---+---+ \n");
        }


    bool coup_valide (char** grille, int colonne) {
        int compteur = 0;
        for (int i = 0; i < 6; i++) {
            if (grille[i][colonne] == '.') {
                compteur++;
            }
        }
        if (compteur == 0) {
            return false;
        }
        else {
            return true;
        }
    }

    void inserer (char** grille, char joueur, int colonne) {
        if (&coup_valide != false) {
           int compteur = 0;
           for (int i = 0; i < 6; i++) {
               if (grille[i][colonne] == '.') {
                   compteur++;
               }
           }
           grille[compteur][colonne] = joueur;
           }
        }

    bool victoire_horizontale(char** grille, char joueur) {
        int compteur = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (grille[i][j] == grille[i+1][j] == grille[i+2][j] == grille[i+3][j]) {
                    return true;
                    //compteur ++;
                }
            }
        }
        if (compteur == 0){
            return false;
        }
        return true;
    }

    bool victoire_verticale(char** grille, char joueur) {
        int compteur = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (grille[i][j] == grille[i][j+1] == grille[i][j+2] == grille[i][j+3]) {
                    return true;
                    //compteur++;
                }
            }
        }
        if (compteur == 0){
            return false;
        }
        return true;
    }

     bool victoire_diagonale1(char** grille, char joueur) {
        int compteur = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (grille[i][j] == grille[i+1][j+1] == grille[i+2][j+2] == grille[i+3][j+3]) {
                    return true;
                    //compteur++;
                }
            }
        }
         if (compteur == 0){
            return false;
        }
         return true;
     }

    bool victoire_diagonale2(char** grille, char joueur) {
        int compteur = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (grille[6-i][j] == grille[5-i][j+1] == grille[4-i][j+2] == grille[3-i][j+3]) {
                    return true;
                    //compteur++;
                }
            }
        }
        if (compteur == 0){
            return false;
        }
        return true;
     }

    bool victoire(char** grille, char joueur) {
        if (victoire_horizontale(grille, joueur) == true ||  victoire_verticale(grille, joueur) == true || victoire_diagonale1(grille, joueur) == true || victoire_diagonale2(grille, joueur) == true) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool grille_pleine(char** grille) {
        int compteur = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if ( grille[i][j] == '.') {
                    compteur++;
                }
            }
        }
        if (compteur > 0){
            return false;
        }
        else {
            return true;
        }
    }

    bool partie_terminee(char** grille) {
        char joueur1 = 'X';
        char joueur2 = 'O';
        if (victoire(grille, joueur1) == true || victoire(grille, joueur2) == true || grille_pleine(grille) == true) {
            return true;
        }
        else {
            return false;
        }
    }

 
void partie_2_joueurs() {
    char** grille = initialise_grille();
    affiche_grille(grille);
    char premierjoueur = 'X';
    char deuxiemejoueur = 'O';
    int tour = 0;
    while (partie_terminee(grille) == false) {
       if ( tour == 0 ) {
          printf("Tour du Joueur 1 :\n Dans quelle colonne souhaitez-vous insérer votre jeton ? \n");
          int f;
          scanf ("%d", &f);
          inserer (grille, premierjoueur, f);
          affiche_grille(grille);
          tour++;
       }
    else {
        printf("Tour du Joueur 2 :\n Dans quelle colonne souhaitez-vous insérer votre jeton ? \n");
        int f;
        scanf ("%d", &f);
        inserer (grille, deuxiemejoueur, f);
        affiche_grille(grille);
        tour = tour - 1;
    }
    }
    if (victoire(grille, premierjoueur) == true) {
        printf("Victoire du Joueur 1 !");
        }
    else if (victoire(grille, deuxiemejoueur) == true) {
            printf("Victoire du Joueur 2 !"); }
    else {
        printf("Egalité (grille pleine) !");
    }
    libere(grille);
}


int main() {
    char** grille = initialise_grille();
    affiche_grille(grille);
    //partie_2_joueurs(initialise_grille);
    inserer;
    return 0;
    }
