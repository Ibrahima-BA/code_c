//
//  main.c
//  tableauFixe
//
//  Created by Ibrahima BA on 26/06/2024.
// Mettre le temps systéme pour que la variable aléatoire soit équiprobable (afaire aprés examen)

#include <stdio.h>
#include <stdlib.h> // permet l'utilisation de la fonction rand

#define taille 10

int main(void) {
int tab [taille];
int n = 0;

    for (int i=0; i < taille; i++) {
    int random = rand() % 10 +1;
    tab [i] = random;
    printf( "%d ", tab [i]);
    n++;
}
printf("\n");
return 0;
}
