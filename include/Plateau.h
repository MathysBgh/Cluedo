/*==============================================================================&
 | Fichier Headers                                                              |
 |                                                                              |
 | Projet Cluedo 2021                                                           |
 | Inge 2                                                                       |
 | Novembre 2021                                                                |
 +------------------------------------------------------------------------------|
 |Ce fichier contient toutes les ressources essentielles telles que structures  |
 |             librairies standard, definitions de types, Protorypes            |
 |              indispensables au fonctionnnement de notre jeu cluedo           |
 ==============================================================================*/

#ifndef PLATEAU_H
#define PLATEAU_H
/// Inclusion des librairies ///
#include <iostream>
#include <vector>
#include "Case.h"
#include "Joueur.h"
#include "Carte.h"


class Case;
class Joueur;

class Plateau //creation classe plateau
{

private:
    std::vector<std::vector<Case>> m_plateau; //creation d'un vecteur de type case



public:


    Plateau(); //constructeur
    //~Plateau();

    ///Getters

    std::vector<std::vector<Case>> getplateau()const;


    /// METHODES

    void majplateau(Joueur *a, Joueur *b, Joueur *c, Joueur *d);
    void afficher();
    void initialisation();
    void information1(int i,Joueur *a);
    void information2(int i,Joueur *a);
    void information3(int i,Joueur *a);
    void information4(int i,Joueur *a);

};

#endif // PLATEAU_H
