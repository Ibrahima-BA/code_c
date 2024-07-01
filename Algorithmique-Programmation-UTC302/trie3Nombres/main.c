//
//  main.c
//  trie3Nombres
//
//  Created by Ibrahima BA on 19/06/2024.
//
#include <stdio.h>
int main() {
    int a;
    int b;
    int c;
    
printf("Veuillez saisir trois nombres séparés par des espaces :\n");
    
scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);

int temp;
    
    if (a > b) {
    temp = a;
    a=b;
    b=temp;
    }

    if (a > c) {
    temp = a;
    a=c;
    c=temp;
    }
    
    if (b > c) {
    temp = b;
    b=c;
    c=temp;
    }
    
printf("Les nombres triés dans l'ordre croissant sont :\n");
printf("%d\n", a);
printf("%d\n", b);
printf("%d\n", c);
    
return 0;
}
