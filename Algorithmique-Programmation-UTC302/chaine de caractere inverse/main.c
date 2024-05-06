//
//  main.c
//  chaine de caractere inverse
//
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <stdio.h>
#include<string.h>

void inversion(char *p_str_1)
{
    unsigned long long_str = strlen(p_str_1);  // Fonction strlen qui retourne un unsigned long
    unsigned long  cpt = long_str / 2 ; // on divise par deux la longueur de la chaine
    char *p_str_2 = p_str_1 + long_str -1 ; // init sur la fin de chaine
    char tmp;
    while(cpt > 0)
    {
        tmp = *p_str_1; // sauv. cara
        *p_str_1 = *p_str_2; // début échange d'un cara
        *p_str_2 = tmp; // fin échange du cara
        
        // gestion des pointeurs :
        p_str_1++;
        p_str_2--;
        cpt--;
        //printf(" on est là \n\r");
    }
    }

int main(void)
{
    char texte [255];
    printf("Entrer une phrase:\n\r");
    gets(texte);
    printf("La chaine de caractère du début était: %s\n\r", texte);
    inversion(texte);
    printf("La chaine de caractère inversée est: %s\n\r", texte);
    return 0;
}
