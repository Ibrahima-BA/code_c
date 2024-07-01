//
//  main.c
//  AjouterElementDunTableauAvecMenu
//
//  Created by Ibrahima BA on 25/06/2024.
// gcc main.c -o AjouterElementDunTableauAvecMenu

#include <stdio.h>
#include<stdlib.h>

#define SIZE 100

void afficherTableau(int tab[], int taille) {
    printf("Tableau : ");
    taille = 10;
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void triBulle(int tab[]) {
    int i;
    int j;
    int tmp;
    
    for (i = 0; i < SIZE -  1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                // Échange les éléments
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    
    int tab[SIZE];
    int taille = 0; // Taille actuelle du tableau
    
    // Remplissage de la liste avec des nombres aléatoires entre 1 et 10
    for ( int i=0; i < SIZE; ++i)
       {
           int random = rand() % 10 + 1; // Valeurs entre 1 et 10
           tab[i] = random;
           taille ++;
       }
    triBulle(tab);
    while (1) {
        printf("Menu :\n");
        printf("1. Ajouter un élément\n");
        printf("2. Afficher le tableau\n");
        printf("3. Quitter\n");

        int choix;
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (taille < SIZE) {
                    int nouvelElement ;
                    
                    printf("Le tables avant ajout : ");
                    afficherTableau(tab, taille);
                    
                    printf("Entrez l'élément à ajouter : ");
                    scanf("%d", &nouvelElement);
                    tab[taille+10] = nouvelElement;

                    // Affichage du tableau mis à jour
                       printf("Tableau après ajout : ");
                        afficherTableau(tab+1, taille);
                    
                } else {
                    printf("Le tableau est plein. Impossible d'ajouter plus d'éléments.\n");
                }
                break;
            case 2:
                afficherTableau(tab, taille);
                break;
            case 3:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez choisir 1, 2 ou 3.\n");
                break;
        }
    }

    return 0;
}
