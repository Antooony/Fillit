# Fillit
Second projet du cursus 42.
L'objectif de ce projet est de concevoir un programme capable de recevoir des tetriminos et de les agencer de sorte a créer le plus petit carré possible.

Les tetriminos sont envoyés dans un fichier, voici un exemple de fichier valide la forme suivante

```
####
....
....
....

##..
##..
....
....
```

le programme doit afficher sur la sortie standard le plus petit carré possible en agençant les pieces,
les pieces sont formatées en utilisant des lettres majuscules, en commençant par 'A', dans l'ordre d'apparition de celles-ci.

Suivant cette règle, la sortie du programme en l'executant avec ces 2 pieces est la suivante:
```
AAAA
BB..
BB..
....
```
## Usage

On compile via le makefile
```
$> make 
```
On execute ```./fillit [input_file]```, par exemple :
```
$> ./fillit test_files/01.txt
AAAA
BB..
BB..
....
```
