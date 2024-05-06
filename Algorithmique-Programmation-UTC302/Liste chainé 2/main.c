//
//  main.c
//  Liste chainé 2
//
//  Created by Ibrahima BA on 25/04/2024.
//

#include <stdio.h>

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    printf("Coordonnees : %d octets\n", sizeof(Coordonnees));

    return 0;
}
