#include "Paquet.h"

std::vector<Suspect> melanger(std::vector<Suspect> paquet)
{
    srand(time(NULL));
    std::random_shuffle(paquet.begin(),paquet.end());
    return paquet;
}

std::vector<Lieu> melanger(std::vector<Lieu> paquet)
{
    srand(time(NULL));
    std::random_shuffle(paquet.begin(),paquet.end());
    return paquet;
}

std::vector<Arme> melanger(std::vector<Arme> paquet)
{
    srand(time(NULL));
    std::random_shuffle(paquet.begin(),paquet.end());
    return paquet;
}
