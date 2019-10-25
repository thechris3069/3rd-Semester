#include "location.h"


Location::Location()
{
m_inhalt = zuweisen();

}
std::string Location::zuweisen()
{
    srand(time(0));
    const std::string moeglicheInhalte[5] = {"Haendler", "Gold", "Ausrüstung", "Lebensmittel", "EXIT"};
    Location::m_inhalt = moeglicheInhalte[rand()%sizeof(moeglicheInhalte)];
    return m_inhalt;

}

