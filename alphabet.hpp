// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_map>

#ifndef __ALPHABET__
    #define __ALPHABET__
    class Alphabet
    {
        public :
        //constructeur : l'alphabet dépend d'un fichier
        Alphabet(const std:: string fichier);
        //méthodes :
        std::string get_fichier() const;
        std::string get_caracteres() const; // méthode de test pour afficher les caractères de l'alphabet
        void set_caracteres(); //on travaille sur un seul fichier
        
        void set_frequence();
        std::unordered_map<char, int> get_frequence();
        void afficher_frequence();
        std::vector<std::pair<char, int>> get_couple_caractere_frequence();

        void set_ordre();
        std::list<char> get_ordre();

        void afficher_liste(std::list<char> liste);

        void enregistrer_alphabet(std::string nom_fichier);

        private :
        std::string fichier;
        std::list<char>caracteres{};
        std::unordered_map<char, int> frequence_caracteres;
        std::list<char> caracteres_ordonnes{};
        std::vector<std::pair<char, int>> couple_caractere_frequence;

    };
#endif