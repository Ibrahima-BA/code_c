//
//  main.c
//  phraseSansECopilot
//
//  Created by Ibrahima BA on 19/06/2024.
//

#include <stdio.h>
#include <string.h>

int main() {
    
    char phrase[] = "Ceci est un exemple de phrase sans la lettre e.\n";

    //printf("Ceci est un exemple de phrase avec la lettre e.\n");
    //printf("\n");
    
    int longueur = strlen(phrase);

    for (int i = 0; i < longueur; i++) {
        if (phrase[i] != 'e' && phrase[i] != 'E') {
            printf("%c", phrase[i]);
        }
    }
    printf ("Fin du programme\n");
    return 0;
}
