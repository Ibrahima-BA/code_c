//  main.c
//  pointeur-suite2 - Pour échange de variable
//
//  Created by Ibrahima Ba on 29/04/2024.
//
#include <stdio.h>
void echange (int * ad1, int * ad2)
{
    int tmp;
    tmp = *ad1;
    * ad1 = *ad2;
    *ad2 = tmp;
}
int main(void) {
    int n1;
    int n2;
    
    printf("Veuillez mettre le chiffre pour A puis B\n");
    scanf("%d %d", &n1,&n2);
    
    printf("Le chiffre pour A est %d puis B sait %d\n",n1,n2);
    echange (&n1,&n2);
    
    printf("Aprés échange le chiffre pour A est %d puis B sait %d\n",n1,n2);
    return 0;
}
