// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include "compression.hpp"

Compression::Compression(const std::string nom_fichier, std::string nom_fichier_comp):nom_fichier(nom_fichier), nom_fichier_comp(nom_fichier_comp) {
    std::cout<<"Compression du fichier en cours : "<<std::endl;
}

void Compression::set_contenu_fichier(){
    //ouverture du fichier :
    std::ifstream fichier(nom_fichier);

    if (fichier.is_open()){
        // on va stocker le fichier dans  une chaine de caractère
        std::string contenu;
        // on lit le fichier ligne par ligne
        std::string ligne;
        while (std::getline(fichier, ligne)) {
            contenu+=ligne; 
        }
        fichier.close();
        contenu_fichier=contenu;
    }
    else{
        std::cerr<< "Impossible d'ouvrir le fichier"<<std::endl;
        contenu_fichier="";
    }
}

std::string Compression::get_contenu_fichier() {
    return this->contenu_fichier;
}


void Compression::set_codage_fichier(const std::unordered_map<char, std::string>& codes_binaires){
    std::string fichier_binaire;
    for (char caractere : contenu_fichier) {
        //on associe à chaque caractere du fichier son code binaire
        //std::cout<<"Caractere : "<< caractere<< " Code Binaire : "<<codes_binaires.at(caractere) <<std::endl;
        fichier_binaire+=codes_binaires.at(caractere);
    }
    codage_fichier=fichier_binaire;
}

std::string Compression::get_codage_fichier(){
    return this->codage_fichier;
}

void Compression::stockage_fichier_compresse(const std::string& codage) {
     // ouverture du fichier en mode binaire
    std::ofstream fichier(nom_fichier_comp, std::ios::binary);
    for (size_t i = 0; i < codage.size(); i += 8) {
        // Extraire une chaîne de 8 bits (un octet)
        std::string octet = codage.substr(i, 8);
        // Convertir la chaîne de bits en un entier (octet)
        unsigned char caractere = static_cast<unsigned char>(std::bitset<8>(octet).to_ulong());
        // Écrire l'octet dans le fichier
        fichier.write(reinterpret_cast<const char*>(&caractere), sizeof(caractere));
    }
    fichier.close();
}

