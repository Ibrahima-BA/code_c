//
//  main.c
//  structure exercice 2
//
//  Created by Ibrahima Ba on 24/04/2024.
//
#include <stdio.h>

struct point
{
    int num;
    float x;
    float y;
}
//typedef struct point course; //c'est un alias

int main(void) {
    struct point A;
    //course A;
    printf("Donner les identifiants de la course :\n");
    scanf("%d", &A.num);
   
    printf("Donner le prix de la course sans la TVA :\n");
    scanf("%f", &A.x);
    
    printf("Donner le prix de la course avec la TVA :\n");
    scanf ("%f", &A.y);
    
    printf("\n");
    printf("Les informations de la course sont les suivantes :\n");
    printf("L'Identifiant est %d ; \nLe prix sans la TVA est %.2f euros; \nLe prix avec la TVA est %.2f euros \n",A.num,A.x, A.y);
    printf("\n");
    printf("La différence avec et sans TVA et de %.2f euros \n", A.y - A.x);
    
    return 0;
}


