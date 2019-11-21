#include "caveadventure.h"

CaveAdventure::CaveAdventure(std::string spielername ,unsigned int  groesseSpielfeld)
    :m_player(spielername, groesseSpielfeld), m_world(groesseSpielfeld)
{
nextMove();
}

void CaveAdventure::nextMove()
{
    while(m_player.nextmove());    //UEBERPRUEF, OB NEXT MOVE MÖGLICH IST, ANSTATT DIE GROESSESPIELFELD IMMER ZU KOPIEREN UND IN JEDEM OBJEKT ZU SPEICHERN
}

CaveAdventure::~CaveAdventure()
{

}
