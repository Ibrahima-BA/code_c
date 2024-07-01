//
//  main.c
//  for
//
//  Created by Ibrahima BA on 27/06/2024.
//
#include<stdio.h>
#include<string.h>
int main()
{
    int x = 0;
    int y = 0;
    char chaine[100] ;
    char chain[100] ;
    printf("donnez-moi un mot ou une phrase...\n");
    gets(chaine);


    while( x < strlen(chaine))
    {
        if(chaine[x]!='e')
        {
            chain[y]=chaine[x];
            y++;
        }
        x++;
    }
    chain[y]='\0';
    printf("%s\n", chain);


}
