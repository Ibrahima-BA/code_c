//
//  main.c
//  case-convert_hex
//
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <stdio.h>

int main (void)
{
  char n;
  printf ("Veuillez saisir une lettre : ");
  scanf (" %c", &n);
    
    switch(n)
    {
        case 'a' :
            printf ("10\n");
           break;
        case 'b' :
            printf ("11\n");
           break;
        case 'c' :
            printf ("12\n");
           break;
        case 'd' :
            printf ("13\n");
           break;
        case 'e' :
            printf ("14\n ");
           break;
        case 'f':
            printf ("15\n");
           break;
        default:
        printf ("Lettre trop grande !\n");
            printf ("\n");
        return main();
        }
      printf ("Fin du programme\n ");
    return 0;
}
