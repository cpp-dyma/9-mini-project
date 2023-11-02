#include "enum.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

/// @brief Définit lequel des deux joueurs a gagné le combat
/// @param geste_j1 Geste réalisé par le 1er joueur
/// @param geste_j2 Geste réalisé par le 2eme joueur
/// @return Retourne le joueur vainqueur
Joueur definirGagnant(Geste geste_j1, Geste geste_j2){

    ///Gestion des 9 (3 x 3) cas

    if(geste_j1 == Geste::pierre){
        if(geste_j2==Geste::pierre){
            return Joueur::egalite;
        } else if(geste_j2==Geste::feuille){
            return Joueur::j2;
        } else{
            return Joueur::j1;
        }
    } else if(geste_j1 == Geste::feuille) {
        if(geste_j2==Geste::pierre){
            return Joueur::j1;
        } else if(geste_j2==Geste::feuille){
            return Joueur::egalite;
        } else{
            return Joueur::j2;
        }
    } else if(geste_j1 == Geste::ciseaux) {
        if(geste_j2==Geste::pierre){
            return Joueur::j2;
        } else if(geste_j2==Geste::feuille){
            return Joueur::j1;
        } else{
            return Joueur::egalite;
        }
    }

    return Joueur::egalite;
}

Geste obtenirGesteAleatoire(){
    auto random_value {std::rand()};
    auto random_1_3 {(random_value%3) +1};

    Geste random_geste {static_cast<Geste>(random_1_3)};
    return random_geste;
}

int main(){
    std::srand(time(nullptr));

    for(auto i{0} ; i<15 ; i++){
        obtenirGesteAleatoire();
    }

    return 0;
}