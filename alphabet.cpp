// Axelle ROY

// PROJ631 : Projet algorithmique
// Codage Huffman

#include "alphabet.hpp"

Alphabet::Alphabet(const std::string nomfichier):fichier(nomfichier) {
    std::cout<<"Creation de l'alphabet en cours : "<<std::endl;
}

std::string Alphabet::get_fichier() const  {
    return this->fichier;
}

std:: string Alphabet::get_caracteres() const{
    std::string result;
    if (!caracteres.empty()) {
        for (const auto& element : caracteres){
            result+=element;
            result+=" ";
        }
    }
    return result ;
}

// Fonction qui permet de définir quels sont les caractères présents dans le fichier
void Alphabet::set_caracteres(){
    // on veut stocker tous les caractères du fichier dans une liste de caractères
    std::list<char>caracteres{};
    std::ifstream file(fichier);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return;
    }
    char c;
    while (file.get(c)) {
        // on ajoute chaque caractère distinct du fichier dans la liste de caracteres
        bool caracterePresent = false;
        for(char ch : caracteres){ // on compare c aux caractères de la liste pour voir s'il est dedans
            if(c==ch){
                caracterePresent = true;
                break; // on sort de la boucle for
            }

        }
        // on ne prend pas en compte les espaces
        if (c != ' ' && !caracterePresent) {
            caracteres.push_back(c);
        }
    }
    file.close();
    //chaque caractere du fichier est stocké dans les caracteres de l'alphabet
    this->caracteres=caracteres;
}

// Fonction qui permet à chaque caractère présent dans le fichier d'y associer sa fréquence
void Alphabet::set_frequence(){
    std::ifstream file(fichier);
    std::unordered_map<char, int> frequence_caracteres;
    for(char &c:caracteres){
        while (file.get(c)){
            frequence_caracteres[c]++; // à chaque fois qu'on a le caractère c, on augmente sa fréquence
        }
    } 
    this->frequence_caracteres=frequence_caracteres;
    
    file.close();
}


std::unordered_map<char, int> Alphabet::get_frequence(){
    return this ->frequence_caracteres;
}

void Alphabet::afficher_frequence(){
    for (const auto& pair : frequence_caracteres) {
            std::cout << pair.first << " - " << pair.second << std::endl;
        }
}

// Fonction qui permet de trier les caractères par ordre de fréquence et par ordre codage des caractères ASCII
void Alphabet::set_ordre(){
    // on utilise un vecteur de paires à la place de la map (dictionnaire non ordonné)
    std::vector<std::pair<char, int>> liste_caracteres(frequence_caracteres.begin(), frequence_caracteres.end());

    // on va ensuite créer une nouvelle liste triée
    std::sort(liste_caracteres.begin(), liste_caracteres.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        if (a.second != b.second) { //.second correspond à la fréquence
            return a.second > b.second; // on trie donc par ordre croissant de fréquence
        } else {
            return a.first > b.first; //.first correspond au caractère, on trie donc par ordre ASCII
        }
    });
    this->couple_caractere_frequence=liste_caracteres;    
    // On ajoute maintenant chaque caractère dans une liste dans le bon ordre
    std::list<char> caracteres_ordonnes;
    for (const auto& p : liste_caracteres) {
        caracteres_ordonnes.push_back(p.first); 
    }
    this->caracteres_ordonnes=caracteres_ordonnes;

}

std::vector<std::pair<char, int>> Alphabet::get_couple_caractere_frequence(){
    return this->couple_caractere_frequence;
}

std::list<char> Alphabet::get_ordre(){
    return this ->caracteres_ordonnes;
}

// Affichage
void Alphabet::afficher_liste(std::list<char> liste){
    std::string result;
    if (!liste.empty()) {
        for (const auto& element : liste){
            result+=element;
            result+=" ";
        }
    std::cout << result << std::endl;
    }
}


void Alphabet::enregistrer_alphabet(std::string nom_fichier){
    std::ofstream fichier("donnees/alphabet/"+nom_fichier+"_freq.txt");

    if (!fichier.is_open()){
        std::cerr << "Probleme lors de l'ouverture du fichier pour l'enregistrement de l'alphabet" << std::endl;
    }

    // enregistrement du nombre de caractère dans le fichier
    fichier << couple_caractere_frequence.size()<< std::endl;

    // enregistrement de chaque couple caractère/fréquence :
    for (const auto& paire : couple_caractere_frequence) {
        fichier << paire.first << " " << paire.second << std::endl;
    }
    fichier.close();
}