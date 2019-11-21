#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <cstdlib>
#include "raum.h"

class World
{
public:
    World(unsigned int groesseSpielfeld);
    Raum raumBasisKlasse;
private:
    std::string zuweisen();
    std::string m_inhalt;
    unsigned int reihe, spalte;
};

#endif // WORLD_H
