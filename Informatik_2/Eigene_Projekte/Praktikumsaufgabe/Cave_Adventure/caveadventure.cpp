#include "caveadventure.h"

CaveAdventure::CaveAdventure(unsigned int  groesseSpielfeld)
    :m_player("Chris", groesseSpielfeld), m_world(groesseSpielfeld)
{
nextMove();
}

void CaveAdventure::nextMove()
{
    while(1)
    m_player.nextmove();
    //UEBERPRUEF, OB NEXT MOVE MÖGLICH IST, ANSTATT DIE GROESSESPIELFELD IMMER ZU KOPIEREN UND IN JEDEM OBJEKT ZU SPEICHERN

}

CaveAdventure::~CaveAdventure()
{

}
