//
//  main.c
//  condition-math
//
//  Created by Ibrahima BA on 18/04/2024.
//

/*if (condition) {
   Ligne A1 ;
Ligne A2 ;
} else {
   Ligne B1;
   Ligne B2;
   }*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int
main ()
{
  float a, b;

  printf ("Saisir un nombre positif : ");
  scanf ("%f", &a);

  if (a >= 0)
    {

      b = sqrt (a);

      printf ("Racine carre de %f vaut: %f\n",a, b);
    }
  else {
    printf ("calcul impossible\n");
 }

return 0;
}

