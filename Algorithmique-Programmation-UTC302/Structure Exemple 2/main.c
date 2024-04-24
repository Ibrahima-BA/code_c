//
//  main.c
//  Structure Exemple 2
//
//  Created by Ibrahima Ba on 22/04/2024.
//
# include <stdio.h>
struct temps {
    unsigned heures;
    unsigned minutes;
    double secondes;
};


void affiche_temps(struct temps temps)
{
printf("%d h et %d min %2.f sec\n", temps.heures, temps.minutes, temps.secondes);
}

int main(void)
{
    affiche_temps((struct temps) { .heures = 12, .minutes = 11, .secondes = 10. });
    return 0;
}
