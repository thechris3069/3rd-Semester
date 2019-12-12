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

    Player(const Player &p) = delete;
    Player operator =(const Player &) = delete;

    bool beendeSpiel;

    void zeigeStatus() const;

    int getPositionReihe() const
    {
        return m_position.reihe;
    }
    int getPositionSpalte() const
    {
        return m_position.spalte;
    }
    int getPLayerHealth() const
    {
        return m_anzahl_health;
    }
    void veraendereLeben(int deltaleben)
    {
            m_anzahl_health += deltaleben;
    }

    const uint8_t m_groesseSpielfeld;
    //    Player(const uint8_t groesseSpielfeld =15);
    Player(const std::string name = "player1", const uint8_t groesseSpielfeld = 15);
    ~Player();
    bool nextmove();
    void showinventory() const;
    void ausgabe() const;
//    bool verringereLeben(int anzahl_lebenspunkte);
    void veraendereGold(int anzahl_goldstuecke);
    void initpos(int reihe, int spalte);



private:

    bool move();
    void geheEinFeld(const int x, const int y, const int anzahl_schritte = 1);

    std::string m_name;
    struct Position m_position;
    uint8_t m_anzahl_gold;
    uint8_t m_anzahl_armor;
    int aktPosition;
    uint8_t m_anzahl_health;
    int *position;
};

#endif // PLAYER_H
