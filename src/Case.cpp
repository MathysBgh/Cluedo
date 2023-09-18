#include "Case.h"

///  Inclusion des librairies ///
#include <vector>
#include <iostream>

Case::Case()
{
    ///constructeur
}

Case::Case(int type)
    :m_type(type)
{
///destructeur
}

Case::~Case()
{
    ///constructeur
}

///Getters
int Case::getType()const
{
    return m_type;
}

Joueur Case::getJoueur()const
{
    return *m_joueur;
}

char Case::getAffichage()const
{
    return m_affichage;
}



///Setters
void Case::setType(int type)
{
    m_type = type;
}

void Case::setJoueur(Joueur *joueur)
{
    m_joueur = joueur;
}

void Case::setAffichage(char affichage)
{
    m_affichage = affichage;
}
