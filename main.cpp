
/*==============================================================================&
 | Fichier MAIN                                                                 |
 |                                                                              |
 | Projet cluedo ECE 2021                                                       |
 | Inge 2                                                                       |
 | Novembre 2021                                                                |
 +------------------------------------------------------------------------------|
 |      Ce fichier contient toutes les definitions essentielles de fonctions    |
 |                                                                              |
 |              indispensables au fonctionnnement de notre jeu Cluedo          |
 ==============================================================================*/


/// inclusion des libraires///
#include <vector>
#include <iostream>
#include <time.h>
#include <random>
#include <algorithm>
#include <iterator>
#include <windows.h>


/// inclusion des fichiers///
#include "console.h"
#include "Carte.h"
#include "Joueur.h"
#include "Paquet.h"
#include "Case.h"
#include "Plateau.h"

int main()
{


    srand(time(NULL));

    /// Déclaration des joueurs
    Joueur joueur1(true, "nom1", 15, 16, 0), joueur2(true, "nom2", 15, 17, 0), joueur3(true, "nom3", 15, 18, 0), joueur4(true, "nom4", 15, 19, 0);

    ///Déclaration des cartes
    Suspect suspect1(false, "Vito Corleone"), suspect2(false, "Michael Corleone"), suspect3(false, "Sonny Corleone"), suspect4(false, "Connie Corleone"), suspect5(false, "Tom Hagen");
    Lieu lieu1(false,"Cathedrale"), lieu2(false,"St Regis"), lieu3(false,"Jack Demesy"), lieu4(false,"La maison"), lieu5(false,"Cimetiere"), lieu6(false,"Elis Island"), lieu7(false,"Savoca"), lieu8(false,"San Nicolo");
    Arme arme1(false, "Couteau"), arme2(false, "Pistolet"), arme3(false, "Mitrailette"), arme4(false, "Batte"),  arme5(false, "Marteau");

    /// Déclaration des paquets
    std::vector <Suspect> paquet_suspect;
    std::vector <Lieu> paquet_lieu;
    std::vector <Arme> paquet_arme;
    Suspect enveloppe_suspect;
    Lieu enveloppe_lieu;
    Arme enveloppe_arme;

    Plateau plateau;

    /// /// /// Menu /// /// ///
    int choix = 0;
    int quit = 0;
    int quitter = 0;

    do
    {
        //affichage
        system("cls");
        gotoligcol(11, 50);
        std::cout << "Bienvenue sur ";
        Color(4,0); // couleur rouge
        std::cout << "Murder Mystery Game";
        Color(15,0); // couleur blanche
        gotoligcol(13,51);
        std::cout << "1. Jouer" << std::endl;
        gotoligcol(14,51);
        std::cout << "2. Creation des joueurs" << std::endl;
        gotoligcol(15,51);
        std::cout << "3. Charger la partie" << std::endl;
        gotoligcol(16,51);
        std::cout << "4. Regle du jeu" << std::endl;
        gotoligcol(17,51);
        std::cout << "0. Quitter" << std::endl;
        gotoligcol(18,51);


        std::cin >> choix;

        switch(choix) // interface du menu
        {
        case 1 : // Jouer
        {
            // definition des position des joueurs au début de la partie
            joueur1.setPosx(15);
            joueur1.setPosy(16);
            joueur2.setPosx(15);
            joueur2.setPosy(17);
            joueur3.setPosx(15);
            joueur3.setPosy(18);
            joueur4.setPosx(15);
            joueur4.setPosy(19);


            ///Rangement des cartes par type
            paquet_suspect.push_back(suspect1);
            paquet_suspect.push_back(suspect2);
            paquet_suspect.push_back(suspect3);
            paquet_suspect.push_back(suspect4);
            paquet_suspect.push_back(suspect5);

            paquet_lieu.push_back(lieu1);
            paquet_lieu.push_back(lieu2);
            paquet_lieu.push_back(lieu3);
            paquet_lieu.push_back(lieu4);
            paquet_lieu.push_back(lieu5);
            paquet_lieu.push_back(lieu6);
            paquet_lieu.push_back(lieu7);

            paquet_arme.push_back(arme1);
            paquet_arme.push_back(arme2);
            paquet_arme.push_back(arme3);
            paquet_arme.push_back(arme4);
            paquet_arme.push_back(arme5);


            ///Mélange des 3 paquets
            paquet_suspect = melanger(paquet_suspect);
            paquet_lieu = melanger(paquet_lieu);
            paquet_arme = melanger(paquet_arme);

            ///Distribution des cartes
            enveloppe_suspect = paquet_suspect[0];
            enveloppe_lieu = paquet_lieu[0];
            enveloppe_arme = paquet_arme[0];

            joueur1.setSuspect(paquet_suspect[1]);
            joueur1.setLieu(paquet_lieu[1]);
            joueur1.setArme(paquet_arme[1]);

            joueur2.setSuspect(paquet_suspect[2]);
            joueur2.setLieu(paquet_lieu[2]);
            joueur2.setArme(paquet_arme[2]);

            joueur3.setSuspect(paquet_suspect[3]);
            joueur3.setLieu(paquet_lieu[3]);
            joueur3.setArme(paquet_arme[3]);

            joueur4.setSuspect(paquet_suspect[4]);
            joueur4.setLieu(paquet_lieu[4]);
            joueur4.setArme(paquet_arme[4]);

            enveloppe_suspect.setMeurtrier(true);
            enveloppe_lieu.setMeurtrier(true);
            enveloppe_arme.setMeurtrier(true);


            system("cls"); // nettoyage de l'affichage console
            plateau.initialisation();
            plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);

            char sauvegarde = 0;

            for (int k = 1; k<2000; k++)
            {

                joueur1.setLancer_de();
                joueur2.setLancer_de();
                joueur3.setLancer_de();
                joueur4.setLancer_de();

                plateau.afficher();

                if (joueur1.getVie() == true && k<2000) // verifie que le joueur est encore vivant
                {
                    for (int i = 0; i<joueur1.getLancer_de(); i++)
                    {
                        plateau.information1(i,&joueur1);
                        joueur1.deplacer(&plateau);
                        k = joueur1.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                if (joueur2.getVie() == true && k<2000)
                {
                    for (int i = 0; i<joueur2.getLancer_de(); i++)
                    {
                        plateau.information2(i,&joueur2);
                        joueur2.deplacer(&plateau);
                        k = joueur2.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                if (joueur3.getVie() == true && k<2000)
                {
                    for (int i = 0; i<joueur3.getLancer_de(); i++)
                    {
                        plateau.information3(i,&joueur3);
                        joueur3.deplacer(&plateau);
                        k = joueur3.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                if (joueur4.getVie() == true && k<2000)
                {
                    for (int i = 0; i<joueur4.getLancer_de(); i++)
                    {
                        plateau.information4(i,&joueur4);
                        joueur4.deplacer(&plateau);
                        k = joueur4.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                /// proposition d'une sauvegarde à la fin de chaque tour
                if (k <2000)
                {
                    ///affichage information

                    system("cls");
                    gotoligcol(10,30);
                    std::cout << "Vous avez realises votre " << k <<"eme tour(s)";
                    gotoligcol(12,30);
                    std::cout << "Si vous voulez arreter votre partie et sauvegarder appuyer sur P";
                    gotoligcol(14,30);
                    std::cout << "Pour continuer la partie entrez n'importe quelle touche";
                    gotoligcol(15,30);
                    std::cin >> sauvegarde;

                    if (sauvegarde == 'P')
                    {
                        joueur1.sauvegarde1(); // sauvgarde des noms des joueurs
                        joueur2.sauvegarde2(); // sauvegarde des cartes
                        joueur3.sauvegarde3(); // sauvegarde des position
                        joueur4.sauvegarde4();

                        enveloppe_arme.sauvegarde_enveloppe_arme(); // sauveagrde de l'enveloppe
                        enveloppe_lieu.sauvegarde_enveloppe_lieu();
                        enveloppe_suspect.sauvegarde_enveloppe_suspect();
                        return 0;
                    }
                    gotoligcol(0,0);
                    system("cls");
                }

            }
            break;
        }
        case 2: /// Ajouter un joueur
        {
            system("cls");
            /// Creation du joueur 1
            std::string nom1, mdp1, mdp2, mdp3, mdp4;
            gotoligcol(10,50);
            std::cout << "Taper le pseudo du joueur 1" << std::endl;
            gotoligcol(11,50);
            std::cin >> nom1;
            joueur1.setNom_joueur(nom1);
            gotoligcol(13,50);
            std::cout << "Taper le mot de passe du joueur 1" << std::endl;
            gotoligcol(14,50);
            std::cin >> mdp1 ;
            joueur1.setMdp(mdp1);

            joueur1.sauvegarde1(); // sauvegarde des information nom et mot de passe du joueur 1


            system("cls");
            /// Creation du joueur 2
            std::string nom2;
            gotoligcol(10,50);
            std::cout << "Taper le pseudo du joueur 2" << std::endl;
            gotoligcol(11,50);
            std::cin >> nom2;
            joueur2.setNom_joueur(nom2);
            gotoligcol(13,50);
            std::cout << "Taper le mot de passe du joueur 2" << std::endl;
            gotoligcol(14,50);
            std::cin >> mdp2 ;
            joueur2.setMdp(mdp2);


            joueur2.sauvegarde2(); // sauvegarde des information nom et mot de passe du joueur 2


            system("cls");
            /// Creation du joueur 3
            std::string nom3;
            gotoligcol(10,50);
            std::cout << "Taper le pseudo du joueur 3" << std::endl;
            gotoligcol(11,50);
            std::cin >> nom3;
            joueur3.setNom_joueur(nom3);
            gotoligcol(13,50);
            std::cout << "Taper le mot de passe du joueur 3" << std::endl;
            gotoligcol(14,50);
            std::cin >> mdp3 ;
            joueur3.setMdp(mdp3);

            joueur3.sauvegarde3(); // sauvegarde des information nom et mot de passe du joueur 3


            system("cls");
            /// Creation du joueur 4
            std::string nom4;
            gotoligcol(10,50);
            std::cout << "Taper le pseudo du joueur 4" << std::endl;
            gotoligcol(11,50);
            std::cin >> nom4;
            joueur4.setNom_joueur(nom4);
            gotoligcol(13,50);
            std::cout << "Taper le mot de passe du joueur 4" << std::endl;
            gotoligcol(14,50);
            std::cin >> mdp4 ;
            joueur4.setMdp(mdp4);

            joueur4.sauvegarde4(); // sauvegarde des information nom et mot de passe du joueur 4

            break;
        }
        case 3: /// Chargement partie
        {
            ///Rangement des cartes par type
            paquet_suspect.push_back(suspect1);
            paquet_suspect.push_back(suspect2);
            paquet_suspect.push_back(suspect3);
            paquet_suspect.push_back(suspect4);
            paquet_suspect.push_back(suspect5);

            paquet_lieu.push_back(lieu1);
            paquet_lieu.push_back(lieu2);
            paquet_lieu.push_back(lieu3);
            paquet_lieu.push_back(lieu4);
            paquet_lieu.push_back(lieu5);
            paquet_lieu.push_back(lieu6);
            paquet_lieu.push_back(lieu7);

            paquet_arme.push_back(arme1);
            paquet_arme.push_back(arme2);
            paquet_arme.push_back(arme3);
            paquet_arme.push_back(arme4);
            paquet_arme.push_back(arme5);

            ///Distribution des cartes
            enveloppe_suspect = paquet_suspect[0];
            enveloppe_lieu = paquet_lieu[0];
            enveloppe_arme = paquet_arme[0];

            joueur1.setSuspect(paquet_suspect[1]);
            joueur1.setLieu(paquet_lieu[1]);
            joueur1.setArme(paquet_arme[1]);

            joueur2.setSuspect(paquet_suspect[2]);
            joueur2.setLieu(paquet_lieu[2]);
            joueur2.setArme(paquet_arme[2]);

            joueur3.setSuspect(paquet_suspect[3]);
            joueur3.setLieu(paquet_lieu[3]);
            joueur3.setArme(paquet_arme[3]);

            joueur4.setSuspect(paquet_suspect[4]);
            joueur4.setLieu(paquet_lieu[4]);
            joueur4.setArme(paquet_arme[4]);

            enveloppe_suspect.setMeurtrier(true);
            enveloppe_lieu.setMeurtrier(true);
            enveloppe_arme.setMeurtrier(true);


            joueur1.chargement1(); // chargement de toutes les informations sauvegardées pendant la derniere partie
            joueur2.chargement2();
            joueur3.chargement3();
            joueur4.chargement4();

            enveloppe_arme.chargement_enveloppe_arme();
            enveloppe_lieu.chargement_enveloppe_lieu();
            enveloppe_suspect.chargement_enveloppe_suspect();

            system("cls");
            plateau.initialisation();
            plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);

            char sauvegarde = 0;

            for (int k=0; k<2000; k++)  // boucle de jeu
            {

                joueur1.setLancer_de();
                joueur2.setLancer_de();
                joueur3.setLancer_de();
                joueur4.setLancer_de();

                plateau.afficher();

                if (joueur1.getVie() == true)
                {
                    for (int i = 0; i<joueur1.getLancer_de(); i++)
                    {
                        plateau.information1(i,&joueur1);
                        joueur1.deplacer(&plateau);
                        joueur1.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                if (joueur2.getVie() == true)
                {
                    for (int i = 0; i<joueur2.getLancer_de(); i++)
                    {
                        plateau.information2(i,&joueur2);
                        joueur2.deplacer(&plateau);
                        joueur2.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                if (joueur3.getVie() == true)
                {
                    for (int i = 0; i<joueur3.getLancer_de(); i++)
                    {
                        plateau.information3(i,&joueur3);
                        joueur3.deplacer(&plateau);
                        joueur3.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }

                if (joueur4.getVie() == true)
                {
                    for (int i = 0; i<joueur4.getLancer_de(); i++)
                    {
                        plateau.information4(i,&joueur4);
                        joueur4.deplacer(&plateau);
                        joueur4.entrer(paquet_suspect, paquet_arme, paquet_lieu,k);
                        plateau.majplateau(&joueur1, &joueur2, &joueur3, &joueur4);
                        plateau.afficher();
                    }
                }
                /// proposition d'une sauvegarde à la fin de chaque tour
                if (k <2000)
                {
                    ///affichage information

                    system("cls");
                    gotoligcol(10,30);
                    std::cout << "Vous avez realises votre " << k <<"eme tour(s)";
                    gotoligcol(12,30);
                    std::cout << "Si vous voulez arreter votre partie et sauvegarder appuyer sur P";
                    gotoligcol(14,30);
                    std::cout << "Pour continuer la partie entrez n'importe quelle touche";
                    gotoligcol(15,30);
                    std::cin >> sauvegarde;

                    if (sauvegarde == 'P')
                    {
                        joueur1.sauvegarde1(); // sauvgarde des noms des joueurs
                        joueur2.sauvegarde2(); // sauvegarde des cartes
                        joueur3.sauvegarde3(); // sauvegarde des position
                        joueur4.sauvegarde4();

                        enveloppe_arme.sauvegarde_enveloppe_arme(); // sauveagrde de l'enveloppe
                        enveloppe_lieu.sauvegarde_enveloppe_lieu();
                        enveloppe_suspect.sauvegarde_enveloppe_suspect();
                        return 0;
                    }
                    gotoligcol(0,0);
                    system("cls");
                }
                gotoligcol(0,0);
                system("cls");
            }

            break;

        }
        case 4: /// Regles du jeu
        {
            system("cls");
            std::cout << "But du jeu : Enqueter sur qui a tue Le Parrain, dans quel lieu et a l'aide de quelle arme." << std::endl << std::endl;
            std::cout << "Nombre de joueurs: 4" << std::endl << std::endl;

            std::cout << "Deroulement :" <<std::endl;
            std::cout << "                                                                   " <<std::endl;

            std::cout << "Les joueurs lancent le de a tour de roles, ensuite le joueur se deplace du nombre correspondant de cases indique par le de sur le plateau." << std::endl << std::endl;
            std::cout << "Attention lorsque le joueur passe une porte, il n'a plus de deplacement." << std::endl << std::endl;

            std::cout << "Soyez curieux, des passages secrets se trouvent sur le plateau de jeu et peuvent vous faire economiser des deplacements." << std::endl << std::endl;

            std::cout << "Lorsque le joueur entre dans dans la maison (salle principale) il peut soumettre une reconstitution du crime en indiquant le meurtrier, l'arme et le lieu." << std::endl << std::endl;
            std::cout << "Si la reconstitution emis par le joueur est fausse alors il sera elimine, si en revanche elle est vraie alors le joueur est le gagnant de la partie." << std::endl << std::endl;
            gotoligcol(18,106);
            std::cout << "0 : Quitter";
            do
            {
                std::cin >> quitter;
            } while (quitter != 0);
            if (quitter == 0)
                break;
        }

        default:
            return 0;
            break;
        }
        //retour en arrière
        system("cls");
        gotoligcol(13,40);
        std::cout << "Tapez 1 pour jouer, autre chose pour quitter le programme." << std::endl;
        std::cin >> quit;

    }
    while(quit == 1);   /// Jusqu'a ce qu'on quitte


    return 0;
}
