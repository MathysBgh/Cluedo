///  Inclusion des fichiers.h ///
#include "Joueur.h"
#include "Carte.h"
#include "Console.h"
///  Inclusion des librairies ///
#include <iostream>


Joueur::Joueur()
{

}
/// constructeur surchargé
Joueur::Joueur(bool vie, std::string nom_joueur, int posx, int posy, int de)
    :m_vie(vie), m_nom_joueur(nom_joueur), m_posx(posx), m_posy(posy), m_de()
{

}

Joueur::~Joueur()
{
    ///destructeur
}


///getters
std::string Joueur::getNom_joueur()const
{
    return m_nom_joueur;
}
std::string Joueur::getMdp()const
{
    return m_nom_joueur;
}
bool Joueur::getVie ()const
{
    return m_vie;
}
int Joueur::getPosx()const
{
    return m_posx;
}
int Joueur::getPosy()const
{
    return m_posy;
}
Suspect Joueur::getSuspect() const
{
    return m_suspect;
}
Lieu Joueur::getLieu() const
{
    return m_lieu;
}
Arme Joueur::getArme() const
{
    return m_arme;
}


///setter pour pouvoir modifier
void Joueur::setNom_joueur(std::string nom_joueur)
{
    m_nom_joueur = nom_joueur;
}


void Joueur::setMdp(std::string mdp)
{
    m_mdp = mdp;
}

void Joueur::setVie (bool vie)
{
    m_vie = vie;
}

void Joueur::setPosx(int posx)
{
    m_posx = posx;
}
void Joueur::setPosy(int posy)
{
    m_posy = posy;
}
void Joueur::setSuspect(Suspect suspect)
{
    m_suspect = suspect;
}
void Joueur::setLieu(Lieu lieu)
{
    m_lieu = lieu;
}
void Joueur::setArme(Arme arme)
{
    m_arme = arme;
}

/// fichier sauvegarde pour tous les joueurs

void Joueur::sauvegarde1()
{
    std::string const nomFichier("Joueur1.txt"); // nom du fichier
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_joueur << std::endl;
        monFlux << m_mdp << std::endl;
        monFlux << m_suspect.getNom_suspect() << std::endl;
        monFlux << m_lieu.getNom_lieu() << std::endl;
        monFlux << m_arme.getNom_arme() << std::endl;
        monFlux << m_posx << std::endl;
        monFlux << m_posy << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}


