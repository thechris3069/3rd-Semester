#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <string>

class Player
{

public:
    Player();
    ~Player();
    void ausgabe() const;

private:
u_int8_t m_anzahl_gold;
u_int8_t m_anzahl_armor;
u_int8_t m_anzahl_health;

};

#endif // PLAYER_H
