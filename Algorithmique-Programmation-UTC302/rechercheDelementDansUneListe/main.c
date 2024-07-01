//
//  main.c
//  rechercheDelementDansUneListe
//
//  Created by Ibrahima BA on 25/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int chercherElement(int tab[], int taille, int element) {
    for (int i = 0; i < taille; i++) {
        if (tab[i] == element) {
            return i; // Indice de l'élément trouvé
        }
    }
    return -1; // Élément non trouvé
}

int main(void) {
    int tab[SIZE] = {5, 8, 3, 2, 7, 1, 6, 4, 9, 10};
    int elementRecherche;

    printf("Menu :\n");
    printf("1. Rechercher un élément\n");
    printf("2. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &elementRecherche);

    switch (elementRecherche) {
        case 1:
            printf("Entrez l'élément à rechercher : ");
            scanf("%d", &elementRecherche);
            int indice = chercherElement(tab, SIZE, elementRecherche);
            if (indice != -1) {
                printf("L'élément %d se trouve à l'indice %d dans le tableau.\n", elementRecherche, indice);
            } else {
                printf("-1 car l'élément %d n'existe pas dans le tableau.\n", elementRecherche);
            }
            break;
        case 2:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide. Veuillez choisir 1 ou 2.\n");
            break;
    }

    return 0;
}
