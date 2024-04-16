// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include <iostream>
#include <string>
#include "alphabet.hpp"

int main() {
  Alphabet a{"donnees/textesimple.txt"};
  std::string fichier_a_traiter=a.get_fichier();
  a.set_caracteres(fichier_a_traiter);   
  a.get_caracteres();
  return 0;
}