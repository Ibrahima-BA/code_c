//
//  main.c
//  listeChaine
//
//  Created by Ibrahima BA on 25/06/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour un élément de la liste chaînée
struct Element {
    int valeur;
    char chaine[50];
    struct Element* precedent;
    struct Element* suivant;
};

// Fonction pour créer un nouvel élément
struct Element* creerElement(int valeur, const char* chaine) {
    struct Element* nouvelElement = (struct Element*)malloc(sizeof(struct Element));
    nouvelElement->valeur = valeur;
    strcpy(nouvelElement->chaine, chaine);
    nouvelElement->precedent = NULL;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}

int main(void) {
    // Création d'éléments
    struct Element* premier = creerElement(10, "Premier élément");
    struct Element* deuxieme = creerElement(20, "Deuxième élément");
    struct Element* troisieme = creerElement(30, "Troisième élément");

    // Liaisons entre les éléments
    premier->suivant = deuxieme;
    deuxieme->precedent = premier;
    deuxieme->suivant = troisieme;
    troisieme->precedent = deuxieme;

    // Affichage des éléments
    struct Element* courant = premier;
    while (courant != NULL) {
        printf("Valeur : %d, Chaîne : %s\n", courant->valeur, courant->chaine);
        courant = courant->suivant;
    }

    // Libération de la mémoire
    free(premier);
    free(deuxieme);
    free(troisieme);
    
    printf("Fin du programme\n");
    return 0;
}
