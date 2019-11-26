#include "world.h"

World::World(unsigned int groesseSpielfeld)
    :m_reihe(groesseSpielfeld), m_spalte(groesseSpielfeld)
{
    std::string m_inhalt{"Hallo Welt"};
    raumBasisKlasse = new Raum **[m_reihe];

    for(int i = 0; i < m_reihe; ++i)
    {
        raumBasisKlasse[i] = new Raum *[m_spalte];
        //                m_inhalt = Raumzuweisen();
        //                raumBasisKlasse[j][i] = RaumEXIT;
    }

    for (int reihe = 0; reihe < m_reihe; ++reihe)
    {
        for(int spalte = 0; spalte < m_spalte; ++spalte)
        {
            raumBasisKlasse[reihe][spalte] = nullptr;
        }
    }
    raumzuweisen();
}


void World::raumzuweisen()
{
    srand(time(0));
    m_startreihe = rand() % m_reihe;
    m_startspalte = rand() % m_spalte;
    raumBasisKlasse[m_startreihe][m_startspalte] = new RaumEINGANG();
//    int m_ausgangspalte, m_ausgangreihe;
//    do{
//    m_ausgangspalte = rand() % m_spalte;
//    m_ausgangreihe = rand() % m_reihe;
//    }
//    while(m_ausgangspalte == m_startspalte && m_ausgangreihe == m_startreihe);
//    raumBasisKlasse[m_ausgangreihe][m_ausgangspalte] = RaumEXIT();

//    for(int reihe = 0; reihe < m_reihe; ++reihe)
//    {
//        for(int spalte = 0; spalte < m_spalte; ++spalte)
//        {
//            raumBasisKlasse[reihe][spalte] = new RaumGol()d; // fuege rand noch ein
//        }
//    }
}
