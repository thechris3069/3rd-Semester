#include "player.h"

using namespace  std;

Player::Player(uint8_t groesseSpielfeld)
    :m_anzahl_armor(5),m_groesseSpielfeld(groesseSpielfeld), m_anzahl_health(80), m_anzahl_gold(20), aktPosition(300)
{
    machSpielfeld(groesseSpielfeld);
   int zahl =  wobinich();

   cout << zahl << endl;
    ausgabe();
}

Player::~Player()
{
    std::cout << "Konstruktor aufgerufen" << std::endl;
}

void Player::ausgabe() const
{
    unsigned int reihe, spalte;
    cout << "Leben: " << static_cast<int>(m_anzahl_health) << endl;
    cout << "Rüstung: " << static_cast<int>(m_anzahl_armor) <<endl;
    cout << "Gold: " << static_cast<int>(m_anzahl_gold) <<endl;
    reihe = aktPosition / m_groesseSpielfeld;
    spalte = aktPosition % m_groesseSpielfeld;
    cout << "Sie sind in der Reihe " << reihe +1 << " und Spalte " << spalte << endl;
}

void Player::move()
{
    unsigned int reihe, spalte;
    reihe = aktPosition / m_groesseSpielfeld;
    spalte = aktPosition % m_groesseSpielfeld;
    char eingabe;
cin >> eingabe;
eingabe = toupper(eingabe);
switch (eingabe)
{
case 'D':
    if (spalte < 199)
    aktPosition = position + 1;
    else
    cout << "Ende des Spielfelds erreicht" << endl;
    break;
case 'W':
        if (reihe > 0)
    aktPosition = position - 200;
        else
    cout << "Ende des Spielfelds erreicht" << endl;
            break;
                                       // 200 ist länge Spielfeld noch abändern
case 'S':
    aktPosition = position + 200;
            break;
case 'A':
            if (reihe > 1)
    aktPosition = aktPosition -1;
    else
        cout << "Ende des Spielfelds erreicht" << endl;
            break;
default:
    cout << "Falsche Eingabe" << endl;
}
}

void Player::machSpielfeld(uint8_t size)
{
    position = new int [size*size]{0};

}

int Player::wobinich()
{
return *position; // noch ein Fehler
}
