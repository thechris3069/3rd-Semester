#include <iostream>
using namespace std;

#include "player.h"
#include "room.h"

Player::Player(string name)
    : m_posRow(0),
      m_posCol(0),
      m_healthPoints(100),
      m_gold(5),
      m_hasWon(false),
      m_name(name)
{
    try {
        // zu Beginn hat der Spieler einen Stein...
        m_weapons.pushFront(new Rock());
    } catch (std::bad_alloc &e) {
        cerr << "Stein konnte nicht zum Inventar des Spielers hinzugefuegt werden!" << endl;
        cerr << e.what() << endl;
    }
    try {
        // ... einen Dolch...
        m_weapons.pushFront(new Dagger());
    } catch (std::bad_alloc &e) {
        cerr << "Dolch konnte nicht zum Inventar des Spielers hinzugefuegt werden!" << endl;
        cerr << e.what() << endl;
    }
    try {
        // ... und einen Zaubertrank.
        m_consumables.pushFront(new MagicPotion());
    } catch (std::bad_alloc &e) {
        cerr << "Zaubertrank konnte nicht zum Inventar des Spielers hinzugefuegt werden!" << endl;
        cerr << e.what() << endl;
    }
}

Player::~Player()
{
}

void Player::move(int deltaRow, int deltaCol)
{
    setPosition(m_posRow + deltaRow, m_posCol + deltaCol);
}

void Player::moveNorth()
{
    move(-1, 0);
}

void Player::moveSouth()
{
    move(1, 0);
}

void Player::moveWest()
{
    move(0, -1);
}

void Player::moveEast()
{
    move(0, 1);
}

const Weapon *Player::getBestWeapon() const
{
    const Weapon *pBestWeapon = nullptr;
    const Inventory *p;
    for (unsigned int i = 0; i < m_weapons.size(); ++i) {
        p = m_weapons.getElementAt(i);
        if (!pBestWeapon) {
            pBestWeapon = static_cast<const Weapon *>(p);
        } else if (static_cast<const Weapon *>(p)->getDamage() > pBestWeapon->getDamage()){
            pBestWeapon = static_cast<const Weapon *>(p);
        }
    }
    return pBestWeapon;
}

bool Player::hasConsumable() const
{
    if (m_consumables.size() > 0)
        return true;
    return false;
}

void Player::attackCreature(Room *pRoom) const
{
    RoomCreature *pR = static_cast<RoomCreature *>(pRoom);
    const Weapon *pW = getBestWeapon();
    if (pR && pW) {
        pR->getCreature()->attack(pW->getDamage());
    }
}

void Player::showInventory() const
{
    cout << m_weapons.getInfo();
    cout << m_consumables.getInfo();
}

void Player::buyInventory(Inventory *p)
{
    if (!p)
        return;

    if (p->isWeapon())
        m_weapons.pushFront(p);
    else if (p->isConsumable())
        m_consumables.pushFront(p);

    m_gold -= p->getPrice();
}

void Player::consume()
{
    unsigned int idx;
    cout << "Welches Lebensmittel willst Du zu Dir nehmen? ";
    cin >> idx;
    const Consumable *p = static_cast<const Consumable *>(m_consumables.getElementAt(idx-1));
    if (p) {
        m_healthPoints += p->getHealingValue();
        m_consumables.remove(idx-1);
    }
}

void Player::showActions(Room *pRoom) const
{
    cout << "Aktionen";
    if (!m_name.empty())
        cout << " von " << m_name;
    cout << ": " << endl;
    cout << " w - gehe nach Westen" << endl;
    cout << " o - gehe nach Osten" << endl;
    cout << " n - gehe nach Norden" << endl;
    cout << " s - gehe nach Sueden" << endl;

    // Inventar anzeigen, falls vorhanden
    if (m_consumables.size() + m_weapons.size() > 0)
        cout << " i - Inventar anzeigen" << endl;

    // Gesundheitszustand verbessern, falls Consumable im Inventory vorhanden ist
    if (hasConsumable())
        cout << " g - verbessere Gesundheitszustand" << endl;

    if (!pRoom)
        return;
    // Kreatur angreifen, falls Kreaturen-Raum und Waffe verfuegbar
    if (dynamic_cast<RoomCreature *>(pRoom) != nullptr && getBestWeapon()) {
        cout << " k - Kreatur angreifen" << endl;
    }

    // TODO: Handeln, falls Haendler-Raum

}

void Player::executeAction(char action, Room *pRoom)
{
    // TODO: anhand angezeigter Aktionen (-> showActions) abpruefen, ob Aktion gueltig ist

    switch(action)
    {
    case 'w':
        moveWest();
        break;
    case 'o':
        moveEast();
        break;
    case 'n':
        moveNorth();
        break;
    case 's':
        moveSouth();
        break;
    case 'i':
        showInventory();
        break;
    case 'k':
        attackCreature(pRoom);
        break;
    case 'g':
        consume();
        break;
    default:
        cout << "Ungueltige Aktion!" << endl;
    }
}

void Player::showInfo() const
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Der Spieler befindet sich an Position " << m_posRow << ", " << m_posCol << "." << endl;
    cout << "  Gesundheitszustand: " << m_healthPoints << endl;
    cout << "  Goldstuecke: " << m_gold << endl;
}

bool Player::isAlive() const
{
    if (m_healthPoints > 0)
        return true;
    return false;
}

void Player::decreaseHealth(unsigned int health)
{
    if (static_cast<int>(health) > m_healthPoints)
        m_healthPoints = 0;
    else
        m_healthPoints -= health;
}

void Player::setPositionBoundaries (unsigned int nrRows, unsigned int nrCols)
{
    m_nrRows = nrRows;
    m_nrCols = nrCols;
}

void Player::setPosition (int row, int col)
{
    if (row < 0)
        m_posRow = 0;
    else if (row >= static_cast<int>(m_nrRows))
        m_posRow = m_nrRows - 1;
    else
        m_posRow = row;

    if (col < 0)
        m_posCol = 0;
    else if (col >= static_cast<int>(m_nrCols))
        m_posCol = m_nrCols - 1;
    else
        m_posCol = col;

}
