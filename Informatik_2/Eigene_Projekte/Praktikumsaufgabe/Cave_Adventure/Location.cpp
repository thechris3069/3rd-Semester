#include "location.h"


Location::Location()
{
m_inhalt = zuweisen();

}
std::string Location::zuweisen()
{
    srand(time(0));
    std::string moeglicheInhalte[5] = {"Haendler", "Gold", "Ausrüstung", "Lebensmittel", "EXIT"};
    Location::m_inhalt = rand()%5;
    return m_inhalt;

}

