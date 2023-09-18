#include "console.h"

void gotoligcol( int lig, int col )
{
    ///ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord ); // handle vers le tampon d'écran
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte); //Définit les attributs des caractères écrits dans le tampon d'écran de la console par la fonction
}



Console* Console::m_instance = NULL;

Console::Console()
{
    m_instance = NULL;
}

Console::~Console()
{

}
///méthodes
void Console::deleteInstance()
{
    delete m_instance;
    m_instance = NULL;
}

///getters
Console* Console::getInstance()
{
    if (!Console::m_instance)
    {
        m_instance = new Console();
    }

    return m_instance;
}

// traduction de fonction venant du c vers le c++
int Console::getInputKey()
{
    return getch();
}

// detection de la touche presse, retourne la fonction kbhit provenant du langage c
bool Console::isKeyboardPressed()
{
    return kbhit();
}

