//
//  main.c
//  Exo1
//
//  Created by Ibrahima BA on 18/04/2024.
//

#include <stdio.h>

int main()
{
    char str[11];
    int a;
    
    printf("saisir une chaine de 10 caracteres max\n");
    scanf("%s", str);
    
    printf("la chaine saisie est %s \n", str);
    
    printf("saisir numero du caractere\n");
    scanf("%d", &a);
    
    /* printf("le caractere est %c", str[a-1]); */
    
    printf("le caractere en position %d est %c\n", a, str[a-1]);

    return 0;
}
