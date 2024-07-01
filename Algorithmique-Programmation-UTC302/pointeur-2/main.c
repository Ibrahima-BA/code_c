//
//  main.c
//  pointeur2
//
//  Created by Ibrahima BA on 18/04/2024.
//

/* Import des librairies */
#include <stdio.h>
//#include <math.h>

void mult2(int *Ptx,int fact);

void AfficheTab (float Tab[], int size);

int main(void)
{
    int a;
    
    printf("saisissez un nombre");
    
    scanf("%d", &a);
    
    mult2(&a,3);
    
    printf("a = %d",a);
    
    return 0;
    
    void mult2(int * Ptx, int fact);
    //Ptx : Manipulation du contenue de ceux qui a l'adresse Ptx
    {
        int * Ptx;
        int fact;
        *Ptx=fact* *Ptx;
    }
        
        void AfficheTab (float Tab[], int size);
        {
            int cb;
            int Size;
            float Tab[cb];
            for (cb=0; cb < Size ; cb++)printf ("%f\t", Tab[cb]);
            return a ;
        }
    }

