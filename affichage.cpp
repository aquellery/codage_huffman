#include "affichage.hpp"
#include <iostream>

Affichage::Affichage(){
}

void Affichage::afficher_liste(std::list<char> liste){
    std::string result;
    if (!liste.empty()) {
        for (const auto& element : liste){
            result+=element;
            result+=" ";
        }
    std::cout << result << std::endl;
    }
}

void Affichage::afficher_string(std::string str){
     std::cout << str << std::endl;
}