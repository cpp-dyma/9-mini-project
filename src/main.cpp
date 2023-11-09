#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Ecrit dans la console la liste des différents choix
 * 0 : Quitter
 * 1 : Pierre
 * 2 : Feuille
 * 3 : Ciseaux
 */
void ecrireInstructions(){
    using std::cout;
    using std::endl;

    cout<<"Bienvenue dans le jeu pierre feuille ciseaux !"<<endl;
    cout<<"Pour jouer, tapez votre choix, puis pressez la touche Entrée"<<endl;
    cout<<"** 0 pour quitter"<<endl;
    cout<<"** 1 pour pierre"<<endl;
    cout<<"** 2 pour feuille"<<endl;
    cout<<"** 3 pour ciseaux"<<endl;
    cout<<"Quel est votre choix : ";
}

/**
 * @brief Ecris dans la console le nom du geste passé en argument
 * 
 * @param geste 
 */
void ecrireGeste(const Geste geste){

    switch (geste)
    {
    case Geste::pierre:
        std::cout<<"pierre";
        break;

    case Geste::feuille:
        std::cout<<"feuille";
        break;

    case Geste::ciseaux:
        std::cout<<"ciseaux";
        break;
    
    default:
        std::cout<<"Geste inconnu";
        break;
    }
}

/**
 * @brief Affiche dans la console le nom du gagnant
 * 
 */
void afficherResultats(const Vainqueur vainqueur, const Geste coup_ordinateur, const Geste coup_humain, const int score_ordinateur, const int score_humain){

    std::cout<<"L'humain a joué ";
    ecrireGeste(coup_humain);
    std::cout<<". L'ordinateur a joué ";
    ecrireGeste(coup_ordinateur);
    std::cout<<std::endl;

    if(vainqueur==Vainqueur::egalite){
        std::cout<<"Egalité !"<<std::endl;
    } else {
        std::cout<<"Le vainqueur est "<< (vainqueur==Vainqueur::ordinateur ? "l'ordinateur":"l'humain")<<std::endl;
    }

    std::cout<<"********** Résumé des scores **********"<<std::endl;
    std::cout<<"Humain : "<<score_humain<<" points"<<std::endl;
    std::cout<<"Ordinateur : "<<score_ordinateur<<" points"<<std::endl;
    std::cout<<"***************************************"<<std::endl;
}

/**
 * @brief Défini qui, de l'ordinateur ou de l'humaine a gagné
 * 
 * @param coup_humain : geste joué par l'humain
 * @param coup_ordinateur : geste joué par l'ordinateur
 * @return Vainqueur 
 */
Vainqueur definirGagnant(const Geste coup_humain, const Geste coup_ordinateur){

    if(coup_humain == Geste::pierre){
        if(coup_ordinateur==Geste::pierre){
            return Vainqueur::egalite;
        } else if(coup_ordinateur==Geste::feuille){
            return Vainqueur::ordinateur;
        } else if(coup_ordinateur==Geste::ciseaux){
            return Vainqueur::humain;
        }
    } else if(coup_humain==Geste::feuille){
        if(coup_ordinateur==Geste::pierre){
            return Vainqueur::humain;
        } else if(coup_ordinateur==Geste::feuille){
            return Vainqueur::egalite;
        } else if(coup_ordinateur==Geste::ciseaux){
            return Vainqueur::ordinateur;
        }
    } else if(coup_humain==Geste::ciseaux){
        if(coup_ordinateur==Geste::pierre){
            return Vainqueur::ordinateur;
        } else if(coup_ordinateur==Geste::feuille){
            return Vainqueur::humain;
        } else if(coup_ordinateur==Geste::ciseaux){
            return Vainqueur::egalite;
        }
    }

    std::cout<<"Coups inconnus, résultat indéfini..."<<std::endl;
    return Vainqueur::egalite;
}

/**
 * @brief Obtient un geste aléatoire grâce à rand()
 * 
 * @return Geste : geste joué par l'ordinateur
 */
Geste obtenirGesteAleatoire(){

    auto random_value {rand()%3};
    return static_cast<Geste>(random_value);
}

int main(){

    //Mélanger l'aléatoire
    std::srand(time(nullptr));
    //Régler le problème d'accent sur Windows
    std::setlocale(LC_ALL, ".utf8");

    int choix_utilisateur{0};
    auto score_ordinateur{0}, score_humain{0};

    do{
        //Affiche les règles
        ecrireInstructions();
        std::cin>>choix_utilisateur;

        //Contrôle de la saisie
        if(choix_utilisateur<0 || choix_utilisateur > 3 ){
            std::cout<<"Saisie invalide, recommencez !"<<std::endl;
            continue;
        }

        //Sortie de la boucle en cas de 0
        if(choix_utilisateur==0){
            break;
        }

        Geste coup_humain {static_cast<Geste>(choix_utilisateur-1)};
        Geste coup_ordinateur;
        coup_ordinateur = obtenirGesteAleatoire();        

        Vainqueur gagnant {definirGagnant(coup_humain, coup_ordinateur)};

        //Incrémentation des scores
        if(gagnant==Vainqueur::ordinateur)
            score_ordinateur++;
        else if(gagnant==Vainqueur::humain)
            score_humain++;

        //Nettoyage de la console
        system("cls");

        afficherResultats(gagnant, coup_ordinateur, coup_humain, score_ordinateur, score_humain);

    } while(choix_utilisateur!=0);

    return 0;
}