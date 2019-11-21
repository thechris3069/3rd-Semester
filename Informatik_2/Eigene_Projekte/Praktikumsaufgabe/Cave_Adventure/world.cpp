#include "world.h"

World::World(unsigned int groesseSpielfeld)
    :reihe(groesseSpielfeld), spalte(groesseSpielfeld)
{
    std::string m_inhalt{"Hallo Welt"};

//    for(int j = 0; j < reihe; ++j)
//    {
//        for(int i = 0; i < spalte; ++spalte)
//        {
//                m_inhalt = zuweisen();
//        }
//    }
}


std::string World::zuweisen()

{
    srand(time(0));
    const std::string moeglicheInhalte[] = {"Haendler", "Leerer Raum", "Kreatur",
                                             "Goldmine", "Ausrüstung", "Lebensmittel", "EXIT"};
    int k = sizeof(moeglicheInhalte)/sizeof(std::string);
    std::string inhalt = moeglicheInhalte[rand()%sizeof(k)];
    return "NOCH KEIN INHALT";
}


