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

#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED
///  Inclusion des librairies ///
#include <iostream>
#include <conio.h>
#include <windows.h>

/* https://pedago-ece.campusonline.me/course/view.php?id=5172 */

void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond); // fonction d'affichage de couleurs

/// classe provenant du campus
class Console
{
    private:
        /// Empêcher la création
        Console();
        ~Console();

        // Empecher la copie d'objet...
        Console& operator= (const Console&){ return *this;}
        Console (const Console&){}

        // Attributs
        static Console* m_instance;

        // Méthodes privées
    public:
        // Méthodes statiques (publiques)
        static Console* getInstance();
        static void deleteInstance();

        // Méthodes publiques
        bool isKeyboardPressed();
        int getInputKey();
};

#endif // CONSOLE_H_INCLUDED
