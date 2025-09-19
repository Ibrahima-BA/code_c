# <u>**Programmation en C[^1] du cours au CNAM UTC302[^2]**</u>
	
```markdown
Projet dédié à la programmation en C vu en cours UTC302 au CNAM à Toulouse.
```
## Table des matiéres

- [**Programmation en C\[^1\] du cours au CNAM UTC302\[^2\]**](#programmation-en-c1-du-cours-au-cnam-utc3022)
  - [Table des matiéres](#table-des-matiéres)
  - [1. Apprentissage du code c](#1-apprentissage-du-code-c)
  - [2. Modifier le Pointeur de Tête](#2-modifier-le-pointeur-de-tête)
  - [3. Ajouter ou Supprimer des Éléments](#3-ajouter-ou-supprimer-des-éléments)
  - [4. Allocation Dynamique de Mémoire](#4-allocation-dynamique-de-mémoire)
    - [Lien vers la Library stdio.h](#lien-vers-la-library-stdioh)


## 1. Apprentissage du code c

Dans le langage C, l'usage des doubles pointeurs (**) est souvent nécessaire pour manipuler les adresses de pointeurs, notamment lorsque l'on souhaite modifier directement l'adresse à laquelle un pointeur pointe à partir d'une fonction. L'utilisation de deux étoiles (**) est particulièrement courante avec des structures de données comme les listes chaînées, où les modifications de la structure doivent être reflétées à l'extérieur de la fonction qui effectue ces modifications. Voici quelques raisons spécifiques pour lesquelles on utilise `**` dans les fonctions de votre programme :

## 2. Modifier le Pointeur de Tête
Lorsque vous travaillez avec des listes chaînées, vous avez souvent un pointeur qui pointe vers le premier élément de la liste, généralement appelé le "pointeur de tête" (`head`). Si vous voulez modifier ce pointeur de tête dans une fonction (par exemple, insérer une nouvelle carte au début ou supprimer la première carte), vous devez passer l'adresse de ce pointeur à la fonction. Cela nécessite l'utilisation d'un pointeur vers un pointeur (`**`) :
`struct Carte **p_tete `signifie que `p_tete` est un pointeur vers un pointeur de type struct Carte. Cela permet à la fonction d'accéder et de modifier l'adresse à laquelle le pointeur original (dehors de la fonction) pointe.

## 3. Ajouter ou Supprimer des Éléments
Prenons l'exemple de l'ajout d'une carte au début de la liste :
Si la liste est vide (le pointeur de tête est `NULL`), et que vous voulez ajouter un nouvel élément, vous devez changer le pointeur de tête pour qu'il pointe vers le nouvel élément. Pour ce faire efficacement dans une fonction, vous devez modifier le pointeur lui-même, pas seulement le contenu de l'endroit où il pointe. Passer l'adresse du pointeur (utiliser `**`) à la fonction vous permet de mettre à jour le pointeur de tête directement.

## 4. Allocation Dynamique de Mémoire
Lorsque de nouveaux éléments sont créés dynamiquement en utilisant `malloc` (comme dans `CreerCarte`), ces éléments sont souvent ajoutés à une structure de données comme une liste chaînée. Si vous souhaitez intégrer cet élément dans votre liste au sein d'une fonction, vous devez assurer que toute modification (ajout ou suppression) se reflète dans toute la liste. L'utilisation d'un double pointeur garantit que les modifications apportées à la liste dans la fonction persistent même après la fin de l'exécution de la fonction.

### [Lien vers la Library stdio.h](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm)



[^1]: C, est un laguage de communication informatique.
[^2]: **UTC302**, est un cours qui est donnée au **CNAM**, permettant l'obtention d'une certification RNTCP, niveau 7.
