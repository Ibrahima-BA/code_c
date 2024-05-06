//
//  main.c
//  c_for
//
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <stdio.h>
#include<string.h> // librairie pour 'strlen'
#include<ctype.h> // librairie pour 'toupper'

int main(void)
{
    char line [100];
    printf("Veuillez écrire une phrase: \n\r");
    gets(line);
    
   //char* line = "H  e  \tl\tlo World\0";
   int space = 0;
   int tab = 0;
   int ret = 0;
   int i;
   unsigned long max = strlen(line);
   for (i = 0; i < max; i++ )
   {
      if ( line[i] == ' ' )
      {
          space++;
      }
      if ( line[i] == '\t' )
      { 
          tab++;
      }
       if (tolower(line[i]) == 'e' )  // fonction pour convertir les majuscules en minuscule (sinon toloper)

       {
           ret++;
       }
   }

   printf("Nombre d'espace: %i\n", space);
   printf("Nombre de tabulation: %i\n", tab);
    printf("Nombre de e: %i\n", ret);
   return 0;
}
