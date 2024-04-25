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

double Compression::calcul_taux_compression(){
    std::ifstream fichier_initial(nom_fichier);
    std::ifstream fichier_comp(nom_fichier_comp);
    if (!fichier_initial.is_open() |!fichier_comp.is_open()) { // |= ou
        std::cerr << "Probleme lors de l'ouverture d'un des fichier" << std::endl;
        return -1;
    }

    // taille du fichier initial :
    fichier_initial.seekg(0, std::ios::end);
    std::streampos taille_initiale = fichier_initial.tellg();
    //std::cout<<"Taille initiale : "<< taille_initiale<<std::endl;
    fichier_initial.close();
    // taille du fichier compressé :
    fichier_comp.seekg(0, std::ios::end);
    std::streampos taille_comp = fichier_comp.tellg();
    //std::cout<<"Taille compressee : "<< taille_comp<<std::endl;
    fichier_comp.close();

    // conversion des tailles des fichiers pour faire le calcul
    double taille_initiale_float = static_cast<double>(taille_initiale);
    double taille_comp_float = static_cast<double>(taille_comp);
    
    // calcul du taux : 
    float taux_compression=1-(taille_comp_float/taille_initiale_float);
    return taux_compression;  
}

double Compression::calcul_nombre_moyen_bits_stockage(std::vector<std::pair<char, int>> couple_caractere_frequence){
    //ouverture du fichier en mode binaire
    std::ifstream fichier_comp(nom_fichier_comp, std::ios::binary);
    if (!fichier_comp.is_open()) {
        std::cerr << "Probleme lors de l'ouverture du fichier compresse" << std::endl;
        return -1;
    }

    // récupération du nombre de bits dans le fichier compressé
    int bits_fichier_comp=0;
    char c;
    while (fichier_comp.get(c)) {
        bits_fichier_comp+=8; // chaque caractère contient 8 bits puisque le fichier a été comprimé octet par octet
    }
    
    double moyenne_bits_par_caractere_compresses=0;
    for (const auto& couple : couple_caractere_frequence) {
        moyenne_bits_par_caractere_compresses+=(couple.second*8); //chaque caractère est codé sur 8 bits donc la fréquence est multipliée par 8
    }
    // on peut maintenant diviser par le nombre de bits présents dans le fichier compressé pour obtenir la moyenne.
    moyenne_bits_par_caractere_compresses/=bits_fichier_comp;

    // fermeture du fichier
    fichier_comp.close();

    return moyenne_bits_par_caractere_compresses;
}