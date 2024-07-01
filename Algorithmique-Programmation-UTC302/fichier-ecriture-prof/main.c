//
//  main.c
//  fichier-ecriture-prof
//
//  Created by Ibrahima Ba on 30/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define FILE_NAME "/Users/ibrahimaba/Documents/GitHub/code_c/Algorithmique-Programmation-UTC302/fichier-ecriture-prof/output.txt"

int main(void) {
    char buffer[BUFFER_SIZE];
    printf("Saisir des donnees 1: ");
    //scanf("%s", buffer);
    fgets(buffer, sizeof(buffer), stdin);
    while (buffer[0] != '1')
    {
        // Ouvrir le fichier en mode append
        FILE *file = fopen(FILE_NAME, "a");
        
        // Écrire la ligne dans le fichier
        fprintf(file, "%s", buffer);

        // Fermer le fichier
        fclose(file);
        
        printf("Saisir des donnees 2: ");
        fgets(buffer, sizeof(buffer), stdin);
    }

    return 0;
}
