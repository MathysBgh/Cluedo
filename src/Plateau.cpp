#include "Plateau.h"
/// inclusion du fichier.h///
#include "console.h"


Plateau::Plateau()
{

}
///getter de vecteur
std::vector<std::vector<Case>> Plateau::getplateau()const
{
    return m_plateau;
}



///    METHODES ///

void Plateau::initialisation()
{
 ///attributs
    char bordurehg = 0xC9; char bordurehd = 0xBB ; char bordurebd = 0xBC ; char bordurebg = 0xC8;
    char bordurehori = 0xCD; char bordureverti = 0xBA;
    char borduresalleverti = 0xB3; char borduresallehori = 0xC4;
    char borduresallehg = 0xDA ; char borduresallehd = 0xBF ; char borduresallebd = 0xD9; char borduresallebg = 0xC0;
    char porte = 'O';
    char piege = '0';

    m_plateau.resize(100);
    for (int i = 0; i < 100; i++)
         m_plateau[i].resize(100);


    ///Initialisation bordures et creation du plateau

   for(int i=1;i<31;i++)
   {
       for (int j=0;j<31;j++)
       {
           m_plateau[i][j].setType(0);
       }
   }

    for (int j=2;j<30;j++)
        {
            m_plateau[1][j].setType(1);
            m_plateau[30][j].setType(1);
        }
    for (int i=2;i<31;i++)
        {
           m_plateau[i][1].setType(2);
           m_plateau[i][30].setType(2);
        }

    for (int i=2;i<9;i++)
    {
        m_plateau[i][2].setType(8);
        m_plateau[i][9].setType(8);
        m_plateau[i][12].setType(8);
        m_plateau[i][19].setType(8);
        m_plateau[i][22].setType(8);
        m_plateau[i][29].setType(8);

        m_plateau[2][i].setType(7);
        m_plateau[9][i].setType(7);
        m_plateau[12][i].setType(7);
        m_plateau[19][i].setType(7);
        m_plateau[22][i].setType(7);
        m_plateau[29][i].setType(7);
    }
    for(int i=12;i<19;i++)
    {
        m_plateau[i][2].setType(8);
        m_plateau[i][22].setType(8);
        m_plateau[i][29].setType(8);

        m_plateau[2][i].setType(7);
        m_plateau[9][i].setType(7);
        m_plateau[22][i].setType(7);
        m_plateau[29][i].setType(7);
    }

    for(int j=2;j<14;j++)
    {
        m_plateau[12][j].setType(7);
        m_plateau[19][j].setType(7);

    }

    for(int i=12;i<19;i++)
    {
        m_plateau[i][14].setType(8);
    }

    for(int i=22;i<29;i++)
    {
        m_plateau[i][2].setType(8);
        m_plateau[i][9].setType(8);
        m_plateau[i][12].setType(8);
        m_plateau[i][19].setType(8);
        m_plateau[i][22].setType(8);
        m_plateau[i][29].setType(8);

        m_plateau[2][i].setType(7);
        m_plateau[9][i].setType(7);
        m_plateau[12][i].setType(7);
        m_plateau[19][i].setType(7);
        m_plateau[22][i].setType(7);
        m_plateau[29][i].setType(7);
    }

    /// Création des coin des salles
    m_plateau[2][2].setType(9);
    m_plateau[2][9].setType(10);
    m_plateau[2][12].setType(9);
    m_plateau[2][19].setType(10);
    m_plateau[2][22].setType(9);
    m_plateau[2][29].setType(10);

    m_plateau[9][2].setType(12);
    m_plateau[9][9].setType(11);
    m_plateau[9][12].setType(12);
    m_plateau[9][19].setType(11);
    m_plateau[9][22].setType(12);
    m_plateau[9][29].setType(11);

    m_plateau[12][2].setType(9);
    m_plateau[12][14].setType(10);
    m_plateau[12][22].setType(9);
    m_plateau[12][29].setType(10);

    m_plateau[19][2].setType(12);
    m_plateau[19][14].setType(11);
    m_plateau[19][22].setType(12);
    m_plateau[19][29].setType(11);

    m_plateau[22][2].setType(9);
    m_plateau[22][9].setType(10);
    m_plateau[22][12].setType(9);
    m_plateau[22][19].setType(10);
    m_plateau[22][22].setType(9);
    m_plateau[22][29].setType(10);

    m_plateau[29][2].setType(12);
    m_plateau[29][9].setType(11);
    m_plateau[29][12].setType(12);
    m_plateau[29][19].setType(11);
    m_plateau[29][22].setType(12);
    m_plateau[29][29].setType(11);


    ///Bordure du plateau

   m_plateau[1][1].setType(3);
   m_plateau[1][30].setType(4);
   m_plateau[30][30].setType(5);
   m_plateau[30][1].setType(6);


    //Porte verticale
   m_plateau[9][7].setType(13);
   m_plateau[9][15].setType(13);
   m_plateau[9][27].setType(13);
   m_plateau[12][10].setType(13);
   m_plateau[19][10].setType(13);
   m_plateau[12][24].setType(13);
   m_plateau[19][24].setType(13);
   m_plateau[22][7].setType(13);
   m_plateau[22][15].setType(13);
   m_plateau[22][27].setType(13);

    //Porte horizontale
   m_plateau[6][9].setType(13);
   m_plateau[6][19].setType(13);
   m_plateau[6][22].setType(13);
   m_plateau[25][9].setType(13);
   m_plateau[25][19].setType(13);
   m_plateau[25][22].setType(13);

    //Pièges
   m_plateau[10][2].setType(99);
   m_plateau[11][29].setType(99);
   m_plateau[21][2].setType(99);
   m_plateau[20][28].setType(99);


    for (int i=1;i<31;i++)
    {
        for (int j=1;j<31;j++)
        {
            if (m_plateau[i][j].getType() == 0)

            {
                m_plateau[i][j].setAffichage(' ');
            }

            if (m_plateau[i][j].getType() == 1)
            {
                m_plateau[i][j].setAffichage(bordurehori);
            }

            if (m_plateau[i][j].getType() == 2)
            {
                m_plateau[i][j].setAffichage(bordureverti);
            }

            if (m_plateau[i][j].getType() == 3)
            {
                m_plateau[i][j].setAffichage(bordurehg);
            }

            if (m_plateau[i][j].getType() == 4)
            {
                m_plateau[i][j].setAffichage(bordurehd);
            }

            if (m_plateau[i][j].getType() == 5)
            {
                m_plateau[i][j].setAffichage(bordurebd);
            }

            if (m_plateau[i][j].getType() == 6)
            {
                m_plateau[i][j].setAffichage(bordurebg);
            }

            if (m_plateau[i][j].getType() == 7)
            {
                m_plateau[i][j].setAffichage(borduresallehori);
            }

              if (m_plateau[i][j].getType() == 8)
            {
                m_plateau[i][j].setAffichage(borduresalleverti);
            }

              if (m_plateau[i][j].getType() == 9)
            {
                m_plateau[i][j].setAffichage(borduresallehg);
            }

              if (m_plateau[i][j].getType() == 10)
            {
                m_plateau[i][j].setAffichage(borduresallehd);
            }

              if (m_plateau[i][j].getType() == 11)
            {
                m_plateau[i][j].setAffichage(borduresallebd);
            }

              if (m_plateau[i][j].getType() == 12)
            {
                m_plateau[i][j].setAffichage(borduresallebg);
            }

               if (m_plateau[i][j].getType() == 13)
            {
                m_plateau[i][j].setAffichage(porte);
            }
            if (m_plateau[i][j].getType() == 99)
            {
                m_plateau[i][j].setAffichage(piege);
            }
        }
    }

/// nommer les salles

    m_plateau[3][3].setAffichage('C');  //on affiche lettre par lettre le nom ici la salle est "cathed" on doit donc placer les lettres en fonction de la ligne qu'on veut en (x) et de la colonne en (y)
    m_plateau[3][4].setAffichage('A');
    m_plateau[3][5].setAffichage('T');
    m_plateau[3][6].setAffichage('H');
    m_plateau[3][7].setAffichage('E');
    m_plateau[3][8].setAffichage('D');

    m_plateau[4][4].setAffichage('R');
    m_plateau[4][5].setAffichage('A');
    m_plateau[4][6].setAffichage('L');
    m_plateau[4][7].setAffichage('E');


    m_plateau[3][15].setAffichage('S');  // Salle 2 ici st regis avec placement en (x) et (y)
    m_plateau[3][16].setAffichage('T');

    m_plateau[4][13].setAffichage('R');
    m_plateau[4][14].setAffichage('E');
    m_plateau[4][15].setAffichage('G');
    m_plateau[4][16].setAffichage('I');
    m_plateau[4][17].setAffichage('S');


    m_plateau[3][24].setAffichage('J');  // Salle 3 "jack demesy" en fonction de (x) et (y)
    m_plateau[3][25].setAffichage('A');
    m_plateau[3][26].setAffichage('C');
    m_plateau[3][27].setAffichage('K');

    m_plateau[4][23].setAffichage('D');
    m_plateau[4][24].setAffichage('E');
    m_plateau[4][25].setAffichage('M');
    m_plateau[4][26].setAffichage('E');
    m_plateau[4][27].setAffichage('S');
    m_plateau[4][28].setAffichage('Y');


    m_plateau[14][4].setAffichage('L');  // Salle 4 "LA MAISON" salle hypothèse
    m_plateau[14][5].setAffichage('A');
    m_plateau[14][7].setAffichage('M');
    m_plateau[14][8].setAffichage('A');
    m_plateau[14][9].setAffichage('I');
    m_plateau[14][10].setAffichage('S');
    m_plateau[14][11].setAffichage('O');
    m_plateau[14][12].setAffichage('N');


    m_plateau[14][23].setAffichage('C');  // Salle 5 "Cimetiere"
    m_plateau[14][24].setAffichage('I');
    m_plateau[14][25].setAffichage('M');
    m_plateau[14][26].setAffichage('E');
    m_plateau[14][27].setAffichage('T');
    m_plateau[14][28].setAffichage('I');

    m_plateau[15][24].setAffichage('E');
    m_plateau[15][25].setAffichage('R');
    m_plateau[15][26].setAffichage('E');


    m_plateau[27][4].setAffichage('E');  // Salle 6 "Elis Island"
    m_plateau[27][5].setAffichage('L');
    m_plateau[27][6].setAffichage('I');
    m_plateau[27][7].setAffichage('S');

    m_plateau[28][3].setAffichage('I');
    m_plateau[28][4].setAffichage('S');
    m_plateau[28][5].setAffichage('L');
    m_plateau[28][6].setAffichage('A');
    m_plateau[28][7].setAffichage('N');
    m_plateau[28][8].setAffichage('D');


    m_plateau[28][13].setAffichage('S');  // Salle 7 "Savoca"
    m_plateau[28][14].setAffichage('A');
    m_plateau[28][15].setAffichage('V');
    m_plateau[28][16].setAffichage('O');
    m_plateau[28][17].setAffichage('C');
    m_plateau[28][18].setAffichage('A');


    m_plateau[27][24].setAffichage('S');  // Salle 8 "San Nicolo"
    m_plateau[27][25].setAffichage('A');
    m_plateau[27][26].setAffichage('N');

    m_plateau[28][23].setAffichage('N');
    m_plateau[28][24].setAffichage('I');
    m_plateau[28][25].setAffichage('C');
    m_plateau[28][26].setAffichage('O');
    m_plateau[28][27].setAffichage('L');
    m_plateau[28][28].setAffichage('O');

}
///affichage du plateau
void Plateau::afficher()
{
    system ("CLS");

    Color (15,0);
    for (int i=1;i<31;i++)
    {
        for (int j=1;j<31;j++)
        {
            if(m_plateau[i][j].getType() == 101)
            {
                Color(1,0);
            }

            if(m_plateau[i][j].getType() == 102)
            {
                Color(2,0);
            }

            if(m_plateau[i][j].getType() == 103)
            {
                Color(3,0);
            }

            if(m_plateau[i][j].getType() == 104)
            {
                Color(4,0);
            }
            if (m_plateau[i][j].getAffichage() =='A' || m_plateau[i][j].getAffichage() =='B' || m_plateau[i][j].getAffichage() =='C' || m_plateau[i][j].getAffichage() =='D' || m_plateau[i][j].getAffichage() =='E' || m_plateau[i][j].getAffichage() =='F' || m_plateau[i][j].getAffichage() =='G' || m_plateau[i][j].getAffichage() =='H' || m_plateau[i][j].getAffichage() =='I' || m_plateau[i][j].getAffichage() =='J' || m_plateau[i][j].getAffichage() =='K' || m_plateau[i][j].getAffichage() =='L' || m_plateau[i][j].getAffichage() =='M' || m_plateau[i][j].getAffichage() =='N' || m_plateau[i][j].getAffichage() =='O' || m_plateau[i][j].getAffichage() =='P' || m_plateau[i][j].getAffichage() =='Q' || m_plateau[i][j].getAffichage() =='R' || m_plateau[i][j].getAffichage() =='S' || m_plateau[i][j].getAffichage() =='T' || m_plateau[i][j].getAffichage() =='U' || m_plateau[i][j].getAffichage() =='V' || m_plateau[i][j].getAffichage() =='W' || m_plateau[i][j].getAffichage() =='X' || m_plateau[i][j].getAffichage() =='Y' || m_plateau[i][j].getAffichage() =='Z')
            {
                Color(14,0);
            }
            if(m_plateau[i][j].getType() == 99)
            {
                Color(7,0);
            }
            if (m_plateau[i][j].getType() == 99)
           {
                Color (13,0);

           }
        ///creation d'un espace entre chaque colonne
            std::cout << m_plateau[i][j].getAffichage() << "";
            Color (15,0);
        }

        std::cout << std::endl;
    }


}

