//
//  main.c
//  structureEtPointeurEnC
//
//  Created by Ibrahima BA on 19/06/2024.
//

#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

// Définition de la structure "Personne"
struct Personne {
    char nom[50];
    int age;
};

int main() {
    // Création d'une instance de la structure "Personne"
    struct Personne p1;

    // Utilisation du pointeur pour accéder aux membres de la structure
    struct Personne *ptr_p1 = &p1;

    // Saisie des informations
    printf("Saisir le nom : ");
    scanf("%s", ptr_p1->nom);

    printf("Saisir l'âge : ");
    scanf("%d", &(ptr_p1->age));

    // Affichage des informations
    printf("Nom : %s\n", ptr_p1->nom);
    printf("Âge : %d\n", ptr_p1->age);

    // Allocation dynamique d'une autre personne
    struct Personne *ptr_p2 = (struct Personne *)malloc(sizeof(struct Personne));
    if (ptr_p2 != NULL) {
        printf("Saisir le nom de la deuxième personne : ");
        scanf("%s", ptr_p2->nom);

        printf("Saisir l'âge de la deuxième personne : ");
        scanf("%d", &(ptr_p2->age));

        printf("Deuxième personne :\n");
        printf("Nom : %s\n", ptr_p2->nom);
        printf("Âge : %d\n", ptr_p2->age);

        // Libération de la mémoire allouée dynamiquement
        free(ptr_p2);
    } else {
        printf("Erreur lors de l'allocation mémoire.\n");
    }

    return 0;
}

