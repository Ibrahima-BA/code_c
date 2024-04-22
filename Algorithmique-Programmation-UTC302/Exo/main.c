#include <stdio.h>

int main(void)
{
    char str[11];
    int a;
    
    printf("saisir une chaine de 10 caracteres max");
    scanf("%c", & str[11]);
    
    printf("la chaine saisie est %s", str);
    
    printf("saisir numero du caractere\n");
    scanf("%d", &a);
    
    /* printf("le caractere est %c", str[a-1]); */
    
    printf("le caractere en position %d est : %c\n", a, str[a-1]);
    return 0;
}
