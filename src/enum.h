#ifndef __ENUM_H__
#define __ENUM_H__

enum class Joueur{
    humain,
    ordinateur,
    egalite
};

enum class Geste{
    pierre,
    feuille,
    ciseaux
};

struct Partie{
    Geste geste_ordinateur {0};
    Geste geste_humain {0};
    Joueur gagnant{Joueur::egalite};
};

#endif