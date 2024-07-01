//
//  main.c
//  fichier-ecriture
//
//  Created by Ibrahima Ba on 29/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
//#define FILE_NAME "output.txt"
#define FILE_NAME "/Users/ibrahimaba/Documents/GitHub/code_c/Algorithmique-Programmation-UTC302/fichier-ecriture/output.txt"

//char nom;
//char prenom;
//int age;
int main(void) {
    char buffer [BUFFER_SIZE];
    //printf
    //FILE *file = fopen(FILE_NAME, "a");
    
    printf("Quelle est votre nom ?\n");
    //scanf("%c\n",&nom);
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
    
    // Ouvrir le fichier en mode append
    //FILE *file = fopen(FILE_NAME, "a");
    
    // Écrire la ligne dans le fichier
    //fprintf(file, "%s", buffer);
    
    //fgets (buffer, sizeof((void)((buffer)), stdin);
           
    //fputc(nom, file); // Écriture du caractère A
    //printf("Quelle est votre prénom ?\n");
    //scanf("%c\n",&prenom);
    //fgets(buffer, sizeof(buffer), stdin);
    
    //printf("Quelle est votre age ?\n");
    //scanf("%d\n",&age);
    //fgets(buffer, sizeof(buffer), stdin);
           
    //fclose(file); // On ferme le fichier qui a été ouvert
    
    return 0;
}
