# Guide de compilation et d'exécution

Ce guide détaille comment compiler et exécuter les programmes C de ce dépôt sur différentes plateformes.

## Table des matières

- [Installation des outils](#installation-des-outils)
- [Compilation de base](#compilation-de-base)
- [Options de compilation](#options-de-compilation)
- [Débogage](#débogage)
- [Gestion des erreurs](#gestion-des-erreurs)
- [Automatisation](#automatisation)
- [Plateformes spécifiques](#plateformes-spécifiques)

## Installation des outils

### macOS

#### Option 1 : Xcode Command Line Tools (Recommandé)
```bash
xcode-select --install
```

#### Option 2 : Homebrew
```bash
# Installer Homebrew si nécessaire
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Installer GCC
brew install gcc
```

#### Vérification
```bash
gcc --version
# Devrait afficher : Apple clang version... ou gcc version...
```

### Linux (Ubuntu/Debian)

```bash
# Mettre à jour les paquets
sudo apt update

# Installer les outils de développement
sudo apt install build-essential

# Installer des outils supplémentaires (optionnel)
sudo apt install gdb valgrind
```

#### Vérification
```bash
gcc --version
gdb --version
```

### Windows

#### Option 1 : MinGW-w64
1. Téléchargez MinGW-w64 depuis [mingw-w64.org](https://www.mingw-w64.org/)
2. Ajoutez le répertoire `bin` au PATH
3. Ouvrez une invite de commande

#### Option 2 : Visual Studio
1. Installez Visual Studio Community
2. Sélectionnez "Développement Desktop en C++"
3. Utilisez "Developer Command Prompt"

#### Option 3 : WSL (Windows Subsystem for Linux)
```bash
# Dans PowerShell (en tant qu'administrateur)
wsl --install

# Puis suivez les instructions Linux
```

## Compilation de base

### Commande simple

```bash
# Syntaxe de base
gcc -o nom_programme fichier_source.c

# Exemple
gcc -o hello main.c
```

### Compilation et exécution rapide

```bash
# Compiler
gcc -o programme main.c

# Exécuter (Unix/Linux/macOS)
./programme

# Exécuter (Windows)
programme.exe
```

### Exemple pratique

```bash
# Naviguer dans un dossier d'exercice
cd "Algorithmique-Programmation-UTC302/Hello Word"

# Compiler
gcc -o hello main.c

# Exécuter
./hello
```

## Options de compilation

### Options essentielles

```bash
# Compilation avec warnings (RECOMMANDÉ)
gcc -Wall -Wextra -o programme main.c

# Compilation avec informations de débogage
gcc -Wall -Wextra -g -o programme main.c

# Compilation stricte (pour l'apprentissage)
gcc -Wall -Wextra -Werror -std=c99 -pedantic -g -o programme main.c
```

### Détail des options

| Option | Description |
|--------|-------------|
| `-Wall` | Active la plupart des warnings |
| `-Wextra` | Active des warnings supplémentaires |
| `-Werror` | Traite les warnings comme des erreurs |
| `-g` | Inclut les informations de débogage |
| `-std=c99` | Utilise le standard C99 |
| `-pedantic` | Respect strict du standard |
| `-O2` | Optimisation niveau 2 |
| `-o nom` | Spécifie le nom de l'exécutable |

### Exemples d'utilisation

```bash
# Pour l'apprentissage (strict)
gcc -Wall -Wextra -Werror -std=c99 -pedantic -g -o programme main.c

# Pour le développement
gcc -Wall -Wextra -g -o programme main.c

# Pour la production
gcc -Wall -Wextra -O2 -o programme main.c

# Compilation silencieuse (non recommandé)
gcc -o programme main.c
```

## Débogage

### Compilation pour le débogage

```bash
# Inclure les informations de débogage
gcc -Wall -Wextra -g -o programme main.c
```

### Utilisation de GDB

```bash
# Lancer GDB
gdb ./programme

# Commandes GDB de base
(gdb) run                    # Exécuter le programme
(gdb) break main             # Point d'arrêt sur main
(gdb) break 15               # Point d'arrêt ligne 15
(gdb) next                   # Ligne suivante
(gdb) step                   # Entrer dans les fonctions
(gdb) print variable         # Afficher une variable
(gdb) list                   # Afficher le code
(gdb) quit                   # Quitter GDB
```

### Exemple de session GDB

```bash
gcc -Wall -Wextra -g -o debug main.c
gdb ./debug

(gdb) break main
(gdb) run
(gdb) next
(gdb) print variable_name
(gdb) continue
(gdb) quit
```

### Débogage avec printf

```c
#include <stdio.h>

int main() {
    int x = 10;
    printf("DEBUG: x = %d\n", x);  // Message de débogage
    
    // Votre code ici
    
    printf("DEBUG: Fin du programme\n");
    return 0;
}
```

## Gestion des erreurs

### Erreurs de compilation courantes

#### 1. Fichier non trouvé
```bash
# Erreur
gcc: error: main.c: No such file or directory

# Solution
ls -la          # Vérifier que le fichier existe
pwd             # Vérifier le répertoire courant
```

#### 2. Erreurs de syntaxe
```bash
# Erreur
main.c:10:5: error: expected ';' before 'return'

# Solution : Ajouter le point-virgule manquant
```

#### 3. Fonction non déclarée
```bash
# Erreur
main.c:15:5: error: implicit declaration of function 'ma_fonction'

# Solution : Ajouter la déclaration ou l'include approprié
```

#### 4. Variables non initialisées
```bash
# Warning
main.c:12:5: warning: 'x' is used uninitialized

# Solution : Initialiser la variable
int x = 0;  // au lieu de : int x;
```

### Erreurs d'exécution courantes

#### 1. Segmentation fault
```bash
# Causes possibles :
# - Déréférencement d'un pointeur NULL
# - Accès hors limites d'un tableau
# - Pile d'appels trop profonde (récursion infinie)

# Débogage avec GDB
gcc -g -o programme main.c
gdb ./programme
(gdb) run
# Le programme plante
(gdb) backtrace  # Voir la pile d'appels
```

#### 2. Fuites mémoire
```bash
# Utiliser Valgrind (Linux/macOS)
gcc -g -o programme main.c
valgrind --leak-check=full ./programme
```

## Automatisation

### Makefile simple

Créez un fichier `Makefile` :

```makefile
# Makefile pour un projet C simple
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99
TARGET = programme
SOURCE = main.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

debug: $(SOURCE)
	$(CC) $(CFLAGS) -DDEBUG -o $(TARGET) $(SOURCE)

.PHONY: clean debug
```

Utilisation :
```bash
make           # Compiler
make debug     # Compiler en mode debug
make clean     # Nettoyer
```

### Script de compilation

Créez un script `compile.sh` :

```bash
#!/bin/bash

# Script de compilation automatique
set -e  # Arrêter en cas d'erreur

echo "🔨 Compilation en cours..."

# Options de compilation
CC="gcc"
CFLAGS="-Wall -Wextra -g -std=c99"
SOURCE="main.c"
TARGET="programme"

# Compiler
$CC $CFLAGS -o $TARGET $SOURCE

echo "✅ Compilation réussie : $TARGET"
echo "🚀 Exécution :"
./$TARGET
```

Utilisation :
```bash
chmod +x compile.sh
./compile.sh
```

### Script pour tous les exercices

```bash
#!/bin/bash

# Compiler tous les exercices
find "Algorithmique-Programmation-UTC302" -name "main.c" -type f | while read file; do
    dir=$(dirname "$file")
    echo "Compilation de $dir..."
    
    cd "$dir"
    if gcc -Wall -Wextra -o programme main.c 2>/dev/null; then
        echo "✅ $dir : OK"
    else
        echo "❌ $dir : ERREUR"
    fi
    cd - >/dev/null
done
```

## Plateformes spécifiques

### macOS avec Xcode

```bash
# Compiler avec Xcode
xcodebuild -project MonProjet.xcodeproj -scheme MonScheme

# Ou utiliser GCC directement
gcc -Wall -Wextra -g -o programme main.c
```

### Linux avec différents compilateurs

```bash
# GCC (par défaut)
gcc -Wall -Wextra -g -o programme main.c

# Clang
clang -Wall -Wextra -g -o programme main.c

# Intel C Compiler (si installé)
icc -Wall -g -o programme main.c
```

### Windows avec MinGW

```cmd
REM Dans l'invite de commande
gcc -Wall -Wextra -g -o programme.exe main.c
programme.exe
```

### Windows avec Visual Studio

```cmd
REM Dans Developer Command Prompt
cl /Wall main.c
main.exe
```

## Conseils et bonnes pratiques

### 1. Toujours compiler avec warnings

```bash
# TOUJOURS utiliser au minimum
gcc -Wall -Wextra -g -o programme main.c
```

### 2. Tester sur différents compilateurs

```bash
# GCC
gcc -Wall -Wextra -std=c99 -o programme main.c

# Clang
clang -Wall -Wextra -std=c99 -o programme main.c
```

### 3. Utiliser des noms explicites

```bash
# Au lieu de
gcc -o a.out main.c

# Préférer
gcc -o calculatrice main.c
```

### 4. Organiser les fichiers

```
projet/
├── src/
│   └── main.c
├── include/
│   └── header.h
├── build/
│   └── programme
└── Makefile
```

### 5. Versionner uniquement les sources

```bash
# .gitignore
*.o
*.exe
a.out
programme
build/
```

## Dépannage

### Problèmes courants

1. **"Command not found: gcc"**
   - Installez les outils de développement
   - Vérifiez votre PATH

2. **"Permission denied"**
   ```bash
   chmod +x programme
   ./programme
   ```

3. **"Segmentation fault"**
   - Compilez avec `-g` et utilisez GDB
   - Vérifiez les pointeurs et les limites de tableaux

4. **Warnings nombreux**
   - Lisez attentivement chaque warning
   - Corrigez un par un
   - Ne les ignorez jamais

### Ressources d'aide

- `man gcc` : Manuel de GCC
- `gcc --help` : Options disponibles
- [Documentation GCC](https://gcc.gnu.org/onlinedocs/)
- [GDB Tutorial](https://www.gnu.org/software/gdb/documentation/)

---

*Ce guide couvre les aspects essentiels de la compilation C. Consultez la documentation officielle pour des besoins spécifiques.*
