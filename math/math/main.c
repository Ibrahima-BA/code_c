//
//  main.c
//  math
//
//  Created by Ibrahima BA on 18/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void mult2(int *Ptx,int fact);

void AfficheTab (float Tab[], int Size);

int main()
{
    
    int a , b ;

    printf("saisissez un nombre");
    
    scanf("%d", &a);

    mult2(&a,3);

    printf("a = %d",a);
    
    return 0;
}
void mult2(int * Ptx, int fact)

//Ptx : Manipulation du contenue de ceux qui a l'adresse Ptx
{
    
*Ptx=fact* *Ptx;


void AfficheTab (float Tab[], int Size){
int cb;
for (cb=0; cb<Size ; cb++)printf ("%d\t", Tab[cb]);
return ;
}
}
