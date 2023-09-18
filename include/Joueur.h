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



#ifndef JOUEUR_H
#define JOUEUR_H

///  Inclusion des librairies ///
#include "Carte.h"
//#include "Console.h"
#include "Plateau.h"

#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stack>

class Plateau;
class Carte;

class Joueur //creation de la classe
{
    private: //attributs
        bool m_vie;
        std::string m_nom_joueur;
        std::string m_mdp;
        int m_posx, m_posy;
        int m_de;

        Suspect m_suspect;
        Lieu m_lieu;
        Arme m_arme;

    public:
        // Constructeurs et destructeur
        Joueur();
        Joueur(bool vie, std::string nom_joueur, int posx, int posy, int de);
        ~Joueur();

        //Getters
        std::string getNom_joueur()const;
        std::string getMdp()const;

        bool getVie ()const;
        int getPosx()const;
        int getPosy()const;
        int getLancer_de()const;
        Suspect getSuspect() const;
        Lieu getLieu() const;
        Arme getArme() const;

        //Setters
        void setNom_joueur(std::string nom_joueur);
        void setMdp(std::string mdp);
        void setVie (bool vie);
        void setPosx(int posx);
        void setPosy(int posy);
        void setSuspect(Suspect suspect);
        void setLieu(Lieu lieu);
        void setArme(Arme arme);
        void setLancer_de();

        //Méthodes

        void distribution(std::vector<Suspect> paquet_s, std::vector<Lieu> paquet_l, std::vector<Arme> paquet_a);

        void jouer();
        void deplacer(Plateau *plateau);
        int entrer(std::vector <Suspect> paquet_suspect, std::vector <Arme> paquet_arme, std::vector <Lieu> paquet_lieu, int k);
        void hypothese(std::vector <Suspect> paquet_suspect, std::vector <Arme> paquet_arme, std::vector <Lieu> paquet_lieu, int k);
        int accuser(std::vector <Suspect> paquet_suspect, std::vector <Arme> paquet_arme, std::vector <Lieu> paquet_lieu, int k);

        void sauvegarde1();
        void chargement1();
        void sauvegarde2();
        void chargement2();
        void sauvegarde3();
        void chargement3();
        void sauvegarde4();
        void chargement4();


};


// Sous-programmes
int StringToInt(std::string in);
void Erase_Line(std::string File, int Line_to_Erase); /* https://www.developpez.net/forums/d517517/c-cpp/cpp/contribuez/faq-cpp-supprimer-ligne-d-fichier/ */


#endif // JOUEUR_H
