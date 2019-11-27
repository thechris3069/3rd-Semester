#include "caveadventure.h"

CaveAdventure::CaveAdventure(std::string spielername ,unsigned int  groesseSpielfeld)
    :m_player(spielername, groesseSpielfeld), m_world(groesseSpielfeld)
{
nextMove();
}

void CaveAdventure::nextMove()
{
    int positionSpielerreihe, positionSpielerspalte;
    while(m_player.nextmove() && (m_player.getPLayerHealth() > 0))
    {

     positionSpielerreihe = m_player.getPositionReihe();
     positionSpielerspalte = m_player.getPositionSpalte();


             m_player.ausgabe();
        m_world.raumBasisKlasse[positionSpielerreihe][positionSpielerspalte]->getEntryText();
    };    //UEBERPRUEF, OB NEXT MOVE MÖGLICH IST, ANSTATT DIE GROESSESPIELFELD IMMER ZU KOPIEREN UND IN JEDEM OBJEKT ZU SPEICHERN
}

CaveAdventure::~CaveAdventure()
{

}
