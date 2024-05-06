//
//  main.c
//  Liste chainé 3
//
//  Created by Ibrahima BA on 25/04/2024.
//

#include <stdio.h>
#include<stdlib.h> // pour l'utilisation de malloc
// Void : return rien 
int main()
{
    int* memoireAllouee = NULL;

    memoireAllouee = malloc(sizeof(int)); // Allocation de la mémoire
    if (memoireAllouee == NULL)
    {
        exit(0);
    }

    // Utilisation de la mémoire
    printf("Quel age avez-vous ? ");
    scanf("%d", memoireAllouee);
    printf("Vous avez %d ans\n", *memoireAllouee);

    free(memoireAllouee); // Libération de mémoire
    printf("Libération de la mémoire\n");
    
    printf("Vous avez %d ans\n", *memoireAllouee);

    //return 0;
}
