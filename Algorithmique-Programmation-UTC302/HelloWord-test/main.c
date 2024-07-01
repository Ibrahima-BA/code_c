//
//  main.c
//  HelloWord-test
//
//  Created by Ibrahima BA on 23/04/2024.
//

#include <stdio.h>

void Helloworld(int n)
{
    for(int i = 0; i<n; i++){
        if (n<=10)
        printf("J'aime le language C en 202%i !\n",i);
        else
        printf("J'aime le language C en 203%i !\n",i);
    }
}

int main()
{
    int n;
    printf("Veuillez mettre un nombre pour déterminer la répétition : \n");
    scanf("%i", &n);
    Helloworld(n);
   if (n>=11)
    printf( "Pour toujours ! \n");
    return 0;
    
}
