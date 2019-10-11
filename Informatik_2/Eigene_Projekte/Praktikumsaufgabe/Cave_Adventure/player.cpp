#include "player.h"

using namespace  std;

Player::Player()
    :m_anzahl_armor(5), m_anzahl_health(80), m_anzahl_gold(20)
{
    ausgabe();
}

Player::~Player()
{
    std::cout << "Konstruktor aufgerufen" << std::endl;
}

void Player::ausgabe() const
{
    cout << "Leben: " << static_cast<int>(m_anzahl_health) << endl;
    cout << "Rüstung: " << static_cast<int>(m_anzahl_armor) <<endl;
    cout << "Gold: " << static_cast<int>(m_anzahl_gold) <<endl;



}
