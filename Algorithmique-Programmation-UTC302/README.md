# Exercices de Programmation C - UTC302

Ce dossier contient tous les exercices pratiques du cours UTC302 du CNAM, organisés par thème et niveau de difficulté.

## Organisation des exercices

### 🟢 Niveau débutant

#### Premiers pas
- **Hello Word/** - Premier programme C, affichage de base
- **HelloWord-test/** - Variante du Hello World
- **Bonjour-Retour chariot/** - Gestion des retours à la ligne

#### Entrées/sorties
- **Condition-if-else/** - Structures conditionnelles de base
- **condition-math/** - Conditions avec calculs mathématiques

### 🟡 Niveau intermédiaire

#### Boucles et itérations
- **c_for/** - Utilisation des boucles for
- **case/** - Instructions switch/case
- **case alphabe/** - Switch avec caractères alphabétiques
- **case-convert_hex/** - Conversion hexadécimale avec switch

#### Fonctions
- **division-fonction/** - Fonctions pour la division
- **multiplication-math-fonction/** - Fonctions mathématiques

#### Tableaux et chaînes
- **Tableau/** - Manipulation de tableaux
- **chaine de caractere/** - Manipulation de chaînes de caractères
- **chaine de caractere inverse/** - Inversion de chaînes

### 🔴 Niveau avancé

#### Pointeurs
- **pointeur/** - Introduction aux pointeurs
- **pointeur-2/** - Pointeurs avancés
- **pointeur-suite/** - Suite sur les pointeurs
- **pointeur-suite2/** - Pointeurs et tableaux

#### Structures de données
- **Structure Exemple/** - Introduction aux structures
- **Structure Exemple 2/** - Structures avancées
- **Structure Exemple 3/** - Structures complexes
- **structure exercice/** - Exercices pratiques sur les structures
- **structure exercice 2/** - Exercices avancés
- **Structure exercice 3/** - Structures et fonctions
- **Structure exercice 4/** - Structures et allocation dynamique

#### Listes chaînées
- **Liste chainé/** - Introduction aux listes chaînées
- **Liste chainé 2/** - Opérations sur les listes
- **Liste chainé 3/** - Listes chaînées avancées

### 🟠 Applications pratiques

- **TVA/** - Calcul de TVA
- **Somme d'argent/** - Gestion de montants financiers
- **Reel-Complexe-Math/** - Nombres complexes et calculs mathématiques

### 🔧 Exercices et tests

- **Exo/** - Exercice général
- **Exo2/** - Exercice avancé
- **Essai Thierry/** - Test spécifique

## Comment utiliser ces exercices

### 1. Parcours recommandé

Suivez l'ordre suggéré dans le [guide d'apprentissage](../docs/guide-apprentissage.md) :

1. Commencez par les exercices **🟢 débutant**
2. Progressez vers les exercices **🟡 intermédiaire**
3. Terminez par les exercices **🔴 avancé**
4. Appliquez vos connaissances avec les **🟠 applications pratiques**

### 2. Pour chaque exercice

```bash
# 1. Naviguez dans le dossier
cd "nom-du-dossier"

# 2. Lisez le code source
cat main.c

# 3. Compilez le programme
gcc -Wall -Wextra -g -o programme main.c

# 4. Exécutez le programme
./programme

# 5. Expérimentez en modifiant le code
```

### 3. Compilation recommandée

Pour tous les exercices, utilisez ces options de compilation :

```bash
# Compilation de base
gcc -o programme main.c

# Compilation avec warnings (recommandé)
gcc -Wall -Wextra -g -o programme main.c

# Compilation stricte (pour apprendre)
gcc -Wall -Wextra -Werror -std=c99 -pedantic -g -o programme main.c
```

## Concepts abordés par exercice

### Syntaxe de base
- Variables et types : `Hello Word`, `Bonjour-Retour chariot`
- Conditions : `Condition-if-else`, `condition-math`
- Boucles : `c_for`
- Switch : `case`, `case alphabe`, `case-convert_hex`

### Fonctions
- Définition : `division-fonction`, `multiplication-math-fonction`
- Paramètres et retour : Tous les exercices de fonction

### Tableaux et chaînes
- Tableaux : `Tableau`
- Chaînes : `chaine de caractere`, `chaine de caractere inverse`

### Pointeurs
- Bases : `pointeur`
- Avancé : `pointeur-2`, `pointeur-suite`, `pointeur-suite2`

### Structures
- Introduction : `Structure Exemple`
- Pratique : `structure exercice` (1-4)
- Applications : `Structure Exemple` (2-3)

### Allocation dynamique
- Listes : `Liste chainé` (1-3)
- Gestion mémoire : Exercices de structures avancés

## Aide et dépannage

### Erreurs courantes

1. **Erreur de compilation** : Vérifiez la syntaxe et les includes
2. **Segmentation fault** : Problème de pointeurs ou de mémoire
3. **Warning unused variable** : Variable déclarée mais non utilisée

### Ressources

- [Guide d'apprentissage](../docs/guide-apprentissage.md) - Parcours structuré
- [Référence des concepts](../docs/concepts.md) - Aide-mémoire
- [FAQ](../docs/faq.md) - Questions fréquentes
- [Guide de contribution](../CONTRIBUTING.md) - Comment contribuer

### Support

- Consultez la documentation dans le dossier `docs/`
- Posez vos questions via les issues GitHub
- Suivez le [guide de contribution](../CONTRIBUTING.md) pour proposer des améliorations

## Progression suggérée

```
Semaine 1-2 : Hello Word → Bonjour-Retour chariot → Condition-if-else
Semaine 3-4 : c_for → case → division-fonction
Semaine 5-6 : Tableau → chaine de caractere → pointeur
Semaine 7-8 : Structure Exemple → structure exercice
Semaine 9-10 : Liste chainé → Applications pratiques
```

---

**Bon apprentissage du langage C !**

*Mise à jour : 26 September 2025*
