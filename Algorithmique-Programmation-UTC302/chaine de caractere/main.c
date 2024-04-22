//
//  main.c
//  chaine de caractere
// https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4283_les-chaines-de-caracteres/
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <stdio.h>
int main(void)
{
    char chaine[100] = "Bonjour";

    printf("%s\n", chaine);
    chaine[0] = 'A';
    chaine[1] = 'u';
    chaine[2] = ' ';
    chaine[3] = 'r';
    chaine[4] = 'e';
    chaine[5] = 'v';
    chaine[6] = 'o';
    chaine[7] = 'i';
    chaine[8] = 'r';
    chaine[9] = ' ';
    chaine[10] = 'I';
    chaine[11] = 'b';
    chaine[12] = 'r';
    chaine[13] = 'a';
    chaine[14] = 'h';
    chaine[15] = 'i';
    chaine[16] = 'm';
    chaine[17] = 'a';
    chaine[18] = ' ';
    chaine[19] = 'B';
    chaine[20] = 'A';
    chaine[21] = '\0'; /* N'oubliez pas le caractère nul ! */
    printf("%s\n", chaine);
    printf ("Fin du programme\n");
    return 0;
}
