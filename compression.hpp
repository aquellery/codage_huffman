// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <bitset>
#include <ios>
#include <vector>

#ifndef __COMPRESSION__
    #define __COMPRESSION__
    class Compression
    {
        public:
        //constructeur : la compression dépend d'un fichier
        Compression(const std:: string nom_fichier, const std::string nom_fichier_comp);
        //méthodes
        void set_contenu_fichier();
        std::string get_contenu_fichier();
        void set_codage_fichier(const std::unordered_map<char, std::string>& codes_binaires);
        std::string get_codage_fichier();

        void stockage_fichier_compresse(const std::string& codage);

        double calcul_taux_compression();

        double calcul_nombre_moyen_bits_stockage(std::vector<std::pair<char, int>> couple_caractere_frequence);

        private :
        std::string nom_fichier;
        std::string contenu_fichier;
        std::string codage_fichier;
        std::string nom_fichier_comp;

    };


#endif
