#include "creature.h"

Creature::Creature()
{
    int r = rand() % 100 + 1;

    if (r < 50) {
        m_name = "Riesenspinne";
        m_healthPoints = 10;
        m_damagePoints = 2;
    }
    else if (r < 80) {
        m_name = "Ogre";
        m_healthPoints = 30;
        m_damagePoints = 10;
    }
    else if (r < 95) {
        m_name = "Fledermaus-Kolonie";
        m_healthPoints = 100;
        m_damagePoints = 4;
    }
    else {
        m_name = "Steinbeisser";
        m_healthPoints = 80;
        m_damagePoints = 15;
    }
}

Creature::~Creature()
{

}

bool Creature::isAlive() const
{
    if (m_healthPoints > 0)
        return true;
    return false;
}

void Creature::attack(int damage)
{
    if (m_healthPoints >= damage) {
        m_healthPoints -= damage;
    } else {
        m_healthPoints = 0;
    }
}
