//
//  main.c
//  phraseSansE
//
//  Created by Ibrahima BA on 19/06/2024.
//

#include <stdio.h>
#include <string.h> // Librairie pour l'utilisation de strlen

int main()
{
    char maphrase[200];
    char maphrasesansE[200];
    int i =0 ;
    int j = 0;
    
    printf("Quelle est votre phrase ?\n");
    gets(maphrase); // cette ligne remplace fgets
    
    //fgets(maphrase, 200, stdin); //Nous utilisons fgets pour saisir la phrase (afin d’éviter les problèmes de débordement de tampon).
    //maphrase[strcspn(maphrase, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
    
    printf("Votre phrase est : %s\n", maphrase);
    
    //for (i=0; maphrase[i] != '\0'; i++) {
    for (i = 0; i < strlen(maphrase); i++) { //Nous utilisons strlen pour calculer la longueur de la phrase.
        if (maphrase[i]!= 'e' && maphrase[i] != 'E') {
            maphrasesansE[j] = maphrase[i];
            j++;
        }
    }
    maphrasesansE[j]= '\0';
    printf("La phrase sans e est: %s\n",maphrasesansE); // Exemple de phrase : Ereka je m'appelle Ibrahima Ba sans E-e
    printf ("Fin du programme\n");
    return 0;
}
