# <u>**Programmation en C[^1] du cours au CNAM UTC302[^2]**</u>
	
<!--
<svg xmlns="http://www.w3.org/2000/svg" width="30" height="50" fill="currentColor" class="bi bi-info-circle" viewBox="0 0 16 16">
  <path d="M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14zm0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16z"/>
  <path d="m8.93 6.588-2.29.287-.082.38.45.083c.294.07.352.176.288.469l-.738 3.468c-.194.897.105 1.319.808 1.319.545 0 1.178-.252 1.465-.598l.088-.416c-.2.176-.492.246-.686.246-.275 0-.375-.193-.304-.533L8.93 6.588zM9 4.5a1 1 0 1 1-2 0 1 1 0 0 1 2 0z"/>
  https://icons.getbootstrap.com/icons/info-circle/-->

<svg xmlns="https://www.w3.org/2000/svg" width="30" height="50" viewBox="0 0 512 512"><!--! Font Awesome Pro 6.2.0 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license (Commercial License) Copyright 2022 Fonticons, Inc. --><path d="M256 512c141.4 0 256-114.6 256-256S397.4 0 256 0S0 114.6 0 256S114.6 512 256 512zM216 336h24V272H216c-13.3 0-24-10.7-24-24s10.7-24 24-24h48c13.3 0 24 10.7 24 24v88h8c13.3 0 24 10.7 24 24s-10.7 24-24 24H216c-13.3 0-24-10.7-24-24s10.7-24 24-24zm40-144c-17.7 0-32-14.3-32-32s14.3-32 32-32s32 14.3 32 32s-14.3 32-32 32z"/></svg>

```markdown
Projet dédié à la programmation en C vu en cours UTC302 au CNAM à Toulouse.
```

- [**Programmation en C\[^1\] du cours au CNAM UTC302\[^2\]**](#programmation-en-c1-du-cours-au-cnam-utc3022)
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
