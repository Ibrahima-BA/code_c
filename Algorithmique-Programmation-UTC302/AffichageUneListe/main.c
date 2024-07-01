//
//  main.c
// Affichage d'une liste
//  Préparation à l'examen
// Afficher la liste sur un tableau de taille 100
//  Created by Ibrahima BA on 24/06/2024.
//

#include <stdio.h>
#include <stdlib.h> // Librairie pour la fonction rand

#define SIZE 10

int main(void) {
    int tab[SIZE];
    int n = 0; // Initialisation de n à 0

    // Remplissage de la liste avec des nombres aléatoires entre 1 et 10
    for (int i = 0; i < SIZE; i++) {
        int random = rand() % 10 + 1; // Valeurs entre 1 et 10
        tab[i] = random;
        printf("%d : Les valeurs suivantes sont : %d\n", n, tab[i]);
        n++; // Incrémentation de n

    if (tab[i] == 10) {
        printf("L'élément de la liste contient la valeur numérique 10 \n");
        }
        else  {
            printf ("-1\n");
        }
    }
    // Ajout d'un élément à la fin du tableau
        int nouvelElement = 42; // Remplacez 42 par la valeur que vous souhaitez ajouter
        tab[SIZE - 1] = nouvelElement;
        printf("Nouvel élément ajouté à la fin du tableau : %d\n", tab[SIZE - 1]);

    printf("Fin du programme\n");
    return 0;
}
