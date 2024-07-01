//
//  main.c
//  fichier
//
//  Created by Ibrahima Ba on 29/05/2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    FILE* file = fopen("/Users/ibrahimaba/Documents/GitHub/code_c/Algorithmique-Programmation-UTC302/fichier/exercice.txt", "r");
    char chaineLue[256];
    while (fgets (chaineLue, sizeof(chaineLue), file)) {
        printf("%s", chaineLue);
    }
           fclose(file); // On ferme le fichier qui a été ouvert
    return 0;
}
