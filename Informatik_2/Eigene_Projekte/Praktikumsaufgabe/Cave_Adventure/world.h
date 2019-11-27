#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <cstdlib>
#include "raum.h"

class World
{
public:
    World(unsigned int groesseSpielfeld);
            Raum ***raumBasisKlasse;
protected:

            void raumzuweisen();
            Raum* zufallsraum(Raum raum[]);
private:


//    std::string m_inhalt;
    const unsigned int m_reihe, m_spalte;
    unsigned int m_startreihe, m_startspalte;
};

#endif // WORLD_H
