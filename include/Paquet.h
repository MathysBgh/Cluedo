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


#ifndef PAQUET_H
#define PAQUET_H
///  Inclusion des librairies ///
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <time.h>
#include <iostream>
#include <vector>
#include <time.h>

#include "case.h"
#include "carte.h"

Suspect remplir_paquet_suspect(std::vector<Suspect> paquet);
Lieu remplir_paquet_lieu(std::vector<Lieu> paquet);
Arme remplir_paquet_arme(std::vector<Arme> paquet);

std::vector<Suspect> melanger(std::vector<Suspect> paquet);
std::vector<Lieu> melanger(std::vector<Lieu> paquet);
std::vector<Arme> melanger(std::vector<Arme> paquet);


#endif // PAQUET_H
