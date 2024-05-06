//
//  main.c
//  pointeur-suite
//
//  Created by Ibrahima Ba on 29/04/2024.
//

#include <stdio.h>

int main(void) {
    int * n;
    int c;
    n = 0;
    printf("Hello, World! N = %d \n",n);
    c = 10;
    n =& c;
    printf("Hello, World! N en = %s \n",n);
    return 0;
}

