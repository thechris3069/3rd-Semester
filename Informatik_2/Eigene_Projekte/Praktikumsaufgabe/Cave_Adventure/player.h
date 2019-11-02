#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits.h>



class Player
{

public:

    struct Position{
    public:
        unsigned int reihe, spalte;
    };
 const uint8_t m_groesseSpielfeld;
//    Player(const uint8_t groesseSpielfeld =15);
    Player(const std::string name = "player1", const uint8_t groesseSpielfeld = 15);
    ~Player();
        bool nextmove();
        void showinventory() const;
         void ausgabe() const;

private:

    std::string m_name{"Player_1"};
    void initpos(uint8_t);
    bool move();
    void geheEinFeld(const int x, const int y, const int anzahl_schritte = 1);
        struct Position m_position;


uint8_t m_anzahl_gold;
uint8_t m_anzahl_armor;
int aktPosition;
uint8_t m_anzahl_health;
int *position;
};

#endif // PLAYER_H
