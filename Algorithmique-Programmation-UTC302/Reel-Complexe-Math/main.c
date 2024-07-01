//
//  main.c
//  Reel-Complexe-Math
//
//  Created by Ibrahima Ba on 22/04/2024.
//

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    double complex x = 301*I +40- 2*I;
    double complex y = 2 - 3*I;

    double complex z = x + y;;

    printf("z = %.1f%+.1fi\n", creal(z), cimag(z));

    return EXIT_SUCCESS;
}
