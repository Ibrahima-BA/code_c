//
//  main.c
//  Liste chainé
//
//  Created by Ibrahima BA on 25/04/2024.
//  Modifié le 26 September 2025 - Correction des erreurs de syntaxe
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Énumération pour les couleurs de cartes
enum Couleur {PIQUES, CARREAUX, COEURS, TREFLES};

// Énumération pour les valeurs de cartes
enum Valeur {AS = 1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI};

// Structure représentant une carte
struct carte {
    enum Valeur valeur;
    enum Couleur couleur;
    char nom_couleur[20];
    struct carte* suivant;  // Pointeur vers la carte suivante dans la liste
};

// Fonction pour créer une nouvelle carte
struct carte* creer_carte(enum Valeur valeur, enum Couleur couleur) {
    struct carte* nouvelle_carte = malloc(sizeof(struct carte));
    if (nouvelle_carte == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }
    
    nouvelle_carte->valeur = valeur;
    nouvelle_carte->couleur = couleur;
    nouvelle_carte->suivant = NULL;
    
    // Définir le nom de la couleur
    switch (couleur) {
        case PIQUES:
            strcpy(nouvelle_carte->nom_couleur, "Piques");
            break;
        case CARREAUX:
            strcpy(nouvelle_carte->nom_couleur, "Carreaux");
            break;
        case COEURS:
            strcpy(nouvelle_carte->nom_couleur, "Coeurs");
            break;
        case TREFLES:
            strcpy(nouvelle_carte->nom_couleur, "Trèfles");
            break;
    }
    
    return nouvelle_carte;
}

// Fonction pour afficher une carte
void afficher_carte(struct carte* carte) {
    if (carte == NULL) {
        printf("Carte inexistante\n");
        return;
    }
    
    printf("Carte: %d de %s\n", carte->valeur, carte->nom_couleur);
}

// Fonction pour libérer la mémoire d'une liste de cartes
void liberer_liste(struct carte* tete) {
    struct carte* current = tete;
    while (current != NULL) {
        struct carte* next = current->suivant;
        free(current);
        current = next;
    }
}

int main(void) {
    printf("=== Exemple de liste chaînée de cartes ===\n");
    
    // Créer quelques cartes
    struct carte* carte1 = creer_carte(AS, PIQUES);
    struct carte* carte2 = creer_carte(ROI, COEURS);
    struct carte* carte3 = creer_carte(DAME, CARREAUX);
    
    // Vérifier que les cartes ont été créées correctement
    if (carte1 == NULL || carte2 == NULL || carte3 == NULL) {
        printf("Erreur lors de la création des cartes\n");
        return 1;
    }
    
    // Créer une liste chaînée
    carte1->suivant = carte2;
    carte2->suivant = carte3;
    
    // Afficher la liste
    printf("\nListe des cartes:\n");
    struct carte* current = carte1;
    int position = 1;
    while (current != NULL) {
        printf("%d. ", position);
        afficher_carte(current);
        current = current->suivant;
        position++;
    }
    
    // Test de l'énumération couleur
    printf("\nTest des énumérations:\n");
    enum Couleur couleur_test = CARREAUX;
    printf("Valeur de CARREAUX: %d\n", couleur_test);
    
    // Libérer la mémoire
    liberer_liste(carte1);
    
    printf("\nProgramme terminé avec succès.\n");
    return 0;
}
