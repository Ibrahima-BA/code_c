//
//  main.c
//  case alphabe
//
//  Created by Ibrahima Ba on 22/04/2024.
//
#include <stdio.h>
#include <ctype.h> // librairie pour toupper

int main (void)
{
  char n;
    
  printf ("Veuillez saisir un lettre :\n");
  scanf (" %c", &n);
    n = toupper(n); // pour mettre les minuscules à majuscules (sinon utliser tolower)
  switch (n)
    {
    case 'a':
      printf ("1ére lettre de l'alphabet\n ");
     break;
        case 'A':
          printf ("1ére lettre de l'alphabet\n ");
         break;
    case 'b' & 'B':
     printf (" 2ème lettre de l'alphabet\n ");
      break;
    case 'c' & 'C':
     printf (" 3ème lettre de l'alphabet\n ");
      break;
    case 'd' & 'D':
     printf (" 4ème lettre de l'alphabet\n ");
      break;
    case 'e' & 'E':
            printf (" 5ème lettre de l'alphabet\n ");
      break;
     case 'f' & 'F':
            printf (" 6ème lettre de l'alphabet\n ");
      break;
     case 'g' & 'G':
            printf (" 7ème lettre de l'alphabet\n ");
      break;
     case 'h'& 'H':
            printf (" 8ème lettre de l'alphabet\n ");
      break;
    case 'i'& 'I':
            printf (" 9ème lettre de l'alphabet\n ");
    break;
    case 'j' & 'J':
        printf (" 10ème lettre de l'alphabet\n ");
    break;
    default:
    printf ("\n");
    printf (" Lettre trop grande\n");
    return main();
    }
  printf ("Fin du programme\n ");
    return 0;
}
