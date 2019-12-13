#include "caveadventure.h"

CaveAdventure::CaveAdventure(std::string spielername ,unsigned int  groesseSpielfeld)
    :m_world(groesseSpielfeld),  m_player(spielername, groesseSpielfeld)
{
    m_player.initpos(m_world.m_startreihe, m_world.m_startspalte);

}


void CaveAdventure::nextMove()
{
   int  positionSpielerreihe = m_player.getPositionReihe();
   int positionSpielerspalte = m_player.getPositionSpalte();

      if(m_player.getPLayerHealth() < 20)
      {
          m_player.zeigeStatus();
      }

        m_player.ausgabe();
        m_world.raumBasisKlasse[positionSpielerreihe][positionSpielerspalte]->getEntryText();
        m_world.raumBasisKlasse[positionSpielerreihe][positionSpielerspalte]->interagieremitSpieler(&m_player);

   //UEBERPRUEF, OB NEXT MOVE MÖGLICH IST, ANSTATT DIE GROESSESPIELFELD IMMER ZU KOPIEREN UND IN JEDEM OBJEKT ZU SPEICHERN
}

CaveAdventure::~CaveAdventure()
{

}
