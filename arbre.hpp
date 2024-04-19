#include <string>
#include <list>
#include <vector>
#include <utility>
#include <iostream>

#ifndef __ARBRE__
    #define __ARBRE__
    class Noeud
    {
        public:
        char caractere;
        int frequence;
        Noeud* gauche;
        Noeud* droit; 

        Noeud(char c, int f): caractere(c), frequence(f), gauche(nullptr), droit(nullptr){};
        bool feuille();

        static std::vector<Noeud*> creer_noeuds(const std::vector<std::pair<char, int>>& couple);

        void afficher_noeud();

    };

    Noeud* construire_arbre_huffman(std::vector<Noeud*>& liste_noeuds);
    
#endif