///affichage des joueurs 1,2,3,4 en fonction de s'il est vivant ou mort

void Plateau::majplateau(Joueur *joueur1, Joueur *joueur2, Joueur *joueur3, Joueur *joueur4)
{
    initialisation ();
    char joueur_1 = 0x03; char joueur_2 = 0x04; char joueur_3 = 0x05; char joueur_4 = 0x06;

    for (int i=1;i<31;i++)
    {
        for (int j=1;j<31;j++)
        {
            m_plateau[i][j].setJoueur(NULL);
        }
    }

    m_plateau[joueur1->getPosx()][joueur1->getPosy()].setType(101);
    if (joueur1->getVie() == false)
    {
        m_plateau[joueur1->getPosx()][joueur1->getPosy()].setType(0);
    }
    m_plateau[joueur2->getPosx()][joueur2->getPosy()].setType(102);
    if (joueur2->getVie() == false)
    {
        m_plateau[joueur2->getPosx()][joueur2->getPosy()].setType(0);
    }
    m_plateau[joueur3->getPosx()][joueur3->getPosy()].setType(103);
    if (joueur3->getVie() == false)
    {
        m_plateau[joueur3->getPosx()][joueur3->getPosy()].setType(0);
    }
    m_plateau[joueur4->getPosx()][joueur4->getPosy()].setType(104);
    if (joueur4->getVie() == false)
    {
        m_plateau[joueur4->getPosx()][joueur4->getPosy()].setType(0);
    }

    for (int i=1;i<31;i++)
    {
        for (int j=1;j<31;j++)
        {
           if (m_plateau[i][j].getType() == 101)
           {
                Color (1,0);
                m_plateau[i][j].setAffichage(joueur_1);
           }

           if (m_plateau[i][j].getType() == 102)
           {
                Color (2,0);
                m_plateau[i][j].setAffichage(joueur_2);
           }

           if (m_plateau[i][j].getType() == 103)
           {
                Color (4,0);
                m_plateau[i][j].setAffichage(joueur_3);
           }

           if (m_plateau[i][j].getType() == 104)
           {
                Color (14,0);
                m_plateau[i][j].setAffichage(joueur_4);
           }

        }
    }
}

