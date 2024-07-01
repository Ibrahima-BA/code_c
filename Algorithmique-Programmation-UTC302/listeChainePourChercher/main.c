//
//  main.c
//  listeChainePourChercher
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

// Fonction pour afficher les détails d'un élément
void afficherElement(struct Element* element) {
    printf("Valeur : %d, Chaîne : %s\n", element->valeur, element->chaine);
}

int main(void) {
    
    int valeurRecherchee;
    char chaineRecherchee[50];
    // Création d'éléments
    struct Element* premier = creerElement(10, "Premier élément");
    struct Element* deuxieme = creerElement(20, "Deuxième élément");
    struct Element* troisieme = creerElement(30, "Troisième élément");

    
    // Utilisation du pointeur pour accéder aux membres de la structure
    struct Element* courant = premier;
    
    // Liaisons entre les éléments
    premier->suivant = deuxieme;
    deuxieme->precedent = premier;
    deuxieme->suivant = troisieme;
    troisieme->precedent = deuxieme;

    // Menu
    int choix;
    printf("Menu :\n");
    printf("1. Chercher par valeur numérique\n");
    printf("2. Chercher par chaîne de caractères\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            // Chercher par valeur numérique
            printf("Entrez la valeur numérique à rechercher : ");
            scanf("%d", &valeurRecherchee);
            // Code pour rechercher et afficher l'élément correspondant
            if (valeurRecherchee == courant->valeur)
                printf("Valeur : %d\n", courant->valeur);
            courant = courant->suivant;
            
            //if (valeurRecherchee == valeur)
                //afficherElement;
            //printf("Valeur : %d\n", element->valeur);
            
            break;
        case 2:
            // Chercher par chaîne de caractères
            printf("Entrez la chaîne de caractères à rechercher : ");
            scanf("%s", chaineRecherchee);
            // Code pour rechercher et afficher l'élément correspondant
            //printf("Valeur : %d, Chaîne : %s\n", element->valeur, element->chaine);
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }

    // Libération de la mémoire
    free(premier);
    free(deuxieme);
    free(troisieme);

    return 0;
}
