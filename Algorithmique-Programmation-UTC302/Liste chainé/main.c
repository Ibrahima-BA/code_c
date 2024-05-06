//
//  main.c
//  Liste chainé
//
//  Created by Ibrahima BA on 25/04/2024.
//

#include <stdio.h>
#include <stdlib.h>

enum Couleur {Piques,Careaux, Coeurs,Trefles};

struct carte
{
    int valeur;
    enum Couleur couleur;
    char couleur [50];
    //char valeurs [50];
    
    struct carte* // pointeurs pour créer un nouvel élément
    
};
int main(void) {
    
    typedef struct carte carte;

    struct carte C1;
    C1.valeurs = {As,2,3};
    
    //struct.carte C1.couleur = {"caro"};
    enum couleur n = Careaux;
    printf("n = %d.\n", (int)n);

    // Malloc => allocation de mémoire
    // Sizeof => taille de l'élément
    //free : fonction pour libérer de la mémoire

    return 0;
}
