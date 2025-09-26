# Guide de contribution

Merci de votre intérêt pour contribuer à ce projet d'apprentissage du langage C ! Ce guide vous explique comment participer efficacement.

## Comment contribuer

### Types de contributions acceptées

- **Corrections de bugs** dans les programmes C
- **Améliorations de code** (optimisation, lisibilité)
- **Nouveaux exercices** avec documentation
- **Améliorations de documentation**
- **Traductions** des commentaires et documentation
- **Tests** et validation des programmes

### Types de contributions non acceptées

- Modifications des concepts pédagogiques de base
- Ajout de dépendances externes non justifiées
- Code non documenté ou mal commenté

## Processus de contribution

### 1. Préparation

1. **Fork** le projet sur GitHub
2. **Clone** votre fork localement :
```bash
git clone https://github.com/votre-nom/code_c.git
cd code_c
```

3. **Créez une branche** pour votre contribution :
```bash
git checkout -b feature/ma-contribution
```

### 2. Développement

#### Pour les corrections de code
1. Identifiez le problème dans le fichier concerné
2. Corrigez en respectant le style existant
3. Testez la compilation et l'exécution :
```bash
gcc -Wall -Wextra -g -o test main.c
./test
```

#### Pour les nouveaux exercices
1. Créez un nouveau dossier avec un nom descriptif
2. Ajoutez le fichier `main.c` avec :
   - En-tête avec description et auteur
   - Code bien commenté
   - Gestion d'erreurs appropriée
3. Créez un `README.md` spécifique au dossier

#### Pour la documentation
1. Respectez le format Markdown
2. Utilisez un français correct
3. Ajoutez des exemples pratiques
4. Vérifiez les liens

### 3. Standards de code

#### Style de programmation C
```c
// En-tête obligatoire
//
//  main.c
//  Nom du projet
//
//  Créé par [Votre Nom] le [Date].
//  Description du programme
//

#include <stdio.h>
#include <stdlib.h>

// Constantes en MAJUSCULES
#define MAX_SIZE 100

// Fonctions avec noms explicites
int calculer_moyenne(int tableau[], int taille) {
    // Code indenté avec 4 espaces
    if (taille == 0) {
        return 0;
    }
    
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tableau[i];
    }
    
    return somme / taille;
}

int main(void) {
    // Variables initialisées
    int nombres[] = {1, 2, 3, 4, 5};
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    // Gestion d'erreurs
    int moyenne = calculer_moyenne(nombres, taille);
    printf("Moyenne : %d\n", moyenne);
    
    return 0;
}
```

#### Règles de nommage
- **Variables** : `snake_case` (ex: `nombre_elements`)
- **Fonctions** : `snake_case` (ex: `calculer_somme`)
- **Constantes** : `MAJUSCULES` (ex: `MAX_TAILLE`)
- **Fichiers** : `kebab-case` pour les dossiers (ex: `liste-chainee`)

#### Commentaires
- Commentaires en français
- Explication du but de chaque fonction
- Commentaires pour les parties complexes
- Pas de commentaires évidents

### 4. Tests

Avant de soumettre :

1. **Compilation** sans warnings :
```bash
gcc -Wall -Wextra -Werror -std=c99 -pedantic main.c
```

2. **Tests fonctionnels** :
   - Cas normaux
   - Cas limites
   - Gestion d'erreurs

3. **Vérification mémoire** (si applicable) :
```bash
valgrind --leak-check=full ./programme
```

### 5. Soumission

1. **Commit** avec un message descriptif :
```bash
git add .
git commit -m "feat: ajout exercice sur les listes chaînées

- Implémentation d'une liste chaînée simple
- Fonctions d'insertion et suppression
- Tests avec différents cas d'usage
- Documentation complète"
```

2. **Push** vers votre fork :
```bash
git push origin feature/ma-contribution
```

3. **Créez une Pull Request** sur GitHub avec :
   - Titre descriptif
   - Description détaillée des changements
   - Capture d'écran si applicable
   - Tests effectués

## Format des messages de commit

Utilisez le format suivant :

```
type(scope): description courte

Description détaillée si nécessaire

- Point 1
- Point 2
```

### Types de commit
- `feat` : Nouvelle fonctionnalité
- `fix` : Correction de bug
- `docs` : Documentation uniquement
- `style` : Formatage (pas de changement de code)
- `refactor` : Refactoring (ni bug ni fonctionnalité)
- `test` : Ajout de tests
- `chore` : Maintenance

### Exemples
```bash
git commit -m "fix(pointeurs): correction segmentation fault dans exemple"
git commit -m "feat(structures): ajout exercice sur les unions"
git commit -m "docs(readme): amélioration guide d'installation"
```

## Révision de code

### Critères d'acceptation

- [ ] Code compile sans warnings
- [ ] Fonctionnalité testée et validée
- [ ] Documentation à jour
- [ ] Style de code respecté
- [ ] Pas de régression introduite

### Processus de révision

1. **Révision automatique** : CI/CD vérifie la compilation
2. **Révision manuelle** : Maintainer vérifie le code
3. **Tests** : Validation fonctionnelle
4. **Merge** : Intégration dans la branche principale

## Organisation du projet

### Structure des dossiers
```
code_c/
├── Algorithmique-Programmation-UTC302/  # Exercices principaux
│   ├── Hello Word/                       # Premier programme
│   ├── pointeur/                         # Exercices pointeurs
│   └── ...
├── docs/                                 # Documentation
│   ├── guide-apprentissage.md
│   ├── concepts.md
│   └── faq.md
├── templates/                            # Modèles et scripts
└── test/                                # Tests et exemples
```

### Ajout d'un nouvel exercice

1. Créer le dossier dans `Algorithmique-Programmation-UTC302/`
2. Ajouter le `main.c` avec code complet
3. Créer un `README.md` spécifique
4. Mettre à jour la documentation principale
5. Ajouter au guide d'apprentissage

## Ressources

### Documentation
- [Guide d'apprentissage](docs/guide-apprentissage.md)
- [Référence des concepts](docs/concepts.md)
- [FAQ](docs/faq.md)

### Outils recommandés
- **Compilateur** : GCC avec options strictes
- **Éditeur** : VS Code avec extension C/C++
- **Débogage** : GDB, Valgrind
- **Formatage** : clang-format

### Standards de référence
- Standard C99 ou C11
- GNU Coding Standards pour le style
- POSIX pour la portabilité

## Aide et support

### Où demander de l'aide
- **Issues GitHub** : Pour les bugs et questions
- **Discussions** : Pour les idées et suggestions
- **Email** : Pour les questions privées

### Réponse aux questions
- Les mainteneurs répondent sous 48h en général
- Soyez précis dans vos descriptions
- Fournissez des exemples reproductibles

## Code de conduite

- Respectez les autres contributeurs
- Soyez constructif dans vos commentaires
- Acceptez les critiques avec bienveillance
- Aidez les débutants

## Reconnaissance

Les contributeurs sont reconnus dans :
- Fichier AUTHORS (si créé)
- Section remerciements du README
- Commentaires dans le code pour les contributions importantes

---

**Merci de contribuer à l'apprentissage du C !**

*Ce guide peut évoluer. Consultez la version la plus récente avant de contribuer.*