void Joueur::sauvegarde2()
{
    std::string const nomFichier("Joueur2.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_joueur << std::endl;
        monFlux << m_mdp << std::endl;
        monFlux << m_suspect.getNom_suspect() << std::endl;
        monFlux << m_lieu.getNom_lieu() << std::endl;
        monFlux << m_arme.getNom_arme() << std::endl;
        monFlux << m_posx << std::endl;
        monFlux << m_posy << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void Joueur::sauvegarde3()
{
    std::string const nomFichier("Joueur3.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_joueur << std::endl;
        monFlux << m_mdp << std::endl;
        monFlux << m_suspect.getNom_suspect() << std::endl;
        monFlux << m_lieu.getNom_lieu() << std::endl;
        monFlux << m_arme.getNom_arme() << std::endl;
        monFlux << m_posx << std::endl;
        monFlux << m_posy << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void Joueur::sauvegarde4()
{
    std::string const nomFichier("Joueur4.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << m_nom_joueur << std::endl;
        monFlux << m_mdp << std::endl;
        monFlux << m_suspect.getNom_suspect() << std::endl;
        monFlux << m_lieu.getNom_lieu() << std::endl;
        monFlux << m_arme.getNom_arme() << std::endl;
        monFlux << m_posx << std::endl;
        monFlux << m_posy << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
///fichier en lecture
void Joueur::chargement1()
{
    std::ifstream monFlux("Joueur.txt");
    if(monFlux)
    {
        std::string ligne1, ligne2, ligne3, ligne4, ligne7;
        int ligne5, ligne6;

        getline(monFlux,ligne1);
        getline(monFlux,ligne7);
        getline(monFlux,ligne2);
        getline(monFlux,ligne3);
        getline(monFlux,ligne4);
        monFlux >> ligne5;
        monFlux >> ligne6;

        m_nom_joueur = ligne1;
        m_mdp = ligne7;
        m_suspect.setNom_suspect(ligne2);
        m_lieu.setNom_lieu(ligne3);
        m_arme.setNom_arme(ligne4);
        m_posx = ligne5;
        m_posy = ligne6;

        monFlux.close();
    }
}


void Joueur::chargement2()
{
    ///fichier en lecture ///
    std::ifstream monFlux("Joueur2.txt");
    if(monFlux)
    {
        std::string ligne1, ligne2, ligne3, ligne4, ligne7;
        int ligne5, ligne6;

        getline(monFlux,ligne1);
        getline(monFlux,ligne7);
        getline(monFlux,ligne2);
        getline(monFlux,ligne3);
        getline(monFlux,ligne4);
        monFlux >> ligne5;
        monFlux >> ligne6;

        m_nom_joueur = ligne1;
        m_mdp = ligne7;
        m_suspect.setNom_suspect(ligne2);
        m_lieu.setNom_lieu(ligne3);
        m_arme.setNom_arme(ligne4);
        m_posx = ligne5;
        m_posy = ligne6;

        monFlux.close();
    }
}

void Joueur::chargement3()
{
    ///fichier en lecture///
    std::ifstream monFlux("Joueur3.txt");
    if(monFlux)
    {
        std::string ligne1, ligne2, ligne3, ligne4, ligne7;
        int ligne5, ligne6;

        getline(monFlux,ligne1);
        getline(monFlux,ligne7);
        getline(monFlux,ligne2);
        getline(monFlux,ligne3);
        getline(monFlux,ligne4);
        monFlux >> ligne5;
        monFlux >> ligne6;

        m_nom_joueur = ligne1;
        m_mdp = ligne7;
        m_suspect.setNom_suspect(ligne2);
        m_lieu.setNom_lieu(ligne3);
        m_arme.setNom_arme(ligne4);
        m_posx = ligne5;
        m_posy = ligne6;

        monFlux.close();
    }
}

void Joueur::chargement4()
{
    ///fichier en lecture ///
    std::ifstream monFlux("Joueur4.txt");
    if(monFlux)
    {
        std::string ligne1, ligne2, ligne3, ligne4, ligne7;
        int ligne5, ligne6;

        getline(monFlux,ligne1);
        getline(monFlux,ligne7);
        getline(monFlux,ligne2);
        getline(monFlux,ligne3);
        getline(monFlux,ligne4);
        monFlux >> ligne5;
        monFlux >> ligne6;

        m_nom_joueur = ligne1;
        m_mdp = ligne7;
        m_suspect.setNom_suspect(ligne2);
        m_lieu.setNom_lieu(ligne3);
        m_arme.setNom_arme(ligne4);
        m_posx = ligne5;
        m_posy = ligne6;

        monFlux.close();
    }
}


void distribution(std::vector<Suspect> paquet_s, std::vector<Lieu> paquet_l, std::vector<Arme> paquet_a)
{
//    joueur.m_suspect;
}
///setter
void Joueur::setLancer_de()
{
    m_de = rand()%7+6; // de facon aléatoire
}
///getter
int Joueur::getLancer_de()const
{
    return m_de;
}


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ////////// Sous-programmes //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Joueur::deplacer(Plateau *plateau)
{
    bool quit = false;
    int key = 0;
    Console* pConsole = NULL;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    while (quit == false)
    {
        /// Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            /// Récupère le code ASCII de la touche
            key = pConsole->getInputKey();

            if (key == 122 || key == 115 || key == 113 || key == 100)
            {

                if(key == 122) ///haut
                    //blindage si le joueur essaye de passer autre part que sur le chemin...
                    if (plateau->getplateau()[m_posx-1][m_posy].getType() == 0 || plateau->getplateau()[m_posx-1][m_posy].getType() == 13 || plateau->getplateau()[m_posx-1][m_posy].getType() == 99)
                    {
                        m_posx--;
                    }
                    else
                    {
                        // message d'erreur
                        std::cout << "Deplacement impossible !" << std::endl ;
                        Sleep(500);
                    }

                if (key == 115) ///bas
                {
                    //blindage si le joueur essaye de passer autre part que sur le chemin...
                    if (plateau->getplateau()[m_posx+1][m_posy].getType() == 0 || plateau->getplateau()[m_posx+1][m_posy].getType() == 13 || plateau->getplateau()[m_posx+1][m_posy].getType() == 99)
                    {
                        m_posx++;
                    }
                    else
                    {
                        // message d'erreur
                        std::cout << "Deplacement impossible !" << std::endl ;
                        Sleep(500);
                    }
                }
                if(key == 113) ///gauche
                {
                    //blindage si le joueur essaye de passer autre part que sur le chemin...
                    if (plateau->getplateau()[m_posx][m_posy-1].getType() == 0 || plateau->getplateau()[m_posx][m_posy-1].getType() == 13 || plateau->getplateau()[m_posx][m_posy-1].getType() == 99)
                    {
                        m_posy--;
                    }
                    else
                    {
                        // message d'erreur
                        std::cout << "Deplacement impossible !" << std::endl ;
                        Sleep(500);
                    }
                }
                if(key == 100) ///droite
                {
                    //blindage si le joueur essaye de passer autre part que sur le chemin...
                    if (plateau->getplateau()[m_posx][m_posy+1].getType() == 0 || plateau->getplateau()[m_posx][m_posy+1].getType() == 13 || plateau->getplateau()[m_posx][m_posy+1].getType() == 99)
                    {
                        m_posy++;
                    }
                    else
                    {
                        // message d'erreur
                        std::cout << "Deplacement impossible !" << std::endl ;
                        Sleep(500);
                    }
                }


                quit=true;
                Console::deleteInstance();
            }


        }



    }


}


int Joueur::entrer(std::vector <Suspect> paquet_suspect, std::vector <Arme> paquet_arme, std::vector <Lieu> paquet_lieu, int k)
{
    if ((m_posx ==9 && m_posy == 7) || (m_posx ==6 && m_posy == 9) ) //Salle 1
    {
        m_posx = 6; /// entrer la coord en x (ligne)
        m_posy = 6; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 10; /// entrer la coord en x (ligne)
        m_posy = 7; /// entrer la coord en y (colonne)

    }

    if ((m_posx ==9 && m_posy == 15) || (m_posx ==6 && m_posy == 19) ) // Salle 2
    {
        m_posx = 6; /// entrer la coord en x (ligne)
        m_posy = 16; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 10; /// entrer la coord en x (ligne)
        m_posy = 15; /// entrer la coord en y (colonne)
    }

    if ((m_posx ==6 && m_posy == 22) || (m_posx == 9 && m_posy == 27) ) //Salle 3
    {
        m_posx = 6; /// entrer la coord en x (ligne)
        m_posy = 26; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 10; /// entrer la coord en x (ligne)
        m_posy = 27; /// entrer la coord en y (colonne)
    }

///la maison

    if ((m_posx ==12 && m_posy == 10) || (m_posx ==19 && m_posy == 10) )
    {
        m_posx = 15; /// entrer la coord en x (ligne)
        m_posy = 9; /// entrer la coord en y (colonne)
        m_de = 0;
        k = accuser(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 11; /// entrer la coord en x (ligne)
        m_posy = 10; /// entrer la coord en y (colonne)
    }

    ///salle  4

    if ((m_posx ==12 && m_posy == 24) || (m_posx ==19 && m_posy == 24) )
    {
        m_posx = 16; /// entrer la coord en x (ligne)
        m_posy = 25; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 11; /// entrer la coord en x (ligne)
        m_posy = 24; /// entrer la coord en y (colonne)
    }
    ///salle 5
    if ((m_posx ==22 && m_posy == 7) || (m_posx ==25 && m_posy == 9) )
    {
        m_posx = 25; /// entrer la coord en x (ligne)
        m_posy = 8; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 21; /// entrer la coord en x (ligne)
        m_posy = 7; /// entrer la coord en y (colonne)

    }

    ///salle 6
    if ((m_posx ==22 && m_posy == 15) || (m_posx ==25 && m_posy == 19) )
    {
        m_posx = 25; /// entrer la coord en x (ligne)
        m_posy = 16; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 21; /// entrer la coord en x (ligne)
        m_posy = 15; /// entrer la coord en y (colonne)
    }
    ///Salle 7
    if ((m_posx ==22 && m_posy == 27) || (m_posx ==25 && m_posy == 22) )
    {
        m_posx = 25; /// entrer la coord en x (ligne)
        m_posy = 25; /// entrer la coord en y (colonne)
        m_de = 0;
        hypothese(paquet_suspect, paquet_arme, paquet_lieu,k);
        m_posx = 21; /// entrer la coord en x (ligne)
        m_posy = 27; /// entrer la coord en y (colonne)
    }

    /// Création des Pièges en indiquant leurs positions

    if (m_posx == 10 && m_posy == 2)
    {
        m_posx = 20; /// entrer la coord en x (ligne)
        m_posy = 27; /// entrer la coord en y (colonne)
        gotoligcol(15, 65);
        std::cout << m_nom_joueur << " s'est teleporte !" ;
        gotoligcol(10, 65);
        Sleep(1000);
    }

    if (m_posx == 20 && m_posy == 28)
    {
        m_posx = 10; /// entrer la coord en x (ligne)
        m_posy = 3; /// entrer la coord en y (colonne)
        gotoligcol(15, 65);
        std::cout << m_nom_joueur << " s'est teleporte !" ;
        gotoligcol(10, 65);
        Sleep(1000);
    }

    if (m_posx == 11 && m_posy == 29)
    {
        m_posx = 21; /// entrer la coord en x (ligne)
        m_posy = 3; /// entrer la coord en y (colonne)
        gotoligcol(15, 65);
        std::cout << m_nom_joueur << " s'est teleporte !" ;
        gotoligcol(10, 65);
        Sleep(1000);
    }

    if (m_posx == 21 && m_posy == 2)
    {
        m_posx = 11; /// entrer la coord en x (ligne)
        m_posy = 28; /// entrer la coord en y (colonne)
        gotoligcol(15, 65);
        std::cout << m_nom_joueur << " s'est teleporte !" ;
        gotoligcol(10, 65);
        Sleep(1000);
    }


    return k;


}
//hypothèse en appelant les attributs nécessaires à la reconstitution du meurtre

void Joueur::hypothese(std::vector <Suspect> paquet_suspect, std::vector <Arme> paquet_arme, std::vector <Lieu> paquet_lieu,int k)
{
    int choix1 = 0, choix2 = 0, choix3 = 0;
    Sleep (500);
    system("cls");
    gotoligcol(12, 40);
    std::cout << m_nom_joueur << ", vous etes entre dans une salle!";
    gotoligcol(13, 30);
    std::cout << "Vous pouvez faire une hypothese sur l'identite du meurtrier.";

    Sleep (3500);
    do
    {
        system("cls");
        gotoligcol(10, 45);
        std::cout << "Choisissez les cartes que vous voulez :";
        gotoligcol(12, 50);
        std::cout << "Cartes Suspect :";
        gotoligcol(13, 50);

        ///affichage des noms de chaque joueurs

        std::cout << "1 - " << paquet_suspect[0].getNom_suspect();
        gotoligcol(14, 50);
        std::cout << "2 - " << paquet_suspect[1].getNom_suspect();
        gotoligcol(15, 50);
        std::cout << "3 - " << paquet_suspect[2].getNom_suspect();
        gotoligcol(16, 50);
        std::cout << "4 - " << paquet_suspect[3].getNom_suspect();
        gotoligcol(12, 67);
        std::cin >> choix1;
    }
    while ( (choix1 < 1) || (choix1 > 4));

    do
    {
        system("cls");
        gotoligcol(8, 45);
        std::cout << "Choisissez les cartes que vous voulez :";
        gotoligcol(10, 50);

        /// Affichage des cartes correspondant aux lieux

        std::cout << "Cartes Lieu :";
        gotoligcol(11, 50);
        std::cout << "1 - " << paquet_lieu[1].getNom_lieu();
        gotoligcol(12, 50);
        std::cout << "2 - " << paquet_lieu[2].getNom_lieu();
        gotoligcol(13, 50);
        std::cout << "3 - " << paquet_lieu[0].getNom_lieu();
        gotoligcol(14, 50);
        std::cout << "4 - " << paquet_lieu[3].getNom_lieu();
        gotoligcol(15, 50);
        std::cout << "5 - " << paquet_lieu[4].getNom_lieu();
        gotoligcol(16, 50);
        std::cout << "6 - " << paquet_lieu[5].getNom_lieu();
        gotoligcol(17, 50);
        std::cout << "7 - " << paquet_lieu[6].getNom_lieu();
        gotoligcol(10, 64);
        std::cin >> choix2;
    }
    while ( (choix2 < 1) || (choix2 > 7));

    do
    {
        system("cls");
        gotoligcol(10, 45);
        std::cout << "Choisissez les cartes que vous voulez :";
        gotoligcol(12, 50);

    /// affichage des cartes armes
        std::cout << "Cartes Arme :";
        gotoligcol(13, 50);
        std::cout << "1 - " << paquet_arme[1].getNom_arme();
        gotoligcol(14, 50);
        std::cout << "2 - " << paquet_arme[2].getNom_arme();
        gotoligcol(15, 50);
        std::cout << "3 - " << paquet_arme[3].getNom_arme();
        gotoligcol(16, 50);
        std::cout << "4 - " << paquet_arme[4].getNom_arme();
        gotoligcol(17, 50);
        std::cout << "5 - " << paquet_arme[0].getNom_arme();
        gotoligcol(12, 64);
        std::cin >> choix3;
    }
    while ( (choix3 < 1) || (choix3 > 5)); // blindage
//validation de l'hypothèse
    system("cls");
    if (choix1 == 1) // si le choix entre est 1
    {
        gotoligcol(10, 45);
        std::cout << "La carte suspecte est correcte.";
    }
    else //si autre reponse fausse
    {
        gotoligcol(10, 45);
        std::cout << "La carte suspecte est incorrecte.";
    }
    if (choix2 == 2) // si le choix entre est 2
    {
        gotoligcol(12, 45);
        std::cout << "La carte lieu est correcte.";
    }
    else // si autre alors reponse fausse
    {
        gotoligcol(12, 45);
        std::cout << "La carte suspecte est incorrecte.";
    }
    if (choix3 == 5) //si le choix entre est 5, alors c'est validé
    {
        gotoligcol(14, 45);
        std::cout << "La carte arme est correcte.";
    }
    else
    {
        gotoligcol(14, 45);
        std::cout << "La carte suspecte est incorrecte.";
    }
    Sleep (5000);

}

int Joueur::accuser(std::vector <Suspect> paquet_suspect, std::vector <Arme> paquet_arme, std::vector <Lieu> paquet_lieu,int k)
{
    ///affichage lorsque le joueur entre dans la salle maison

    int choix1 = 0, choix2 = 0, choix3 = 0;
    Sleep (500);
    system("cls");
    gotoligcol(12, 40);
    std::cout << m_nom_joueur << ", vous etes entre dans la maison!";
    gotoligcol(13, 30);
    std::cout << "Vous pouvez faire une accusation sur l'identite du meurtrier.";
    gotoligcol(14, 27);
    std::cout << "Mais attention si vous vous trompez vous serez elimine de la partie!";

/// possibilite de soumettre une hypothèse
    Sleep (5000);

    do
    {
        system("cls");
        gotoligcol(10, 45);
        std::cout << "Choisissez les cartes que vous voulez :";
        gotoligcol(12, 50);
        std::cout << "Cartes Suspect :";
        gotoligcol(13, 50);
        std::cout << "1 - " << paquet_suspect[0].getNom_suspect();
        gotoligcol(14, 50);
        std::cout << "2 - " << paquet_suspect[1].getNom_suspect();
        gotoligcol(15, 50);
        std::cout << "3 - " << paquet_suspect[2].getNom_suspect();
        gotoligcol(16, 50);
        std::cout << "4 - " << paquet_suspect[3].getNom_suspect();
        gotoligcol(12, 67);
        std::cin >> choix1;
    }
    while ( (choix1 < 1) || (choix1 > 4));

    do
    {
        system("cls");
        gotoligcol(8, 45);
        std::cout << "Choisissez les cartes que vous voulez :";
        gotoligcol(10, 50);
        std::cout << "Cartes Lieu :";
        gotoligcol(11, 50);
        std::cout << "1 - " << paquet_lieu[1].getNom_lieu();
        gotoligcol(12, 50);
        std::cout << "2 - " << paquet_lieu[2].getNom_lieu();
        gotoligcol(13, 50);
        std::cout << "3 - " << paquet_lieu[0].getNom_lieu();
        gotoligcol(14, 50);
        std::cout << "4 - " << paquet_lieu[3].getNom_lieu();
        gotoligcol(15, 50);
        std::cout << "5 - " << paquet_lieu[4].getNom_lieu();
        gotoligcol(16, 50);
        std::cout << "6 - " << paquet_lieu[5].getNom_lieu();
        gotoligcol(17, 50);
        std::cout << "7 - " << paquet_lieu[6].getNom_lieu();
        gotoligcol(10, 64);
        std::cin >> choix2;
    }
    while ( (choix2 < 1) || (choix2 > 7));

    do
    {
        system("cls");
        gotoligcol(10, 45);
        std::cout << "Choisissez les cartes que vous voulez :";
        gotoligcol(12, 50);
        std::cout << "Cartes Arme :";
        gotoligcol(13, 50);
        std::cout << "1 - " << paquet_arme[1].getNom_arme();
        gotoligcol(14, 50);
        std::cout << "2 - " << paquet_arme[2].getNom_arme();
        gotoligcol(15, 50);
        std::cout << "3 - " << paquet_arme[3].getNom_arme();
        gotoligcol(16, 50);
        std::cout << "4 - " << paquet_arme[4].getNom_arme();
        gotoligcol(17, 50);
        std::cout << "5 - " << paquet_arme[0].getNom_arme();
        gotoligcol(12, 64);
        std::cin >> choix3;
    }
    while ( (choix3 < 1) || (choix3 > 5));


    if (choix1 == 1)
    {
        gotoligcol(10, 45);
        std::cout << "La carte suspecte est correcte.";
    }
    else
    {
        gotoligcol(10, 45);
        std::cout << "La carte suspecte est incorrecte.";
    }
    if (choix2 == 2)
    {
        gotoligcol(12, 45);
        std::cout << "La carte lieu est correcte.";
    }
    else
    {
        gotoligcol(12, 45);
        std::cout << "La carte suspecte est incorrecte.";
    }
    if (choix3 == 5)
    {
        gotoligcol(14, 45);
        std::cout << "La carte arme est correcte.";
    }
    else
    {
        gotoligcol(14, 45);
        std::cout << "La carte suspecte est incorrecte.";
    }

    system("cls");
    if (choix1 == 1 && choix2 == 2 && choix3 == 5)
    {
        ///fin de partie si le joueur a son hypothese de correcte

        gotoligcol(12, 47);
        std::cout << "L'accusation est correcte";
        gotoligcol(14, 38);
        std::cout << "Vous avez gagne. Applaudissons tous " << m_nom_joueur << " !!!";
        Sleep (5000);
        system ("cls");
        gotoligcol (12,55);
        std::cout << "Credits :";
        gotoligcol (13,52);
        std::cout << "Maxence Tiercelet";
        gotoligcol (14,52);
        std::cout << "Mathys Bagnah";
        gotoligcol (15,52);
        std::cout << "Jules Pinte";
        Sleep (5000);
        k = 2000; // Sortie de la boucle de jeu

    }
    else // si l'hypothese est fausse on élimine le joueur
    {
        gotoligcol(12, 50);
        std::cout << "L'accusation est fausse";
        gotoligcol(14, 52);
        std::cout << m_nom_joueur << " est elimine !";
        m_vie = false;
        Sleep (5000);
    }

    return k;
}