/// information déroulement du jeu

void Plateau::information1(int i,Joueur *a)
{
    gotoligcol (0, 65);
    std::cout << "C'est au tour de ";
    Color (1,0);
    std::cout << a->getNom_joueur() << std::endl;
    Color (15,0);
    gotoligcol (2, 65);
    Color (1,0);
    std::cout << a->getNom_joueur();
    Color (15,0);
    std::cout << " a encore " << a->getLancer_de()-i << " deplacements possibles." << std::endl;

    gotoligcol(5, 65);
    std::cout << "Carte Personnage : " << a->getSuspect().getNom_suspect() << std::endl;
    gotoligcol(6, 65);
    std::cout << "Carte Arme : " << a->getArme().getNom_arme() << std::endl;
    gotoligcol(7, 65);
    std::cout << "Carte Lieu : " << a->getLieu().getNom_lieu() << std::endl;
    gotoligcol(9, 65);
    std::cout << "Pour se deplacer utiliser z, q, s, d" << std::endl;
    gotoligcol(10, 65);
}

void Plateau::information2(int i,Joueur *a)
{
    gotoligcol (0, 65);
    std::cout << "C'est au tour de ";
    Color (2,0);
    std::cout << a->getNom_joueur() << std::endl;
    Color (15,0);
    gotoligcol (2, 65);
    Color (2,0);
    std::cout << a->getNom_joueur();
    Color (15,0);
    std::cout << " a encore " << a->getLancer_de()-i << " deplacements possibles." << std::endl;

    gotoligcol(5, 65);
    std::cout << "Carte Personnage : " << a->getSuspect().getNom_suspect() << std::endl;
    gotoligcol(6, 65);
    std::cout << "Carte Arme : " << a->getArme().getNom_arme() << std::endl;
    gotoligcol(7, 65);
    std::cout << "Carte Lieu : " << a->getLieu().getNom_lieu() << std::endl;
    gotoligcol(9, 65);
    std::cout << "Pour se deplacer utiliser z, q, s, d" << std::endl;
    gotoligcol(10, 65);
}

