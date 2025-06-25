# mysh

**"This isn’t flying. This is falling with style!"**

## 🧠 Description

**mysh** est une version enrichie d'un shell minimaliste (projet *minishell1*), développée en C.  
Elle supporte la gestion des **points-virgules (`;`)**, **pipes (`|`)**, ainsi que les **quatre types de redirections** :  
`>`, `<`, `>>`, `<<`.

Ce shell offre une interprétation simple des commandes avec une gestion correcte des priorités d'exécution.

---

## ⚙️ Caractéristiques

- Exécution de commandes séparées par `;`
- Gestion des tubes (`|`)
- Gestion des redirections :
  - Sortie standard : `>` et `>>`
  - Entrée standard : `<` et `<<`
- Gestion des erreurs avec code de retour `84`
- Redirection de flux avancée (bonus) :
  - `2>&1`, `&>`, etc.
- Gestion des signaux
- Support de l'environnement courant (`cd`, `getcwd`, etc.)

---

## 📁 Structure

- `src/` : code source principal
- `include/` : headers
- `bonus/` : fichiers bonus (fonctionnalités non obligatoires)
- `Makefile` : compilation automatisée

---

## 🛠️ Compilation

Le projet se compile avec `make`.

```bash
make        # Compilation
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets + le binaire
make re     # clean + build
```

Le binaire généré s'appelle : `mysh`

---

## ✅ Fonctionnalités autorisées

Voici les fonctions système et libc autorisées pour ce projet :

```
malloc, free, exit, opendir, readdir, closedir, getcwd, chdir, fork,
stat, lstat, fstat, open, close, getline, strtok, strtok_r, read, write,
execve, access, isatty, wait, waitpid, wait3, wait4, signal, kill,
getpid, strerror, perror, strsignal, pipe, dup, dup2
```

---

## ❌ Gestion des erreurs

- Tous les messages d’erreur sont affichés sur **la sortie d’erreur standard** (`stderr`).
- En cas d'erreur, le programme quitte avec le **code de retour `84`**.
- En cas de succès, **code de retour `0`**.

---

## 💡 Utilisation

Le shell peut être utilisé en interactif ou via un pipe :

```bash
./mysh
$> ls -l; ls -l | wc -l
```

Ou bien :

```bash
echo "mkdir test; cd test; ls -a; ls | cat | wc -c > tutu; cat tutu" | ./mysh
```

---

## 👤 Auteur

- Projet réalisé individuellement (groupe de 1 personne).
- Langage utilisé : **C**

---

## 📝 Notes

- Tous les fichiers livrés doivent être utiles (pas de binaires, fichiers temporaires, etc.).
- La gestion de redirections complexes (`2>&1`, `&>`, etc.) est **considérée comme bonus**.
- L’environnement utilisé pour les tests est POSIX (Linux).
