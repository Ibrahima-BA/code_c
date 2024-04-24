//
//  main.c
//  Algorithmique-Programmation-UTC302
//
// Créer par Ibrahima Ba le 22/04/2024.
// Modifier par Ibrahima Ba le 24/04/2024.

#include <stdio.h>

#define ND "\n"

void bonjour (int n)
{
    for (int i=0; i<n; i++) {
        printf("J'aime le language C en 200%i !\n",i);

    }
    printf("Pour le moment ! \n");
}

void bonjour2 (int n)
{
    for (int i=10; i<n; i++) {
        printf("J'aime le language C en 20%i !\n",i);
       
    }
    printf("Depuis toujours !\n");
}

int main(void) {
    int n;
    printf("Veuillez mettre un nombre pour déterminer la répétition : \n");
    scanf("%i", &n);
    if (n<=10)
    bonjour(n);
    else
    bonjour2(n);
    //printf ("Fin du programme\n");
    return 0;
}
