#include "arbre.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

bool Noeud::feuille(){
    return (gauche==nullptr && droit==nullptr);
    //nullptr :  pointeur nul, autrement dit le noeud n'a pas de fils gauche ni de fils droit.
}

std::vector<Noeud*> Noeud::creer_noeuds(const std::vector<std::pair<char, int>>& couple) {
    std::vector<Noeud*> liste_noeuds;
    for (const auto& pair : couple) {
        Noeud* nouveau = new Noeud(pair.first, pair.second);
        liste_noeuds.push_back(nouveau);
    }
    return liste_noeuds;
}

void Noeud::afficher_noeud(){
    std::string result;
    result+=this->caractere;
    result+=" - frequence : ";
    result+=std::to_string(this->frequence);
    std::cout << result << std::endl;
}

Noeud* construire_arbre_huffman(std::vector<Noeud*> & liste_noeuds){
    //On va parcourir la liste des noeuds pour les placer dans l'arbre de Huffman
    while( liste_noeuds.size()>1){
        Noeud* gauche = liste_noeuds[0];
        Noeud* droit = liste_noeuds[1];
        //On supprime les deux premiers éléments de la liste
        liste_noeuds.erase(liste_noeuds.begin(), liste_noeuds.begin() + 2);
        //On crée un nouveau noeud qui aura comme fils gauche "gauche" et comme fils droit "droit"
        Noeud* noeud_parent=new Noeud('#', gauche->frequence + droit->frequence);
        noeud_parent->gauche=gauche;
        noeud_parent->droit=droit;

        // Ajouter le nouveau noeud à la liste
        liste_noeuds.push_back(noeud_parent);
    }
    // Quand il ne reste plus qu'un noeud dans la liste : c'est la racine de l'arbre
    return liste_noeuds[0];
}

void parcours_profondeur(Noeud* noeud, std::string code_binaire, std::unordered_map<char, std::string>& codes_binaires){
    if (noeud->feuille()){
        codes_binaires[noeud->caractere]=code_binaire;
    }
    else{
        parcours_profondeur(noeud->gauche, code_binaire+"0", codes_binaires);
        parcours_profondeur(noeud->droit, code_binaire+"1", codes_binaires);
    }
}
