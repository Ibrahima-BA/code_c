//
//  main.c
//  division-fonction
//
//  Created by Ibrahima BA on 18/04/2024.
//

#include <stdio.h>

/** float Divide (int a, int b); **/

void Divide (int a, int b, int *Ptr, int * Ptq);

int main(void)
{
    int a, b;
    int quotient, reste;
    
    printf("Saisir deux nombres entier a et b\n");
    scanf("%d%d", &a, &b);

    while (b==0){
        
        printf("Le diviseur est égal a 0 - Saisir un nouveau diviseur\n");
        scanf("%d",&b);
    }
    Divide (a,b, &reste,&quotient);
    
    printf ("Le quotient vaut %d et le reste vaut %d\n",quotient, reste);
   
    return 0;
}

void Divide (int a, int b, int *Ptr, int * Ptq){
    
    *Ptq = a/b ;
    *Ptr = a%b ;
    
    return ;
}
