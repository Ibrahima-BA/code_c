//
//  main.c
//  case
//
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <stdio.h>

int main (void)
{
  int n;
  printf ("Veuillez saisir un entier : ");
  scanf ("%d", &n);

  switch (n)
    {
    case 0:
      printf (" Zero\n ");
      break;
    case 1:
      printf (" Un\n ");
      break;
    case 2:
      printf (" Deux\n ");
      break;
    case 3:
      printf (" Trois\n ");
      break;
    case 4:
      printf (" Quatre\n ");
      break;
    case 5:
      printf (" Cinq\n ");
      break;
     case 6:
       printf (" Six\n ");
      break;
     case 7:
      printf (" Sept\n ");
      break;
     case 8:
      printf (" Huit\n ");
      break;
    case 9:
     printf (" Neuf\n ");
    break;
    case 10:
     printf (" Dix\n");
    break;
    default:
    printf ("\n");
    printf (" Trop grand\n");
    }
  printf ("Fin du programme\n ");
}
