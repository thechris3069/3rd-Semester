#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <string>



class Player
{

public:
    uint8_t m_groesseSpielfeld;
    Player(uint8_t groesseSpielfeld);
    ~Player();
    void ausgabe() const;
    void move();

private:
    void machSpielfeld(uint8_t );
    int wobinich();
uint8_t m_anzahl_gold;
uint8_t m_anzahl_armor;
int aktPosition;
uint8_t m_anzahl_health;
int *position;
};

#endif // PLAYER_H
