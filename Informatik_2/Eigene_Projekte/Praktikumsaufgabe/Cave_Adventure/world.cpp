#include "world.h"

World::World()
{
m_groesseSpielfeld.m_inhalt = zuweisen();
}


std::string World::zuweisen()

{
    srand(time(0));
    const std::string moeglicheInhalte[5] = {"Haendler", "Gold", "Ausrüstung", "Lebensmittel", "EXIT"};
    std::string inhalt = moeglicheInhalte[rand()%sizeof(moeglicheInhalte)];
    return inhalt;
}


