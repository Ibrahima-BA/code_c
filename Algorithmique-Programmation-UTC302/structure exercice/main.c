//
//  main.c
//  structure exercice
//
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <stdio.h>
    
    struct point
    {
        int id;
        float prix;
        char provenance [50];
        
    };
typedef struct point point;
int main(void) {
    point FR1, FR2,FR3 = {11, 12.3, "Sénégal"};
    
    printf("Donner les infos de de FR1 : \n");
    printf("L'ID : ");
    scanf("%d", &FR1.id);
    
    printf("Le prix : ");
    scanf("%f", &FR1.prix);
    //gets(FR1.prix);
    
    printf("La provenance : ");
    scanf("%s",FR1.provenance);
    //gets(FR1.provenance);
    
    FR2 =FR3;
    
    printf("Les infos de FR1 sont les suivantes : \n");
    printf("L'Identifiant est %d ; Le prix est %.2f ; La provenance est %s \n",FR1.id, FR1.prix,FR1.provenance);
    printf("\n");
    printf("Les infos de FR2 sont les suivantes : \n");
    printf("L'Identifiant est %d ; Le prix est %.2f ; La provenance est %s \n",FR2.id, FR2.prix,FR2.provenance );
    printf("\n");
    printf("Les infos de FR3 sont les suivantes : \n");
    printf("L'Identifiant est %d ; Le prix est %.2f ; La provenance est %s \n",FR3.id, FR3.prix,FR3.provenance );
    printf("Fin du programme\n");
    return 0;
}
