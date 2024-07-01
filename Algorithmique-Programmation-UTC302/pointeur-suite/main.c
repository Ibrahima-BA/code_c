//
//  main.c
//  pointeur-suite
//
//  Created by Ibrahima Ba on 29/04/2024.
//

#include <stdio.h>

int main(void) {
    int * n;
    int c = 10;
    n = &c; // Assign the address of 'c' to 'n'
    
    printf("Hello, World! N = %d \n",*n);
    c = 11;
    printf("Hello, World! N en = %d\n",*n);
    return 0;
}

