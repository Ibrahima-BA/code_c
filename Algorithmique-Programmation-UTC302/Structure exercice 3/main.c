//
//  main.c
//  Structure exercice 3
//
//  Created by Ibrahima Ba on 29/04/2024.
//

#include <stdio.h>
#include <stdlib.h> // Librairie pour l'utilisation de "malloc" et

enum Couleur{PIQUE, TREFLE, CARRO, COEUR};

struct Carte
{
    int valeur;
    enum Couleur couleur;
    struct Carte * p_suivant;
};

struct Carte * CreerCarte(int v, enum Couleur c) {
    struct Carte * element = malloc(sizeof(struct Carte));
    element->valeur = v;
    element->couleur = c;
    element->p_suivant = NULL;

    return element;
}

void AfficheListe(struct Carte* curseur) {
    while (curseur != NULL) {
        printf("%d", curseur->valeur);
        printf(" - ");
        enum Couleur couleur = curseur->couleur;
        if(curseur->couleur == PIQUE){
            printf("Pique");
        } else if(curseur->couleur == TREFLE){
            printf("Trefle");
        } else if(curseur->couleur == CARRO){
            printf("Carreau");
        } else {
            printf("Coeur");
        }
        
        if (curseur->p_suivant != NULL) {
            printf(" > ");
        }
        curseur = curseur->p_suivant;
    }
    printf("\n");
}

int main(void)
{
    struct Carte* p_tete = NULL;
    
    p_tete = CreerCarte(2, COEUR);
    p_tete->p_suivant = CreerCarte(4, TREFLE);
    p_tete->p_suivant->p_suivant = CreerCarte(7, CARRO);
    p_tete->p_suivant->p_suivant->p_suivant = CreerCarte(10, PIQUE);
    p_tete->p_suivant->p_suivant->p_suivant->p_suivant = CreerCarte(3, COEUR);
    p_tete->p_suivant->p_suivant = p_tete->p_suivant->p_suivant->p_suivant;
    AfficheListe(p_tete);
    return 0;
}
