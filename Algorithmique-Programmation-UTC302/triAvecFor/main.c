//
//  main.c
//  triAvecFor
//
//  Created by Ibrahima BA on 19/06/2024.
//

#include <stdio.h>

// Fonction pour trier un tableau en utilisant le tri par sélection
void triSelection(int tab[], int taille) {
    for (int i = 0; i < taille - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < taille; ++j) {
            if (tab[j] < tab[minIndex]) {
                minIndex = j;
            }
        }
    
        int main() {
            int tableau[] = {5, 2, 9, 1, 5, 6};
            int taille = sizeof(tableau) / sizeof(tableau[0]);

            printf("Tableau avant le tri : ");
            for (int i = 0; i < taille; ++i) {
                printf("%d ", tableau[i]);
            }

            triSelection(tableau, taille);

            printf("\nTableau après le tri : ");
            for (int i = 0; i < taille; ++i) {
                printf("%d ", tableau[i]);
                //printf("\n");
            }
            printf("\n");
            return 0;
        }