void Plateau::information3(int i,Joueur *a)
{
    gotoligcol (0, 65);
    std::cout << "C'est au tour de ";
    Color (11,0);
    std::cout << a->getNom_joueur() << std::endl;
    Color (15,0);
    gotoligcol (2, 65);
    Color (11,0);
    std::cout << a->getNom_joueur();
    Color (15,0);
    std::cout << " a encore " << a->getLancer_de()-i << " deplacements possibles." << std::endl;

    gotoligcol(5, 65);
    std::cout << "Carte Personnage : " << a->getSuspect().getNom_suspect() << std::endl;
    gotoligcol(6, 65);
    std::cout << "Carte Arme : " << a->getArme().getNom_arme() << std::endl;
    gotoligcol(7, 65);
    std::cout << "Carte Lieu : " << a->getLieu().getNom_lieu() << std::endl;
    gotoligcol(9, 65);
    std::cout << "Pour se deplacer utiliser z, q, s, d" << std::endl;
    gotoligcol(10, 65);
}

void Plateau::information4(int i,Joueur *a)
{
    gotoligcol (0, 65);
    std::cout << "C'est au tour de ";
    Color (4,0);
    std::cout << a->getNom_joueur() << std::endl;
    Color (15,0);
    gotoligcol (2, 65);
    Color (4,0);
    std::cout << a->getNom_joueur();
    Color (15,0);
    std::cout << " a encore " << a->getLancer_de()-i << " deplacements possibles." << std::endl;

    gotoligcol(5, 65);
    std::cout << "Carte Personnage : " << a->getSuspect().getNom_suspect() << std::endl;
    gotoligcol(6, 65);
    std::cout << "Carte Arme : " << a->getArme().getNom_arme() << std::endl;
    gotoligcol(7, 65);
    std::cout << "Carte Lieu : " << a->getLieu().getNom_lieu() << std::endl;
    gotoligcol(9, 65);
    std::cout << "Pour se deplacer utiliser z, q, s, d" << std::endl;
    gotoligcol(10, 65);
}
