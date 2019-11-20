#include "world.h"

World::World(unsigned int groesseSpielfeld)
    :reihe(groesseSpielfeld), spalte(groesseSpielfeld)
{
    std::string m_inhalt{"Hallo Welt"};

    m_inhalt = zuweisen();

}


std::string World::zuweisen()

{
    srand(time(0));
    const std::string moeglicheInhalte[5] = {"Haendler", "Gold", "Ausrüstung", "Lebensmittel", "EXIT"};
    int k = sizeof(moeglicheInhalte)/sizeof(std::string);
//    std::string inhalt = moeglicheInhalte[rand()%sizeof(moeglicheInhalte)];
    return "NOCH KEIN INHALT";
}


