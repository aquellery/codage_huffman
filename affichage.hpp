#include <string>
#include <list>

#ifndef __AFFICHAGE__
    #define __AFFICHAGE__
    class Affichage
    {
        public :
        //constructeur
        Affichage();

        //méthodes
        void afficher_liste(std::list<char> liste);
        void afficher_string(std::string str);


    };
#endif

