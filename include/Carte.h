#ifndef CARTE_H
#define CARTE_H

#include <iostream>

class Carte
{
    protected:
        std::string m_type_carte;
        bool m_meurtrier;


    public:
        // Constructeurs et destructeur
        Carte();
        Carte (std::string type_carte, bool m);
        ~Carte();

        //Getters
        std::string getType_carte()const;
        bool getMeurtrier() const;

        //Setters
        void setType_carte(std::string type_carte);
        void setMeurtrier(bool m);

        //Méthodes
};


class Suspect : public Carte
{
    private:
        bool m_suspect_meurtrier;
        std::string m_nom_suspect;

    public:
        Suspect();
        Suspect (bool suspect_meurtrier, std::string nom_suspect);
        ~Suspect();

        //Getters
        bool getSuspect_meurtrier()const;
        std::string getNom_suspect()const;

        //Setters
        void setSuspect_meurtrier(bool suspect_meurtrier);
        void setNom_suspect(std::string nom_suspect);

        //Méthodes
        void chargement_enveloppe_suspect();
        void sauvegarde_enveloppe_suspect();
};


class Lieu :  public Carte
{
    private:
        bool m_lieu_meurtrier;
        std::string m_nom_lieu;

    public:
        // Constructeurs et destructeur
        Lieu();
        Lieu (bool lieu_meurtrier, std::string nom_lieu);
        ~Lieu();

        //Getters
        bool getLieu_meurtrier()const;
        std::string getNom_lieu()const;

        //Setters
        void setLieu_meurtrier(bool lieu_meurtrier);
        void setNom_lieu(std::string nom_lieu);

        //Méthodes
        void chargement_enveloppe_lieu();
        void sauvegarde_enveloppe_lieu();
};


class Arme : public Carte
{

    private:
        bool m_arme_meurtrier;
        std::string m_nom_arme;

    public:
        // Constructeurs et destructeur
        Arme();
        Arme (bool arme_meurtrier, std::string nom_arme);
        ~Arme();

        //Getters
        bool getArme_meurtrier()const;
        std::string getNom_arme()const;

        //Setters
        void setArme_meurtrier(bool arme_meurtrier);
        void setNom_arme(std::string nom_arme);

        //Méthodes
        void chargement_enveloppe_arme();
        void sauvegarde_enveloppe_arme();
};


#endif // CARTE_H
