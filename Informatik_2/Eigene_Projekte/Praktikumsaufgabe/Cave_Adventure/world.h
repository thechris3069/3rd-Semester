#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <cstdlib>
#include "raum.h"
//#include "player.h"

class World
{
public:
    World(unsigned int groesseSpielfeld);
    Raum ***raumBasisKlasse;
    unsigned int m_startreihe, m_startspalte;
    World(const World &w) = delete;
    World operator = (const World &) = delete;

    Raum* getRaum(int zeile,int spalte)
    {
        return raumBasisKlasse[zeile][spalte];
    }
protected:
    void raumzuweisen();
    Raum* zufallsraum(Raum raum[]);
private:
    const unsigned int m_reihe, m_spalte;

};

#endif // WORLD_H
