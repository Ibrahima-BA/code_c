//
//  main.c
//  Algorithmique-Programmation-UTC302
//
// Créer par Ibrahima Ba le 22/04/2024.
// Modifier par Ibrahima Ba le 02/04/2024.
// Ce programme fonctionne jusqu'à 77 puis çà donne des répétitions abérantes (20100)

#include <stdio.h>

void bonjour (int n)
{
    for (int i=0; i<n; i++) {
        printf("J'aime le language C en 20%i !\n",24+i);

    }
    printf("Pour le moment ! \n");
}

void bonjour2 (int n)
{
    for (int i=0; i<10; i++) {
        int Tab[] = {2024,2025, 2026, 2027, 2028,2029,2030,2031,2032,2033};
        printf("J'aime le language C en %i !\n",Tab[i]);
    }
        for (int i=10; i<n; i++) {
        printf("J'aime le language C en 20%i !\n",24+i);
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
