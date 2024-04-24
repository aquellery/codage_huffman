# codage_huffman
PROJ631 - Projet Algo : Compression de données par codage de Huffman

Ce projet est codé en C++.
Pour permettre une bonne organisation des fichiers utilisés, les textes à compressés se trouvent dans le dossier "data" et les fichiers compressés seront automatiquement enregistré dans le sous-dossier "compression".

## Utilisation du programme :
Le programme prend en paramètre le nom du fichier à compresser. Un nouveau fichier va ensuite être recréé en reprenant le nom du fichier passé en paramètre.
Voici la commande a exécuter pour lancer le programme :
g++ *.cpp -o codage_huffman ./codage_huffman fichier_a_compressé

Par exemple : 
g++ *.cpp -o codage_huffman ./codage_huffman alice

Les fichiers étant automatiquement des fichiers txt, il n'y a pas besoin de le préciser dans l'invite de commande.

## Fonctionnement du programme :
Le fichier main.cpp permet de regrouper tous les autres fichiers et de lancer les méthodes nécessaires au fonctionnement du programme.

Les différentes fonctions utilisées par le programme sont réparties suivant 3 classes :

### la classe Alphabet :
Cette classe est définie selon un nom de fichier, une liste de caracteres, une map de fréquence de caractère, une liste de caracteres ordonnée et une paire représentant un couple de caractère et sa fréquence.
Elle permet de définir quels sont les caractères présents dans le fichier a compresser grâce à différents constructeurs et méthodes :
- set_caracteres : cette méthode permet de faire la liste de tous les caractères distints du fichier,
- set_frequence : cette méthode permet de définir la fréquence d'appartition d'un caractère dans le fichier,
- set_ordre : cette méthode permet de classer les caractères en fonction de leur fréquence d'apparition et de leur code ASCII,
- afficher_liste : cette méthode permet d'avoir un affichage dans l'invite de commande.
- enregistrer_alphabet : cette méthode permet de stocker l'alphabet utilisé avec la fréquence des caractères dans un fichier texte.

### la classe Noeud :
Elle est définie dans le fichier arbre.
Chaque noeud est défini selon un caractère, une fréquence et un fils gauche ou droit ainsi qu'un booléen feuille.
La classe permet de créer les noeuds et de gérer l'arbre de Huffman grâce à plusieurs méthodes :
- creer_noeuds : cette fonction permet, à partir d'un ensemble de couple caractère/fréquence, de créer les noeuds feuilles utilisés pour construire l'arbre d'Huffman. Elle renvoie un vecteur de noeuds.
- construire_arbre_huffman : cette méthode permet de construire l'arbre d'Huffman par récurrence depuis un vecteur de noeuds.
Ainsi, on va utiliser chaque noeud pour créer un noeud parent qui regroupera la fréquence de ces deux noeuds avant de supprimer les fils du vecteur
Ce processus se répère jusqu'à ce qu'il reste plus qu'un seul noeud dans le vecteur : le noeud racine de l'arbre d'Huffman.
- parcours_profondeur : depuis un noeud racine, cette méthode va parcourir l'arbre d'Huffman en profondeur donc tous les noeuds qui ont été créé avant. De cette façon, on obtient le code binaire associé à chaque feuille de l'arbre. En effet, à chaque fils gauche, on va associé la valeur "0" et à chaque fis droit la valeur "1" et ce, jusqu'à arriver à un noeud feuille par récurrece.

### la classe Compression :
Cette classe se définie en fonction du nom du fichier a compresser, du contenu de ce fichier et du codage du fichier.
La classe comprend 3 méthodes principales qui permettent de gérer l'aspect de codage et d'enregistrement du nouveau fichier :
- set_contenu_fichier : cette méthode permet de récupérer tout ce qui est contenu dans le fichier sous forme de chaine de caractère
- set_codage_fichier : cette méthode va parcourir chaque caractère du fichier (de la chaine de caractère obtenue avant) et lui associé son codage d'Huffman.
- stockage_fichier_compresse : cette dernière méthode permet de créer un nouveau fichier .bin et d'y stocker le texte codé.

La méthode taux_compression permet elle de déterminer le taux de compression obtenu grâce au codage d'Huffman.