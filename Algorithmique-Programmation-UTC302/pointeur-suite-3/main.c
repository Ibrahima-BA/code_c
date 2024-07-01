//
//  main.c
//  pointeur-suite-3
//
//  Created by Ibrahima Ba on 16/05/2024.
// Ce programme prends les valeurs du tableau de A à E

#include <stdio.h>

int main(void) {
    char arr[5]= {'A','B','C','D','E'};
    char *p = arr;

    for (int i = 0; i < 5; i++) {
        printf("Valeur de arr[%d] = %c\n", i, *(p + i));// %d c'est pour afficher le contenu de i et %c c'est pour afficher le contenu de p+i
    }

    return 0;
}
