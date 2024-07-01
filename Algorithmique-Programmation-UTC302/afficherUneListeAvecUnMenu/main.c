//
//  main.c
//  afficherUneListeAvecUnMenu
//
//  Created by Ibrahima BA on 25/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(void) {

    int liste[SIZE];

    // Remplissage de la liste avec des nombres aléatoires entre 1 et 10
    for (int i = 0; i < SIZE; i++) {
        int random = rand() % 100 + 1; // Valeurs entre 1 et 10
        liste[i] = random;
    }

    // Affichage du menu
    printf("--- Menu ---\n");
    printf("1. Afficher la liste\n");
    printf("2. Quitter\n");

    int choix;
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Liste des nombres aléatoires :\n");
            for (int i = 0; i < SIZE; i++) {
                printf("%d ", liste[i]);
            }
            printf("\n");
            
            break;
        case 2:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }

    return 0;
}
