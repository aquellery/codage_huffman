// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include "arbre.hpp"

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
    //std::cout << "Affichage de l'arbre en cours : " << std::endl;
    //On va parcourir la liste des noeuds pour les placer dans l'arbre de Huffman
    while( liste_noeuds.size()>1){
        // le noeud droit correspond au dernier noeud et le gauche à l'avant dernier
        Noeud* droit=liste_noeuds.back(); 
        Noeud* gauche=liste_noeuds[liste_noeuds.size()-2];
        //On supprime les deux noeuds de la liste (les deux derniers éléments)
        liste_noeuds.pop_back();
        liste_noeuds.pop_back();
        //On crée un nouveau noeud qui aura comme fils gauche "gauche" et comme fils droit "droit"
        char char_gauche=gauche->caractere;
        Noeud* noeud_parent=new Noeud(char_gauche, gauche->frequence+droit->frequence);
        noeud_parent->gauche=gauche;
        noeud_parent->droit=droit;
        // On ajoute le nouveau noeud à la liste
        liste_noeuds.push_back(noeud_parent);
        // on retrie la liste en fonction de la fréquence du nouveau noeud parent
        std::sort(liste_noeuds.begin(), liste_noeuds.end(), [](Noeud* a, Noeud* b) {
            return a->frequence > b->frequence;
        });
        // affichage test
        /*
        std::cout<<"Noeud gauche : " << std::endl;
        gauche->afficher_noeud();
        std::cout<< "Noeud droit : " << std::endl;
        droit->afficher_noeud();
        std::cout <<"Noeud parent : " <<std::endl;
        noeud_parent->afficher_noeud();
        std::cout <<"Liste de nouveau triee : " <<std::endl;
        for (Noeud* noeud : liste_noeuds){
            noeud->afficher_noeud();
        }
        std::cout << "-------------" <<std::endl;
        */
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
