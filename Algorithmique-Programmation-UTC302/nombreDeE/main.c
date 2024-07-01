//
//  main.c
//  nombreDeE
//
//  Created by Ibrahima BA on 19/06/2024.
//

#include <stdio.h>
int main()
{
char maphrase[200];
    int nombrede_e = 0;
    int i;

printf("Quelle est votre phrase ?\n");
gets(maphrase);

printf("Votre phrase est : %s\n", maphrase);

for (i=0; maphrase[i]!='\0'; i++){
    if (maphrase[i]=='e'|| maphrase[i]=='E'){
        nombrede_e ++;
    }
}
printf("Le nombre de e dans ma phrase est : %d\n",nombrede_e);
//strcat( nombrede_e, "e" );
    printf ("Fin du programme\n");
    return 0;
}
