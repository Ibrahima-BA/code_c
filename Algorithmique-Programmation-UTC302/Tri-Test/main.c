//
//  main.c
//  Tri-Test
//
//  Created by Ibrahima Ba on 23/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


void affiche(int tab[]){
for (int i = 0; i < SIZE; i++) {
printf("%d\n",tab[i]);
}
printf("\n");
}


// Fonction pour trier le tableau avec l'algorithme de tri à bulles
void trie(int tab[]) {
int temp; // Variable temporaire pour l'échange
for (int i = 0; i < SIZE - 1; i++) {
for (int j = 0; j < SIZE - i - 1; j++) {
// Si l'élément actuel est plus grand que le suivant, échanger les deux
if (tab[j] > tab[j + 1]) {
temp = tab[j];
tab[j] = tab[j + 1];
tab[j + 1] = temp;
}
}
}
}

   void verif(int tab[]){
}

int main(void)
{
    int tab [SIZE];
    int tab2 [SIZE];
    int tab3 [SIZE];
    
    int i;
        for (i=0; i < SIZE; ++i)
        {
        int random = rand();
        tab[i] = random;
        tab2[i] = random;
        tab3[i] = random;
        
}
    tab[i] = rand();
        trie(tab);
        
        trie(tab2);
        
        trie(tab3);
        
        //verif(tab);
    affiche(tab);
    printf("\n");
    affiche(tab2);
    printf("\n");
    affiche(tab3);
    
}

