#include "alphabet.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

Alphabet::Alphabet(const std::string nomfichier):fichier(nomfichier)
{
    std::cout<<"Creation de l'alphabet"<<std::endl;
}

std::string Alphabet::get_fichier() const  
{
    return this->fichier;
}

std:: string Alphabet::get_caracteres() const
{
    std::string result;
    if (!caracteres.empty()) {
        for (const auto& element : caracteres){
            result+=element;
            result+=" ";
        }
    std::cout << result << std::endl;
    }
    return result ;
}

void Alphabet::set_caracteres(const std::string fichier){
    // on veut stocker tous les caractères du fichier dans une liste de caractères
    std::list<char>caracteres{};
    std::ifstream file(fichier);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return;
    }
    char c;
    while (file.get(c)) {
        // on ajoute chaque caractère du fichier dans la liste de caracteres
        // on ne prend pas en compte les espaces
        if (c != ' ')
            caracteres.push_back(c);
    }
    file.close();
    //chaque caractere du fichier est stocké dans les caracteres de l'alphabet
    this->caracteres=caracteres;
}
