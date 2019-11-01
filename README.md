<div align="center"><h1>Chap - Epitech 2019</h1>

[![Build Status](https://travis-ci.org/HugoSohm/Chap.svg?branch=master)](https://travis-ci.org/HugoSohm/Chap)

Le chap est un projet de programmation réseau en C de 2 semaines

</div>

## Projet chap

### Paramètres

Le chap nécéssite 3 arguments pour fonctionner et un serveur avec le mot de passe

- Cible
- Port
- Mot de passe
- Serveur avec SHA256

## Installation et compilation

### Récupération du projet

Après avoir cloné le [répertoire](https://github.com/HugoSohm/Chap):

```
git clone https://github.com/HugoSohm/Chap
```

- Se rendre à la racine du projet :

```
$ cd Chap
```

- Vérifier que tout est à jour :

```
$ git checkout master
```

### Compilation du programme

- Compilation

```
$ make
```

- Re-compilation

```
$ make re
```

- Nettoyage

```
$ make fclean
```

## Exécution

### Lancement du programme

- Client
```
$ sudo ./client -t 127.0.0.1 -p 4242 -p "epitech"
```

- Serveur
```
$ ./server 4242
```
