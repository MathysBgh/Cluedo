#include "Carte.h"

///  Inclusion des librairies ///
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>


Carte::Carte()
{
    ///constructeur par défaut
}

Carte::Carte(std::string type_carte, bool m)
    :m_type_carte(type_carte), m_meurtrier(m)
{
    ///constructeur surchargé
}

Carte::~Carte()
{
    ///destructeur
}


bool Carte::getMeurtrier() const // type booleen avec un getter qui retourne l'attribut m_meurtrier
{
    return m_meurtrier;
}

void Carte::setMeurtrier(bool m) // declaration d'une méthode avec un setter afin de pouvoir modifier la variable
{
    m_meurtrier = m;
}
///--------------------------

/// creation de la classe suspect

Suspect::Suspect()
{

}

Suspect::Suspect(bool suspect_meurtrier, std::string nom_suspect)
    :m_suspect_meurtrier(suspect_meurtrier), m_nom_suspect(nom_suspect)
{
    /// constructeur surchargé
}

Suspect::~Suspect()
{
    /// destructeur
}

/// getter
std::string Suspect::getNom_suspect() const
{
    return m_nom_suspect;
}

///getter

bool Suspect::getSuspect_meurtrier()const
{
    return m_suspect_meurtrier;
}

///setter
void Suspect::setSuspect_meurtrier(bool suspect_meurtrier)
{
    m_suspect_meurtrier = suspect_meurtrier;
}
///setter
void Suspect::setNom_suspect(std::string nom_suspect)
{
    m_nom_suspect = nom_suspect;
}

void Suspect::chargement_enveloppe_suspect()
{
    /// Fichier en lecture
    std::ifstream monFlux("enveloppe_suspect.txt");
    if(monFlux)
    {
        std::string ligne1;

        getline(monFlux,ligne1);

        m_nom_suspect = ligne1;
        m_suspect_meurtrier = true;

        monFlux.close();
    }
}
///creation méthode pour la sauvegarde de l'enveloppe
void Suspect::sauvegarde_enveloppe_suspect()
{
    //creation
    std::string const nomFichier("enveloppe_suspect.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_suspect << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

///Nouvelle classe Lieu



Lieu::Lieu()
{

}

Lieu::Lieu(bool lieu_meurtrier, std::string nom_lieu)
    :m_lieu_meurtrier(lieu_meurtrier), m_nom_lieu(nom_lieu)
{
    ///constructeur surchargé
}

Lieu::~Lieu()
{
///destructeur
}


 ///getters
bool Lieu::getLieu_meurtrier()const
{
    return m_lieu_meurtrier;
}
std::string Lieu::getNom_lieu()const
{
    return m_nom_lieu;
}

///setters
void Lieu::setLieu_meurtrier(bool lieu_meurtrier)
{
    m_lieu_meurtrier = lieu_meurtrier;
}
void Lieu::setNom_lieu(std::string nom_lieu)
{
    m_nom_lieu = nom_lieu;
}

void Lieu::chargement_enveloppe_lieu()
{
    /// Fichier en lecture
    std::ifstream monFlux("enveloppe_lieu.txt");
    if(monFlux)
    {
        std::string ligne1;

        getline(monFlux,ligne1);

        m_nom_lieu = ligne1;
        m_lieu_meurtrier = true;

        monFlux.close();
    }
}

void Lieu::sauvegarde_enveloppe_lieu()
{
    std::string const nomFichier("enveloppe_lieu.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_lieu << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

///Création de la classe arme


Arme::Arme()
{

}

Arme::Arme(bool arme_meurtrier, std::string nom_arme)
    :m_arme_meurtrier(arme_meurtrier), m_nom_arme(nom_arme)
{
    //ctor surchargé
}

Arme::~Arme()
{

}


//Getters
bool Arme::getArme_meurtrier()const
{
    return m_arme_meurtrier;
}
std::string Arme::getNom_arme()const
{
    return m_nom_arme;
}

//Setters
void Arme::setArme_meurtrier(bool arme_meurtrier)
{
    m_arme_meurtrier = arme_meurtrier;
}
void Arme::setNom_arme(std::string nom_arme)
{
    m_nom_arme = nom_arme;
}


void Arme::chargement_enveloppe_arme()
{
    std::ifstream monFlux("enveloppe_arme.txt"); // Fichier en lecture
    if(monFlux)
    {
        std::string ligne1;

        getline(monFlux,ligne1);

        m_nom_arme = ligne1;
        m_arme_meurtrier = true;

        monFlux.close();
    }
}

void Arme::sauvegarde_enveloppe_arme()
{
    std::string const nomFichier("enveloppe_arme.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_arme << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
