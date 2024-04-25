// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include "alphabet.hpp"
#include "arbre.hpp"
#include "compression.hpp"

int main(int argc, char *argv[]) {
  std::string nom_fichier=argv[1];
  Alphabet alphabet{"donnees/"+nom_fichier+".txt"};
  // étape 1 : on définit l'alphabet du fichier
  alphabet.set_caracteres();
  std::string caracteres_fichier=alphabet.get_caracteres();  

  // étape 2 : on définit la fréquence de chaque caractère du fichier
  alphabet.set_frequence(); 
  //alphabet.afficher_frequence();

  // étape 3 : on trie les caractères par ordre de fréquence et par ordre codage des caractères ASCII
  alphabet.set_ordre();
  std::list<char> caracteres_ordonnes=alphabet.get_ordre();
  std::cout<<"Liste de caracteres triee : " <<std::endl;
  alphabet.afficher_liste(caracteres_ordonnes);

  // étape 4 : on enregistre l'alphabet dans un fichier txt
  std::cout << "Enregistrement de l'alphabet en cours" <<std::endl;
  alphabet.enregistrer_alphabet(nom_fichier);

  // étape 5 : on créé les noeuds associé à chaque couple de caractère-fréquence
  std::vector<std::pair<char, int>> couple_car_freq=alphabet.get_couple_caractere_frequence();
  
  std::vector<Noeud*> liste_noeuds=Noeud::creer_noeuds(couple_car_freq);
  for (Noeud* noeud : liste_noeuds){
    noeud->afficher_noeud();
  }
  Noeud* racine=construire_arbre_huffman(liste_noeuds);
  std::cout << "Noeud racine de l'arbre : " << std::endl;
  racine->afficher_noeud();

  // étape 6 : on parcours l'arbre en profondeur (depuis la racine vers les feuilles) pour déterminer le codage binaire associé à chaque caractères
  std::unordered_map<char, std::string> codes_binaires;
  parcours_profondeur(racine, "", codes_binaires);
  // affichage des codes générés :
   std::cout << "Codes binaires :\n";
    for (const auto& [caractere, code] : codes_binaires) {
        std::cout <<  caractere << " -  code associe : " << code << std::endl;
    }

  // étape 7 : on parcours le fichier pour créer le fichier codé 
  Compression comp{"donnees/"+nom_fichier+".txt", "donnees/compression/"+nom_fichier+"_comp.bin"};
  std::cout <<"Codage du fichier en cours "<< std::endl;
  comp.set_contenu_fichier();
  comp.set_codage_fichier(codes_binaires);
  std::string codage=comp.get_codage_fichier();
  if(codage.size()<1000){
    std::cout <<codage<<std::endl;
  }

  // étape 8 : on enregistre le codage dans un nouveau fichier
  std::cout <<"Enregistrement du nouveau fichier en cours "<< std::endl;
  comp.stockage_fichier_compresse(codage);

  // étape 9 : on détermine le taux de compression du fichier obtenu
  double taux_compression=comp.calcul_taux_compression();
  std::cout<<"Taux de compression : " << taux_compression*100 << "%" << std::endl;

  // étape 10 : on détermine le nombre moyen de bits de stockage d’un caractère du texte compressé
  double nombre_moyen = comp.calcul_nombre_moyen_bits_stockage(couple_car_freq);
  std::cout <<"Nombre moyen de bits de stockage d'un caractere du texte compresse : "<< nombre_moyen << std::endl;


  return 0;
}
