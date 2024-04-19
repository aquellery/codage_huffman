// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include <iostream>
#include <string>
#include "alphabet.hpp"
#include "affichage.hpp"


int main() {
  Alphabet alphabet{"donnees/textesimple.txt"};
  Affichage aff{};
  // étape 1 : on définit l'alphabet du fichier
  alphabet.set_caracteres();
  std::string caracteres_fichier=alphabet.get_caracteres();  
  aff.afficher_string(caracteres_fichier);
  // étape 2 : on définit la fréquence de chaque caractère du fichier
  alphabet.set_frequence(); 
  //alphabet.afficher_frequence();
  // étape 3 : on trie les caractères par ordre de fréquence et par ordre codage des caractères ASCII
  alphabet.set_ordre();
  std::list<char> caracteres_ordonnes=alphabet.get_ordre();
  aff.afficher_liste(caracteres_ordonnes);

  return 0;
}
