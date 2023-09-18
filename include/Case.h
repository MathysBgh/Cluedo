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


#ifndef CASE_H
#define CASE_H

#include "Joueur.h"

class Joueur; //creation de la classe

class Case
{
    private: //attributs dans le privé
        int m_type;
        char m_affichage;
        Joueur *m_joueur;

    public:
        Case(); // constructeur
        Case (int numero_case); //surchargé
        ~Case(); //destructeur

        //Getters
        int getType()const;
        Joueur getJoueur()const;
        char getAffichage()const;

        //Setters
        void setType(int m_type);
        void setJoueur(Joueur *joueur);
        void setAffichage(char affichage);

        //Méthodes
};

#endif // CASE_H
