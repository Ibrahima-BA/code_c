//
//  main.c
//  Tri
//
//  Created by Ibrahima Ba on 23/05/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 1000

void affiche(int tab[]){
    for (int i = 0; i < SIZE; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void triInsertion(int tab[]) {
    int i;
    int j;
    int key;
    
    for (i = 1; i < SIZE; i++) {
        key = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }
}

void triSelection(int tab[]) {
    int i;
    int j;
    int tmp;
    int min_idx;
  
    for (i = 0; i < SIZE-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < SIZE; j++)
        {
            if (tab[j] < tab[min_idx]){
                min_idx = j;
            }
        }
        tmp = tab[min_idx];
        tab[min_idx] = tab[i];
        tab[i] = tmp;
    }
}

void triBulle(int tab[]) {
    int i;
    int j;
    int tmp;
    
    for (i = 0; i < SIZE -  1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                // Échange les éléments
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

void triRapide(int tab[], int first, int last) {
    int pivot;
    int    i;
    int j;
    int tmp;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last){
                i++;
            }
            while(tab[j] > tab[pivot]){
                j--;
            }
            if(i < j) {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
        
        tmp = tab[pivot];
        tab[pivot] = tab[j];
        tab[j] = tmp;
        
        triRapide(tab, first, j - 1);
        triRapide(tab, j + 1, last);
    }
}

bool verifierTri(int tab[]){
    bool tri = true;
    int i;
    for(i = 0; i<SIZE-1 && tri;i++){
        if(tab[i]>tab[i+1]){
            tri = false;
            printf("erreur du tri %d - %d \n", tab[i], tab[i+1]);
            printf("erreur des indices %d - %d\n", i, i+1);
        }
    }
    
    if(tri){
        printf("Tableau trie\n");
    }else{
        printf("Erreur dans le tri\n");
    }
    
    return tri;
}

int main (void)
{
    int tabBulle[SIZE];
    int tabInsert[SIZE];
    int tabSelect[SIZE];
    int tabRapide[SIZE];
    int i;
    clock_t start, finish;
    
    for (i=0; i < SIZE; ++i)
    {
        int random = rand();
        tabBulle[i] = random;
        tabInsert[i] = random;
        tabSelect[i] = random;
        tabRapide[i] = random;
    }

    start = clock();
    
    // Iici on fait le tri
    triBulle(tabBulle);
    finish = clock();
    unsigned long millis = (finish -  start) * 1000 / CLOCKS_PER_SEC;
    printf("tri bulle :");
    verifierTri(tabBulle);
    
    start = clock();
    
    // Iici on fait le tri
    triSelection(tabSelect);
    
    finish = clock();
    unsigned long millisSelection = (finish -  start) * 1000 / CLOCKS_PER_SEC;
    
    printf("tri selection :");
    verifierTri(tabSelect);
    
    start = clock();
    
    // Ici on fait le tri
    triInsertion(tabInsert);
    
    finish = clock();
    unsigned long millisInsertion = (finish -  start) * 1000 / CLOCKS_PER_SEC;
    printf("tri insertion :");
    verifierTri(tabInsert);
    
    start = clock();
    
    // Ici on fait le tri
    triRapide(tabRapide, 0, SIZE);
    
    finish = clock();
    unsigned long millisRapide = (finish -  start) * 1000 / CLOCKS_PER_SEC;
    printf("tri rapide :");
    verifierTri(tabRapide);

    
    printf( "tri bulle %ld ms\n", millis );
    printf( "tri selection %ld ms\n", millisSelection );
    printf( "tri insertion %ld ms\n", millisInsertion );
    printf( "tri rapide %ld ms\n", millisRapide );
}
