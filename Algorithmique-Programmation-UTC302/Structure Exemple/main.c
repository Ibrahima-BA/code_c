//
//  main.c
//  Structure Exemple
//
//  Created by Ibrahima Ba on 22/04/2024.
//  Modifié le 26 September 2025 - Ajout d'un exemple complet
//

#include <stdio.h>
#include <string.h>

// Définition de la structure
struct exemple {
    int identifiant;
    int qualite;
    float prix;
    char nom[50];
};

// Fonction pour afficher un exemple
void afficher_exemple(struct exemple item) {
    printf("=== Informations de l'article ===\n");
    printf("Identifiant: %d\n", item.identifiant);
    printf("Nom: %s\n", item.nom);
    printf("Qualité: %d/10\n", item.qualite);
    printf("Prix: %.2f €\n", item.prix);
    printf("================================\n");
}

// Fonction pour initialiser un exemple
struct exemple creer_exemple(int id, const char* nom, int qualite, float prix) {
    struct exemple nouvel_item;
    
    nouvel_item.identifiant = id;
    nouvel_item.qualite = qualite;
    nouvel_item.prix = prix;
    
    // Copie sécurisée du nom
    strncpy(nouvel_item.nom, nom, sizeof(nouvel_item.nom) - 1);
    nouvel_item.nom[sizeof(nouvel_item.nom) - 1] = '\0';
    
    return nouvel_item;
}

int main(void) {
    printf("=== Démonstration des structures en C ===\n\n");
    
    // Méthode 1: Initialisation directe
    struct exemple article1;
    article1.identifiant = 1001;
    article1.qualite = 8;
    article1.prix = 29.99f;
    strcpy(article1.nom, "Livre C Programming");
    
    printf("Article 1 (initialisation directe):\n");
    afficher_exemple(article1);
    printf("\n");
    
    // Méthode 2: Initialisation lors de la déclaration
    struct exemple article2 = {
        .identifiant = 1002,
        .qualite = 9,
        .prix = 45.50f,
        .nom = "Clavier mécanique"
    };
    
    printf("Article 2 (initialisation lors de la déclaration):\n");
    afficher_exemple(article2);
    printf("\n");
    
    // Méthode 3: Utilisation d'une fonction
    struct exemple article3 = creer_exemple(1003, "Écran 24 pouces", 7, 189.99f);
    
    printf("Article 3 (création via fonction):\n");
    afficher_exemple(article3);
    printf("\n");
    
    // Démonstration de modification
    printf("=== Modification de l'article 1 ===\n");
    article1.prix = 24.99f;  // Réduction de prix
    article1.qualite = 9;    // Amélioration qualité
    
    printf("Article 1 après modification:\n");
    afficher_exemple(article1);
    printf("\n");
    
    // Comparaison de prix
    printf("=== Comparaison des prix ===\n");
    if (article1.prix < article2.prix) {
        printf("L'article 1 (%s) est moins cher que l'article 2 (%s)\n", 
               article1.nom, article2.nom);
    } else {
        printf("L'article 2 (%s) est moins cher que l'article 1 (%s)\n", 
               article2.nom, article1.nom);
    }
    
    // Calcul du prix moyen
    float prix_moyen = (article1.prix + article2.prix + article3.prix) / 3.0f;
    printf("Prix moyen des articles: %.2f €\n", prix_moyen);
    
    printf("\nProgramme terminé avec succès.\n");
    return 0;
}
