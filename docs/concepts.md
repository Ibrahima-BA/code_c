# Référence des concepts - Programmation C

Cette référence détaille les concepts fondamentaux du langage C abordés dans ce dépôt.

## Table des matières

- [Types de données](#types-de-données)
- [Variables et constantes](#variables-et-constantes)
- [Opérateurs](#opérateurs)
- [Structures de contrôle](#structures-de-contrôle)
- [Fonctions](#fonctions)
- [Pointeurs](#pointeurs)
- [Tableaux](#tableaux)
- [Structures de données](#structures-de-données)
- [Gestion mémoire](#gestion-mémoire)
- [Préprocesseur](#préprocesseur)

## Types de données

### Types de base

| Type | Taille | Plage de valeurs | Exemple |
|------|--------|------------------|---------|
| `char` | 1 octet | -128 à 127 | `char c = 'A';` |
| `int` | 4 octets | -2^31 à 2^31-1 | `int n = 42;` |
| `float` | 4 octets | ~7 chiffres décimaux | `float f = 3.14f;` |
| `double` | 8 octets | ~15 chiffres décimaux | `double d = 3.14159;` |

### Modificateurs de type

- `unsigned` : Valeurs positives uniquement
- `signed` : Valeurs positives et négatives (défaut)
- `short` : Version courte du type
- `long` : Version longue du type

```c
unsigned int age = 25;
long long big_number = 1234567890LL;
```

## Variables et constantes

### Déclaration de variables
```c
int age;                    // Déclaration
int age = 25;              // Déclaration avec initialisation
int a = 1, b = 2, c = 3;   // Déclarations multiples
```

### Constantes
```c
#define PI 3.14159         // Constante préprocesseur
const int MAX_SIZE = 100;  // Constante typée
```

### Portée des variables
- **Globale** : Déclarée hors de toute fonction
- **Locale** : Déclarée dans une fonction
- **Statique** : Conserve sa valeur entre les appels

```c
int global_var = 10;       // Variable globale

int main() {
    int local_var = 20;    // Variable locale
    static int static_var = 30; // Variable statique
    return 0;
}
```

## Opérateurs

### Opérateurs arithmétiques
| Opérateur | Description | Exemple |
|-----------|-------------|---------|
| `+` | Addition | `a + b` |
| `-` | Soustraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` |
| `%` | Modulo | `a % b` |

### Opérateurs de comparaison
| Opérateur | Description | Exemple |
|-----------|-------------|---------|
| `==` | Égal à | `a == b` |
| `!=` | Différent de | `a != b` |
| `<` | Inférieur à | `a < b` |
| `<=` | Inférieur ou égal | `a <= b` |
| `>` | Supérieur à | `a > b` |
| `>=` | Supérieur ou égal | `a >= b` |

### Opérateurs logiques
| Opérateur | Description | Exemple |
|-----------|-------------|---------|
| `&&` | ET logique | `a && b` |
| `\|\|` | OU logique | `a \|\| b` |
| `!` | NON logique | `!a` |

## Structures de contrôle

### Instruction if/else
```c
if (condition) {
    // Code si condition vraie
} else if (autre_condition) {
    // Code si autre condition vraie
} else {
    // Code par défaut
}
```

### Instruction switch
```c
switch (variable) {
    case valeur1:
        // Code pour valeur1
        break;
    case valeur2:
        // Code pour valeur2
        break;
    default:
        // Code par défaut
        break;
}
```

### Boucles

#### Boucle for
```c
for (initialisation; condition; incrément) {
    // Code à répéter
}

// Exemple
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

#### Boucle while
```c
while (condition) {
    // Code à répéter
}

// Exemple
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}
```

#### Boucle do-while
```c
do {
    // Code à répéter au moins une fois
} while (condition);
```

## Fonctions

### Déclaration et définition
```c
// Déclaration (prototype)
int addition(int a, int b);

// Définition
int addition(int a, int b) {
    return a + b;
}

// Utilisation
int result = addition(5, 3);
```

### Passage de paramètres

#### Par valeur
```c
void modifier_valeur(int x) {
    x = 100; // Ne modifie pas la variable originale
}
```

#### Par référence (avec pointeurs)
```c
void modifier_reference(int *x) {
    *x = 100; // Modifie la variable originale
}
```

### Fonctions récursives
```c
int factorielle(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorielle(n - 1);
}
```

## Pointeurs

### Déclaration et utilisation
```c
int x = 10;
int *ptr = &x;     // ptr pointe vers x
int valeur = *ptr; // Déréférencement : valeur = 10
```

### Pointeurs de pointeurs
```c
int x = 10;
int *ptr = &x;
int **ptr_ptr = &ptr; // Pointeur vers un pointeur
```

### Arithmétique des pointeurs
```c
int tableau[5] = {1, 2, 3, 4, 5};
int *ptr = tableau;

ptr++;        // Pointe vers l'élément suivant
ptr += 2;     // Avance de 2 éléments
int diff = ptr2 - ptr1; // Différence en éléments
```

## Tableaux

### Déclaration et initialisation
```c
int tableau[5];                    // Déclaration
int tableau[5] = {1, 2, 3, 4, 5}; // Avec initialisation
int tableau[] = {1, 2, 3};        // Taille automatique
```

### Tableaux multidimensionnels
```c
int matrice[3][4];                 // Matrice 3x4
int matrice[2][3] = {{1,2,3}, {4,5,6}};
```

### Chaînes de caractères
```c
char nom[20];                      // Déclaration
char nom[] = "Bonjour";           // Initialisation
char nom[20] = "Bonjour";         // Taille fixe
```

## Structures de données

### Structures
```c
struct Personne {
    char nom[50];
    int age;
    float taille;
};

// Utilisation
struct Personne p1;
strcpy(p1.nom, "Jean");
p1.age = 25;
p1.taille = 1.75;
```

### Énumérations
```c
enum Couleur {
    ROUGE,
    VERT,
    BLEU
};

enum Couleur ma_couleur = ROUGE;
```

### Unions
```c
union Donnee {
    int entier;
    float reel;
    char caractere;
};

union Donnee d;
d.entier = 10;
```

### Typedef
```c
typedef struct {
    int x, y;
} Point;

Point p = {10, 20};
```

## Gestion mémoire

### Allocation dynamique
```c
#include <stdlib.h>

// Allocation
int *ptr = malloc(sizeof(int));
int *tableau = malloc(10 * sizeof(int));

// Réallocation
ptr = realloc(ptr, 20 * sizeof(int));

// Libération
free(ptr);
free(tableau);
```

### Fonctions de gestion mémoire
| Fonction | Description |
|----------|-------------|
| `malloc()` | Alloue de la mémoire |
| `calloc()` | Alloue et initialise à zéro |
| `realloc()` | Redimensionne un bloc mémoire |
| `free()` | Libère la mémoire |

## Préprocesseur

### Directives courantes
```c
#include <stdio.h>     // Inclusion de fichier système
#include "monheader.h" // Inclusion de fichier local

#define MAX 100        // Définition de constante
#define CARRE(x) ((x)*(x)) // Macro fonction

#ifdef DEBUG           // Compilation conditionnelle
    printf("Mode debug\n");
#endif

#ifndef HEADER_H       // Protection contre inclusion multiple
#define HEADER_H
// Contenu du header
#endif
```

## Bibliothèques standard courantes

### stdio.h
- `printf()`, `scanf()` : Entrées/sorties formatées
- `fopen()`, `fclose()` : Gestion de fichiers
- `getchar()`, `putchar()` : Caractères

### stdlib.h
- `malloc()`, `free()` : Gestion mémoire
- `rand()`, `srand()` : Nombres aléatoires
- `exit()` : Terminaison du programme

### string.h
- `strlen()` : Longueur de chaîne
- `strcpy()`, `strcat()` : Copie et concaténation
- `strcmp()` : Comparaison de chaînes

### math.h
- `sqrt()`, `pow()` : Fonctions mathématiques
- `sin()`, `cos()`, `tan()` : Fonctions trigonométriques

---

*Cette référence est un guide de consultation rapide. Consultez la documentation officielle pour plus de détails.*
