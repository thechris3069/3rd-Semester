#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include "spielfeld.h"

class World
{
public:
    World();
    Spielfeld m_groesseSpielfeld;

private:
    std::string zuweisen();
};

#endif // WORLD_H
