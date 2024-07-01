//
//  main.c
//  trierLesElementsDunTableau
//
//  Created by Ibrahima BA on 25/06/2024.
//

#include <stdio.h>
#include <stdlib.h>

void triBulle(int tab[], int taille) {
    int i;
    int j;
    int tmp;
    
    for (i = 0; i < taille -  1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                // Échange les éléments
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}
int main(void)
{
    int tab[]= {100,4, 5,11,55,88,14,18};
    int taille = sizeof (tab) / sizeof (tab [0]);
    printf("Avant le tri du tableau : \n");
    for (int i=0; i< taille;i++)
    {
        printf ("%d ",tab[i]);
    }
    printf("\n");
    printf("Aprés le tri du tableau\n");
    triBulle(tab,taille);
    
    for (int i=0; i< taille;i++)
    {
        printf ("%d ",tab[i]);
    }
    printf("\n");
    
    return 0;
}
