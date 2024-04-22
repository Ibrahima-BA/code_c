//
//  main.c
//  Somme d'argent
//
//  Created by Ibrahima BA on 18/04/2024.
//

#include <stdio.h>

int main(void)
{
int nb500, /* correspond à la constante du nombres de billets de 500 */
nb200,/* correspond à la constante du nombres de billets de 200 */
nb100,
nb50,
nb20,
nb10,
nb5,
np2,/* correspond à la constante du nombres de pièces de 2 */
np1,
argent;/* c'est la constante dans laquel on enregistrera la somme entré par l'utilisateur */

printf("Veuillez entrer la somme d'argent\n");
scanf("%d", &argent);

nb500 = argent/500;
argent = argent%500;
    
nb200 = argent/200;
argent = argent%200;
    
nb100 = argent/100;
argent = argent%100;
    
nb50 = argent/50;
argent = argent%50;
    
nb20 = argent/20;
argent = argent%20;
    
nb10 = argent/10;
argent = argent%10;
    
nb5 = argent/5;
argent = argent%5;
    
np2 = argent/2;
argent = argent%2;
    
np1 = argent;

printf("Il faut %d billet(s) de 500 EUR\n", nb500);
printf("Il faut %d billet(s) de 200 EUR\n", nb200);
printf("Il faut %d billet(s) de 100 EUR\n", nb100);
printf("Il faut %d billet(s) de 50 EUR\n", nb50);
printf("Il faut %d billet(s) de 20 EUR\n", nb20);
printf("Il faut %d billet(s) de 10 EUR\n", nb10);
printf("Il faut %d billet(s) de 5 EUR\n", nb5);
printf("Il faut %d piece(s) de 2 EUR\n", np2);
printf("Il faut %d piece(s) de 1 EUR\n", np1);

//system ("pause");
    
return 0;
}
