#include <string>
#include <list>

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
        void set_caracteres(const std::string fichier); //on travaille sur un seul fichier

        private :
        std::string fichier;
        std::list<char>caracteres{};
    };
#endif