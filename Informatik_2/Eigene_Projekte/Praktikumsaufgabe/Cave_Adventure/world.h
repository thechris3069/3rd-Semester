#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include "spielfeld.h"

class World
{
public:
    World(unsigned int groesseSpielfeld);

private:
    std::string zuweisen();
    std::string m_inhalt;
    unsigned int reihe, spalte;
};

#endif // WORLD_H
