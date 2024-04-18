/******************************************************************************
 //
 //  main.c
 //  Chaine de caractére
Calculer la TVA de 20% sur un prix et afficher le prix TTC

Ce programe permet de calculer la TVA à 20% à partir d'un prix
 //  Created by Ibrahima BA on 18/04/2024.
*******************************************************************************/
#include <stdio.h>
float a;
float b;


int main()
{
    printf("Veuillez saisir un prix :\n");
    scanf("%f", &a);
    b=a+(a*0.2);
    printf("Le prix calculé avec la TVA à 20 pour cents : %f euros  \n",b);
    
    return 0;
}
