# Programmation en C - Cours CNAM UTC302

Ce dépôt contient les exercices et projets de programmation en C développés dans le cadre du cours UTC302 au CNAM de Toulouse. Il s'agit d'une collection complète d'exemples pratiques couvrant les concepts fondamentaux du langage C.

## Description

Ce projet pédagogique propose une approche progressive de l'apprentissage du langage C, de la syntaxe de base aux concepts avancés comme la gestion dynamique de la mémoire et les structures de données.

## Table des matières

- [Structure du projet](#structure-du-projet)
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Concepts abordés](#concepts-abordés)
- [Organisation des exercices](#organisation-des-exercices)
- [Compilation](#compilation)
- [Documentation](#documentation)
- [Contribution](#contribution)
- [Licence](#licence)

## Structure du projet

```
code_c/
├── Algorithmique-Programmation-UTC302/  # Exercices principaux
├── docs/                                # Documentation et wiki
├── templates/                           # Modèles et scripts utilitaires
├── test/                               # Tests et exemples
└── README.md                           # Ce fichier
```

## Prérequis

- Compilateur C (GCC recommandé)
- Make (optionnel)
- Xcode (pour macOS)
- Connaissances de base en programmation

## Installation

1. Clonez le dépôt :
```bash
git clone https://github.com/Ibrahima-BA/code_c.git
cd code_c
```

2. Compilez un exemple :
```bash
cd "Algorithmique-Programmation-UTC302/Hello Word"
gcc -o hello main.c
./hello
```

## Utilisation

Chaque dossier contient un programme C complet avec son fichier `main.c`. Naviguez dans le dossier souhaité et compilez le programme :

```bash
cd "nom-du-dossier"
gcc -o programme main.c
./programme
```

## Concepts abordés

### 1. Syntaxe de base
- Variables et types de données
- Opérateurs arithmétiques et logiques
- Structures de contrôle (if/else, switch)
- Boucles (for, while, do-while)

### 2. Fonctions
- Déclaration et définition de fonctions
- Passage de paramètres par valeur et par référence
- Fonctions récursives
- Portée des variables

### 3. Pointeurs
- Déclaration et utilisation des pointeurs
- Arithmétique des pointeurs
- Pointeurs de pointeurs (**)
- Passage de pointeurs aux fonctions

### 4. Tableaux et chaînes de caractères
- Tableaux unidimensionnels et multidimensionnels
- Manipulation de chaînes de caractères
- Relation entre tableaux et pointeurs

### 5. Structures de données
- Structures (struct)
- Énumérations (enum)
- Unions
- Listes chaînées

### 6. Gestion mémoire
- Allocation statique vs dynamique
- Fonctions malloc(), calloc(), realloc(), free()
- Gestion des fuites mémoire

## Organisation des exercices

Les exercices sont organisés par thème dans le dossier `Algorithmique-Programmation-UTC302/` :

- **Hello Word/** : Premier programme, affichage de base
- **Condition-if-else/** : Structures conditionnelles
- **c_for/** : Boucles for
- **pointeur/** : Introduction aux pointeurs
- **Tableau/** : Manipulation de tableaux
- **Structure Exemple/** : Utilisation des structures
- **Liste chainé/** : Implémentation de listes chaînées
- **case/** : Instructions switch/case
- **chaine de caractere/** : Manipulation de chaînes

## Compilation

### Compilation simple
```bash
gcc -o programme main.c
```

### Compilation avec options de débogage
```bash
gcc -Wall -Wextra -g -o programme main.c
```

### Compilation avec optimisation
```bash
gcc -O2 -o programme main.c
```

## Documentation

La documentation complète est disponible dans le dossier `docs/` :
- [Guide d'apprentissage](docs/guide-apprentissage.md)
- [Référence des concepts](docs/concepts.md)
- [FAQ](docs/faq.md)
- [Exemples avancés](docs/exemples-avances.md)

## Contribution

Les contributions sont les bienvenues ! Consultez le fichier [CONTRIBUTING.md](CONTRIBUTING.md) pour les directives de contribution.

## Licence

Ce projet est sous licence Apache 2.0. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

**Auteur :** Ibrahima BA  
**Cours :** UTC302 - CNAM Toulouse  
**Année :** 2024
