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
void definirGagnant(Partie &partie){

    ///Gestion des 9 (3 x 3) cas

    if(partie.geste_humain == Geste::pierre){
        if(partie.geste_ordinateur==Geste::pierre){
            partie.gagnant = Joueur::egalite;
        } else if(partie.geste_ordinateur==Geste::feuille){
            partie.gagnant = Joueur::ordinateur;
        } else{
            partie.gagnant = Joueur::humain;
        }
    } else if(partie.geste_humain == Geste::feuille) {
        if(partie.geste_ordinateur==Geste::pierre){
            partie.gagnant = Joueur::humain;
        } else if(partie.geste_ordinateur==Geste::feuille){
            partie.gagnant = Joueur::egalite;
        } else{
            partie.gagnant = Joueur::ordinateur;
        }
    } else if(partie.geste_humain == Geste::ciseaux) {
        if(partie.geste_ordinateur==Geste::pierre){
            partie.gagnant = Joueur::ordinateur;
        } else if(partie.geste_ordinateur==Geste::feuille){
            partie.gagnant = Joueur::humain;
        } else{
            partie.gagnant = Joueur::egalite;
        }
    }
}

/// @brief Utilise l'aléatoire pour générer un des 3 gestes disponibles en aléatoire
/// @return Retourne un geste aléatoire
Geste obtenirGesteAleatoire(){
    auto random_value {std::rand()};
    auto random_1_3 {(random_value%3)};

    Geste random_geste {static_cast<Geste>(random_1_3)};
    return random_geste;
}

void ecrireInstructions(){
    cout<<"****************************"<<endl;
    cout<<"Tapez un chiffre en fonction de votre choix"<<endl;
    cout<<"** 0 pour quitter"<<endl;
    cout<<"** 1 pour pierre"<<endl;
    cout<<"** 2 pour feuille"<<endl;
    cout<<"** 3 pour ciseaux"<<endl;
    cout<<"Tapez votre choix pour appuyez sur Entree : ";
}

void ecrireGeste(Geste geste){
    switch(geste){
        case Geste::pierre:
        cout<<"pierre";
        break;

        case Geste::feuille:
        cout<<"feuille";
        break;

        case Geste::ciseaux:
        cout<<"ciseaux";
        break;

        default:
        cout<<"Inconnu ??";
        break;
    }
}

void ecrireResultat(Partie partie){
    cout<<"Vous avez joué ";
    ecrireGeste(partie.geste_humain);
    cout<<endl<<"L'ordinateur a joué ";
    ecrireGeste(partie.geste_ordinateur);
    cout<<endl;
    

    switch(partie.gagnant){
        case Joueur::egalite:
        cout<<"Egalité !"<<endl;
        break;

        case Joueur::humain:
        cout<<"Bravo vous avez gagné !"<<endl;
        break;

        case Joueur::ordinateur:
        cout<<"Vous avez perdu..."<<endl;
        break;

        default:
        cout<<"Joueur indéfini :-o"<<endl;
        break;
    }
}

int main(){
    /// Mélange l'aléatoire
    std::srand(time(nullptr));
    std::setlocale(LC_ALL, ".utf8");
    auto choix{0};
    auto points_ordinateur{0}, points_humain{0};

    do{
        ecrireInstructions();
        cin>>choix;

        if(choix>0){
            system("cls");
            Geste geste_ordinateur{obtenirGesteAleatoire()};
            Geste geste_humain{choix-1};

            Partie partie{geste_ordinateur, geste_humain};

            definirGagnant(partie);

            if(partie.gagnant==Joueur::humain)
                points_humain++;
            else if(partie.gagnant==Joueur::ordinateur)
                points_ordinateur++;

            ecrireResultat(partie);

            cout<<"****************************"<<endl;
            cout<<"Récapitulatif des points :"<<endl;
            cout<<"Vous : "<<points_humain<<endl;
            cout<<"Ordinateur : "<<points_ordinateur<<endl;

        }
    }while(choix>0);

    return 0;
}