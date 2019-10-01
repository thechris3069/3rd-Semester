#include "caveadventure.h"

#include <iostream>
using namespace std;

CaveAdventure::CaveAdventure(string pfadZuHoehlendateien)
    : m_player("Claudia"),
      m_world(pfadZuHoehlendateien)
{
    m_player.setPositionBoundaries(m_world.getNrRows(), m_world.getNrCols());
    m_player.setPosition(m_world.getRowStart(), m_world.getColStart());
    cout << "------------------------------------------------------------" << endl;
    try {
        cout << m_world.getRoomAt(m_player.getRow(), m_player.getCol())->getEntryText() << endl;
    } catch(string &e) {
        cerr << "Exception gefangen: " << e << endl;
    }
    m_player.showInfo();
}

CaveAdventure::~CaveAdventure()
{

}

void CaveAdventure::doOneStep(char action)
{
    try {
        m_player.executeAction(action, m_world.getRoomAt(m_player.getRow(), m_player.getCol()));
        cout << "------------------------------------------------------------" << endl;
        cout << m_world.getRoomAt(m_player.getRow(), m_player.getCol())->getEntryText() << endl;
        cout << m_world.getRoomAt(m_player.getRow(), m_player.getCol())->interactWithPlayer(&m_player) << endl;
    } catch(string &e) {
        cerr << "Exception gefangen: " << e << endl;
    }
    m_player.showInfo();
}

bool CaveAdventure::isGameFinished() const
{
    if (!m_player.isAlive() || m_player.hasWon())
        return true;
    return false;
}

void CaveAdventure::getAndProcessUserInput()
{
    char action;
    try {
        m_player.showActions(m_world.getRoomAt(m_player.getRow(), m_player.getCol()));
        cout << "Was willst Du machen? ";
        cin >> action;
        cin.get(); // extract '\n'
        doOneStep(action);
    } catch(string &e) {
        cerr << "Exception gefangen: " << e << endl;
    }
}
