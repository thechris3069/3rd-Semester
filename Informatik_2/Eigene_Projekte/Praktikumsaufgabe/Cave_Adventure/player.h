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
    public:  //PRIVATE FUNKTIONIERT NICHT
        unsigned int reihe, spalte;                                 //CS: Wo kommt das hin, hab noch komische Fehler wenn ich die nur im Header deklarier
        std::string inhalt;
    };

    Player(uint8_t groesseSpielfeld =15);
    Player(std::string name, uint8_t groesseSpielfeld);
    ~Player();
        bool nextmove();

private:
        uint8_t m_groesseSpielfeld{20};

        std::string m_name{"Player_1"};
    void machSpielfeld(uint8_t );
    void ausgabe() const;
    bool move();
    void geheEinFeld(int, int);
        struct Position m_position;


uint8_t m_anzahl_gold;
uint8_t m_anzahl_armor;
int aktPosition;
uint8_t m_anzahl_health;
int *position;
};

#endif // PLAYER_H
