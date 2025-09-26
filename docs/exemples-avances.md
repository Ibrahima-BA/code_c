# Exemples avancés - Programmation C

Cette section présente des exemples avancés et des techniques de programmation C qui vont au-delà des exercices de base.

## Table des matières

- [Gestion avancée des pointeurs](#gestion-avancée-des-pointeurs)
- [Structures de données complexes](#structures-de-données-complexes)
- [Allocation dynamique avancée](#allocation-dynamique-avancée)
- [Techniques d'optimisation](#techniques-doptimisation)
- [Gestion d'erreurs robuste](#gestion-derreurs-robuste)
- [Patterns de conception en C](#patterns-de-conception-en-c)

## Gestion avancée des pointeurs

### Pointeurs de fonctions

```c
#include <stdio.h>

// Définition de types de fonctions
typedef int (*operation_t)(int, int);

int addition(int a, int b) {
    return a + b;
}

int multiplication(int a, int b) {
    return a * b;
}

// Fonction qui utilise un pointeur de fonction
int calculer(int a, int b, operation_t op) {
    return op(a, b);
}

int main() {
    // Tableau de pointeurs de fonctions
    operation_t operations[] = {addition, multiplication};
    char* noms[] = {"Addition", "Multiplication"};
    
    int a = 10, b = 5;
    
    for (int i = 0; i < 2; i++) {
        int resultat = calculer(a, b, operations[i]);
        printf("%s de %d et %d = %d\n", noms[i], a, b, resultat);
    }
    
    return 0;
}
```

### Pointeurs vers pointeurs avancés

```c
#include <stdio.h>
#include <stdlib.h>

// Fonction pour modifier un pointeur via un pointeur de pointeur
void allouer_memoire(int **ptr, int taille) {
    *ptr = malloc(taille * sizeof(int));
    if (*ptr == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }
    
    // Initialiser avec des valeurs
    for (int i = 0; i < taille; i++) {
        (*ptr)[i] = i * i;
    }
}

void liberer_memoire(int **ptr) {
    if (*ptr != NULL) {
        free(*ptr);
        *ptr = NULL;  // Éviter les pointeurs pendants
    }
}

int main() {
    int *tableau = NULL;
    int taille = 5;
    
    // Allocation via pointeur de pointeur
    allouer_memoire(&tableau, taille);
    
    if (tableau != NULL) {
        printf("Tableau alloué :\n");
        for (int i = 0; i < taille; i++) {
            printf("tableau[%d] = %d\n", i, tableau[i]);
        }
        
        // Libération sécurisée
        liberer_memoire(&tableau);
        printf("Mémoire libérée, tableau = %p\n", (void*)tableau);
    }
    
    return 0;
}
```

## Structures de données complexes

### Arbre binaire de recherche

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int valeur;
    struct noeud *gauche;
    struct noeud *droite;
} noeud_t;

// Créer un nouveau nœud
noeud_t* creer_noeud(int valeur) {
    noeud_t *nouveau = malloc(sizeof(noeud_t));
    if (nouveau == NULL) return NULL;
    
    nouveau->valeur = valeur;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}

// Insérer dans l'arbre
noeud_t* inserer(noeud_t *racine, int valeur) {
    if (racine == NULL) {
        return creer_noeud(valeur);
    }
    
    if (valeur < racine->valeur) {
        racine->gauche = inserer(racine->gauche, valeur);
    } else if (valeur > racine->valeur) {
        racine->droite = inserer(racine->droite, valeur);
    }
    
    return racine;
}

// Parcours en ordre
void parcours_en_ordre(noeud_t *racine) {
    if (racine != NULL) {
        parcours_en_ordre(racine->gauche);
        printf("%d ", racine->valeur);
        parcours_en_ordre(racine->droite);
    }
}

// Rechercher une valeur
noeud_t* rechercher(noeud_t *racine, int valeur) {
    if (racine == NULL || racine->valeur == valeur) {
        return racine;
    }
    
    if (valeur < racine->valeur) {
        return rechercher(racine->gauche, valeur);
    }
    
    return rechercher(racine->droite, valeur);
}

// Libérer l'arbre
void liberer_arbre(noeud_t *racine) {
    if (racine != NULL) {
        liberer_arbre(racine->gauche);
        liberer_arbre(racine->droite);
        free(racine);
    }
}

int main() {
    noeud_t *racine = NULL;
    int valeurs[] = {50, 30, 70, 20, 40, 60, 80};
    int nb_valeurs = sizeof(valeurs) / sizeof(valeurs[0]);
    
    // Construire l'arbre
    for (int i = 0; i < nb_valeurs; i++) {
        racine = inserer(racine, valeurs[i]);
    }
    
    printf("Parcours en ordre : ");
    parcours_en_ordre(racine);
    printf("\n");
    
    // Recherche
    int cible = 40;
    noeud_t *trouve = rechercher(racine, cible);
    if (trouve != NULL) {
        printf("Valeur %d trouvée dans l'arbre\n", cible);
    } else {
        printf("Valeur %d non trouvée\n", cible);
    }
    
    liberer_arbre(racine);
    return 0;
}
```

### Table de hachage simple

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TABLE 10

typedef struct entree {
    char *cle;
    int valeur;
    struct entree *suivant;
} entree_t;

typedef struct {
    entree_t *table[TAILLE_TABLE];
} table_hachage_t;

// Fonction de hachage simple
unsigned int hacher(const char *cle) {
    unsigned int hash = 0;
    while (*cle) {
        hash = (hash * 31) + *cle;
        cle++;
    }
    return hash % TAILLE_TABLE;
}

// Initialiser la table
table_hachage_t* creer_table() {
    table_hachage_t *table = malloc(sizeof(table_hachage_t));
    if (table == NULL) return NULL;
    
    for (int i = 0; i < TAILLE_TABLE; i++) {
        table->table[i] = NULL;
    }
    
    return table;
}

// Insérer une entrée
void inserer(table_hachage_t *table, const char *cle, int valeur) {
    unsigned int index = hacher(cle);
    
    // Créer nouvelle entrée
    entree_t *nouvelle = malloc(sizeof(entree_t));
    nouvelle->cle = malloc(strlen(cle) + 1);
    strcpy(nouvelle->cle, cle);
    nouvelle->valeur = valeur;
    nouvelle->suivant = table->table[index];
    
    table->table[index] = nouvelle;
}

// Rechercher une valeur
int rechercher(table_hachage_t *table, const char *cle, int *valeur) {
    unsigned int index = hacher(cle);
    entree_t *current = table->table[index];
    
    while (current != NULL) {
        if (strcmp(current->cle, cle) == 0) {
            *valeur = current->valeur;
            return 1; // Trouvé
        }
        current = current->suivant;
    }
    
    return 0; // Non trouvé
}

// Libérer la table
void liberer_table(table_hachage_t *table) {
    for (int i = 0; i < TAILLE_TABLE; i++) {
        entree_t *current = table->table[i];
        while (current != NULL) {
            entree_t *temp = current;
            current = current->suivant;
            free(temp->cle);
            free(temp);
        }
    }
    free(table);
}

int main() {
    table_hachage_t *table = creer_table();
    
    // Insérer des données
    inserer(table, "nom", 100);
    inserer(table, "age", 25);
    inserer(table, "score", 95);
    
    // Rechercher
    int valeur;
    if (rechercher(table, "age", &valeur)) {
        printf("age = %d\n", valeur);
    }
    
    if (rechercher(table, "inexistant", &valeur)) {
        printf("inexistant = %d\n", valeur);
    } else {
        printf("Clé 'inexistant' non trouvée\n");
    }
    
    liberer_table(table);
    return 0;
}
```

## Allocation dynamique avancée

### Pool de mémoire

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct bloc {
    struct bloc *suivant;
} bloc_t;

typedef struct {
    void *memoire;
    bloc_t *libre;
    size_t taille_bloc;
    size_t nb_blocs;
} pool_memoire_t;

// Créer un pool de mémoire
pool_memoire_t* creer_pool(size_t taille_bloc, size_t nb_blocs) {
    pool_memoire_t *pool = malloc(sizeof(pool_memoire_t));
    if (pool == NULL) return NULL;
    
    // Aligner la taille sur la taille d'un pointeur
    if (taille_bloc < sizeof(bloc_t)) {
        taille_bloc = sizeof(bloc_t);
    }
    
    pool->taille_bloc = taille_bloc;
    pool->nb_blocs = nb_blocs;
    pool->memoire = malloc(taille_bloc * nb_blocs);
    
    if (pool->memoire == NULL) {
        free(pool);
        return NULL;
    }
    
    // Initialiser la liste des blocs libres
    pool->libre = NULL;
    char *ptr = (char*)pool->memoire;
    
    for (size_t i = 0; i < nb_blocs; i++) {
        bloc_t *bloc = (bloc_t*)ptr;
        bloc->suivant = pool->libre;
        pool->libre = bloc;
        ptr += taille_bloc;
    }
    
    return pool;
}

// Allouer un bloc
void* allouer_bloc(pool_memoire_t *pool) {
    if (pool->libre == NULL) {
        return NULL; // Pool épuisé
    }
    
    bloc_t *bloc = pool->libre;
    pool->libre = bloc->suivant;
    
    return bloc;
}

// Libérer un bloc
void liberer_bloc(pool_memoire_t *pool, void *ptr) {
    if (ptr == NULL) return;
    
    bloc_t *bloc = (bloc_t*)ptr;
    bloc->suivant = pool->libre;
    pool->libre = bloc;
}

// Détruire le pool
void detruire_pool(pool_memoire_t *pool) {
    if (pool != NULL) {
        free(pool->memoire);
        free(pool);
    }
}

int main() {
    // Créer un pool pour des entiers
    pool_memoire_t *pool = creer_pool(sizeof(int), 10);
    
    if (pool != NULL) {
        // Allouer quelques blocs
        int *a = allouer_bloc(pool);
        int *b = allouer_bloc(pool);
        int *c = allouer_bloc(pool);
        
        if (a && b && c) {
            *a = 10;
            *b = 20;
            *c = 30;
            
            printf("a = %d, b = %d, c = %d\n", *a, *b, *c);
            
            // Libérer les blocs
            liberer_bloc(pool, a);
            liberer_bloc(pool, b);
            liberer_bloc(pool, c);
        }
        
        detruire_pool(pool);
    }
    
    return 0;
}
```

## Techniques d'optimisation

### Cache-friendly programming

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 1000

// Version non optimisée (accès par colonnes)
void multiplier_matrices_lent(int a[TAILLE][TAILLE], 
                             int b[TAILLE][TAILLE], 
                             int c[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            c[i][j] = 0;
            for (int k = 0; k < TAILLE; k++) {
                c[i][j] += a[i][k] * b[k][j];  // Accès non optimal à b
            }
        }
    }
}

// Version optimisée (meilleure localité)
void multiplier_matrices_rapide(int a[TAILLE][TAILLE], 
                               int b[TAILLE][TAILLE], 
                               int c[TAILLE][TAILLE]) {
    // Initialiser c
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            c[i][j] = 0;
        }
    }
    
    // Réorganiser les boucles pour une meilleure localité
    for (int i = 0; i < TAILLE; i++) {
        for (int k = 0; k < TAILLE; k++) {
            for (int j = 0; j < TAILLE; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

double mesurer_temps(void (*fonction)(int[TAILLE][TAILLE], 
                                    int[TAILLE][TAILLE], 
                                    int[TAILLE][TAILLE]),
                    int a[TAILLE][TAILLE], 
                    int b[TAILLE][TAILLE], 
                    int c[TAILLE][TAILLE]) {
    clock_t debut = clock();
    fonction(a, b, c);
    clock_t fin = clock();
    
    return ((double)(fin - debut)) / CLOCKS_PER_SEC;
}
```

### Optimisations bit à bit

```c
#include <stdio.h>

// Vérifier si un nombre est pair (plus rapide que % 2)
int est_pair_rapide(int n) {
    return (n & 1) == 0;
}

// Multiplier par 2 (plus rapide que * 2)
int multiplier_par_2(int n) {
    return n << 1;
}

// Diviser par 2 (plus rapide que / 2)
int diviser_par_2(int n) {
    return n >> 1;
}

// Compter les bits à 1
int compter_bits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Version optimisée (algorithme de Brian Kernighan)
int compter_bits_rapide(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n - 1;  // Efface le bit le plus à droite
        count++;
    }
    return count;
}

int main() {
    int n = 42;
    
    printf("n = %d\n", n);
    printf("Est pair ? %s\n", est_pair_rapide(n) ? "Oui" : "Non");
    printf("n * 2 = %d\n", multiplier_par_2(n));
    printf("n / 2 = %d\n", diviser_par_2(n));
    printf("Bits à 1 : %d\n", compter_bits_rapide(n));
    
    return 0;
}
```

## Gestion d'erreurs robuste

### Système d'erreurs avec codes

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef enum {
    ERREUR_OK = 0,
    ERREUR_MEMOIRE,
    ERREUR_FICHIER,
    ERREUR_PARAMETRE,
    ERREUR_INTERNE
} code_erreur_t;

typedef struct {
    code_erreur_t code;
    char message[256];
    const char *fichier;
    int ligne;
} erreur_t;

// Macro pour créer une erreur avec informations de debug
#define CREER_ERREUR(code, msg) creer_erreur(code, msg, __FILE__, __LINE__)

erreur_t creer_erreur(code_erreur_t code, const char *message, 
                     const char *fichier, int ligne) {
    erreur_t err;
    err.code = code;
    strncpy(err.message, message, sizeof(err.message) - 1);
    err.message[sizeof(err.message) - 1] = '\0';
    err.fichier = fichier;
    err.ligne = ligne;
    return err;
}

void afficher_erreur(const erreur_t *err) {
    const char *type_erreur;
    switch (err->code) {
        case ERREUR_OK: type_erreur = "OK"; break;
        case ERREUR_MEMOIRE: type_erreur = "MEMOIRE"; break;
        case ERREUR_FICHIER: type_erreur = "FICHIER"; break;
        case ERREUR_PARAMETRE: type_erreur = "PARAMETRE"; break;
        case ERREUR_INTERNE: type_erreur = "INTERNE"; break;
        default: type_erreur = "INCONNU"; break;
    }
    
    fprintf(stderr, "ERREUR %s: %s (%s:%d)\n", 
            type_erreur, err->message, err->fichier, err->ligne);
}

// Fonction qui peut échouer
erreur_t allouer_tableau(int **tableau, size_t taille) {
    if (tableau == NULL || taille == 0) {
        return CREER_ERREUR(ERREUR_PARAMETRE, "Paramètres invalides");
    }
    
    *tableau = malloc(taille * sizeof(int));
    if (*tableau == NULL) {
        return CREER_ERREUR(ERREUR_MEMOIRE, "Échec d'allocation mémoire");
    }
    
    // Initialiser le tableau
    for (size_t i = 0; i < taille; i++) {
        (*tableau)[i] = i;
    }
    
    return CREER_ERREUR(ERREUR_OK, "Succès");
}

int main() {
    int *tableau = NULL;
    erreur_t err;
    
    // Test avec paramètres valides
    err = allouer_tableau(&tableau, 10);
    if (err.code != ERREUR_OK) {
        afficher_erreur(&err);
        return 1;
    }
    
    printf("Allocation réussie\n");
    
    // Utiliser le tableau
    for (int i = 0; i < 10; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    
    free(tableau);
    
    // Test avec paramètres invalides
    err = allouer_tableau(NULL, 10);
    if (err.code != ERREUR_OK) {
        afficher_erreur(&err);
    }
    
    return 0;
}
```

## Patterns de conception en C

### Factory Pattern

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Interface commune
typedef struct forme forme_t;

typedef struct {
    void (*dessiner)(const forme_t *self);
    void (*detruire)(forme_t *self);
    double (*aire)(const forme_t *self);
} forme_vtable_t;

struct forme {
    const forme_vtable_t *vtable;
};

// Implémentation Circle
typedef struct {
    forme_t base;
    double rayon;
} cercle_t;

void cercle_dessiner(const forme_t *self) {
    const cercle_t *c = (const cercle_t*)self;
    printf("Dessin d'un cercle de rayon %.2f\n", c->rayon);
}

void cercle_detruire(forme_t *self) {
    free(self);
}

double cercle_aire(const forme_t *self) {
    const cercle_t *c = (const cercle_t*)self;
    return 3.14159 * c->rayon * c->rayon;
}

static const forme_vtable_t cercle_vtable = {
    .dessiner = cercle_dessiner,
    .detruire = cercle_detruire,
    .aire = cercle_aire
};

// Implémentation Rectangle
typedef struct {
    forme_t base;
    double largeur, hauteur;
} rectangle_t;

void rectangle_dessiner(const forme_t *self) {
    const rectangle_t *r = (const rectangle_t*)self;
    printf("Dessin d'un rectangle %.2f x %.2f\n", r->largeur, r->hauteur);
}

void rectangle_detruire(forme_t *self) {
    free(self);
}

double rectangle_aire(const forme_t *self) {
    const rectangle_t *r = (const rectangle_t*)self;
    return r->largeur * r->hauteur;
}

static const forme_vtable_t rectangle_vtable = {
    .dessiner = rectangle_dessiner,
    .detruire = rectangle_detruire,
    .aire = rectangle_aire
};

// Factory
forme_t* creer_cercle(double rayon) {
    cercle_t *c = malloc(sizeof(cercle_t));
    if (c == NULL) return NULL;
    
    c->base.vtable = &cercle_vtable;
    c->rayon = rayon;
    return (forme_t*)c;
}

forme_t* creer_rectangle(double largeur, double hauteur) {
    rectangle_t *r = malloc(sizeof(rectangle_t));
    if (r == NULL) return NULL;
    
    r->base.vtable = &rectangle_vtable;
    r->largeur = largeur;
    r->hauteur = hauteur;
    return (forme_t*)r;
}

forme_t* creer_forme(const char *type, ...) {
    // Implémentation simplifiée
    if (strcmp(type, "cercle") == 0) {
        return creer_cercle(5.0);
    } else if (strcmp(type, "rectangle") == 0) {
        return creer_rectangle(4.0, 3.0);
    }
    return NULL;
}

// Fonctions polymorphiques
void dessiner_forme(const forme_t *forme) {
    if (forme && forme->vtable && forme->vtable->dessiner) {
        forme->vtable->dessiner(forme);
    }
}

double aire_forme(const forme_t *forme) {
    if (forme && forme->vtable && forme->vtable->aire) {
        return forme->vtable->aire(forme);
    }
    return 0.0;
}

void detruire_forme(forme_t *forme) {
    if (forme && forme->vtable && forme->vtable->detruire) {
        forme->vtable->detruire(forme);
    }
}

int main() {
    // Utilisation du factory
    forme_t *formes[] = {
        creer_forme("cercle"),
        creer_forme("rectangle"),
        creer_cercle(3.0),
        creer_rectangle(2.0, 4.0)
    };
    
    int nb_formes = sizeof(formes) / sizeof(formes[0]);
    
    for (int i = 0; i < nb_formes; i++) {
        if (formes[i] != NULL) {
            dessiner_forme(formes[i]);
            printf("Aire: %.2f\n", aire_forme(formes[i]));
            printf("---\n");
        }
    }
    
    // Nettoyage
    for (int i = 0; i < nb_formes; i++) {
        detruire_forme(formes[i]);
    }
    
    return 0;
}
```

## Conclusion

Ces exemples avancés montrent des techniques importantes pour :

1. **Gestion mémoire sophistiquée** : Pools, allocation custom
2. **Structures de données efficaces** : Arbres, tables de hachage
3. **Optimisations** : Cache-friendly, bit manipulation
4. **Robustesse** : Gestion d'erreurs structurée
5. **Architecture** : Patterns de conception adaptés au C

Ces techniques sont utiles pour des projets C plus complexes et professionnels.

---

*Ces exemples sont des points de départ. Adaptez-les selon vos besoins spécifiques.*
