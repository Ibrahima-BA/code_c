//
//  main.c
//  Structure exercice 4
//
//  Created by Ibrahima Ba on 06/05/2024.
//

#include <stdio.h>
#include <stdlib.h>

enum Couleur { PIQUE, TREFLE, CARRO, COEUR };

struct Carte {
    int valeur;
    enum Couleur couleur;
    struct Carte *p_suivant;
};

struct Carte *CreerCarte(int v, enum Couleur c) {
    struct Carte *element = malloc(sizeof(struct Carte));
    element->valeur = v;
    element->couleur = c;
    element->p_suivant = NULL;
    return element;
}

void AjouterDebut(struct Carte **p_tete, struct Carte *nouvelle_carte) {
    nouvelle_carte->p_suivant = *p_tete;
    *p_tete = nouvelle_carte;
}

void AjouterFin(struct Carte **p_tete, struct Carte *nouvelle_carte) {
    struct Carte *curseur = *p_tete;
    if (curseur == NULL) {
        *p_tete = nouvelle_carte;
    } else {
        while (curseur->p_suivant != NULL) {
            curseur = curseur->p_suivant;
        }
        curseur->p_suivant = nouvelle_carte;
    }
}

void SupprimerDernier(struct Carte **p_tete) {
    if (*p_tete == NULL) return;
    if ((*p_tete)->p_suivant == NULL) {
        free(*p_tete);
        *p_tete = NULL;
    } else {
        struct Carte *curseur = *p_tete;
        while (curseur->p_suivant->p_suivant != NULL) {
            curseur = curseur->p_suivant;
        }
        free(curseur->p_suivant);
        curseur->p_suivant = NULL;
    }
}

void SupprimerCarte(struct Carte **p_tete, int val, enum Couleur col) {
    struct Carte *curseur = *p_tete, *precedent = NULL;
    while (curseur != NULL) {
        if (curseur->valeur == val && curseur->couleur == col) {
            if (precedent == NULL) {
                *p_tete = curseur->p_suivant;
            } else {
                precedent->p_suivant = curseur->p_suivant;
            }
            free(curseur);
            return;
        }
        precedent = curseur;
        curseur = curseur->p_suivant;
    }
}

void AfficherListe(struct Carte *tete) {
    struct Carte *curseur = tete;
    while (curseur != NULL) {
        printf("%d de ", curseur->valeur);
        switch (curseur->couleur) {
            case PIQUE: printf("Pique"); break;
            case TREFLE: printf("Trèfle"); break;
            case CARRO: printf("Carreau"); break;
            case COEUR: printf("Coeur"); break;
        }
        if (curseur->p_suivant != NULL) {
            printf(" -> ");
        }
        curseur = curseur->p_suivant;
    }
    printf("\n");
}

int main(void) {
    struct Carte *p_tete = NULL;

    // Ajout de cartes
    AjouterDebut(&p_tete, CreerCarte(10, PIQUE));
    AjouterDebut(&p_tete, CreerCarte(3, COEUR));
    AjouterFin(&p_tete, CreerCarte(7, CARRO));
    AjouterFin(&p_tete, CreerCarte(4, TREFLE));

    printf("Liste après ajout de cartes :\n");
    AfficherListe(p_tete);

    // Suppression de la dernière carte
    SupprimerDernier(&p_tete);
    printf("Liste après suppression de la dernière carte :\n");
    AfficherListe(p_tete);

    // Suppression d'une carte spécifique
    SupprimerCarte(&p_tete, 3, COEUR);
    printf("Liste après suppression de la carte 3 de Coeur :\n");
    AfficherListe(p_tete);

    return 0;
}