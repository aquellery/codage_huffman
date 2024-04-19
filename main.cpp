// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "alphabet.hpp"
#include "affichage.hpp"
#include "arbre.hpp"


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

  //étape 4 : on créé les noeuds associé à chaque couple de caractère-fréquence
  std::vector<std::pair<char, int>> couple_car_freq=alphabet.get_couple_caractere_frequence();
  std::vector<Noeud*> liste_noeuds=Noeud::creer_noeuds(couple_car_freq);
  for (Noeud* noeud : liste_noeuds){
    noeud->afficher_noeud();
  }

  Noeud* racine=construire_arbre_huffman(liste_noeuds);
  racine->afficher_noeud();

  return 0;
}
