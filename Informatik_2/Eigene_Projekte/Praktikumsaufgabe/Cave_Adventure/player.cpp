#include "player.h"

using namespace  std;


struct Position{
    unsigned int reihe, spalte;                                 //CS: Wo kommt das hin, hab noch komische Fehler wenn ich die nur im Header deklarier
    std::string inhalt;
};

Player::Player(uint8_t groesseSpielfeld)
    :m_anzahl_armor(5),m_groesseSpielfeld(groesseSpielfeld), m_anzahl_health(80), m_anzahl_gold(20), aktPosition(12)
{
    machSpielfeld(groesseSpielfeld);
    int zahl =  wobinich();

    cout << zahl << endl;
    ausgabe();
}

Player::~Player()
{
    std::cout << "Destruktor aufgerufen" << std::endl;
}

void Player::ausgabe() const
{
    unsigned int reihe, spalte;
    cout << "Leben: " << static_cast<int>(m_anzahl_health) << endl;
    cout << "Rüstung: " << static_cast<int>(m_anzahl_armor) <<endl;
    cout << "Gold: " << static_cast<int>(m_anzahl_gold) <<endl;
    cout << "Sie sind in der Reihe " << m_position.reihe +1 << " und Spalte " << m_position.spalte +1 << endl;
    cout << endl << endl;

}

bool Player::nextmove()
{
    bool schrittmoeglich = false;
    schrittmoeglich = move();
    ausgabe();
    return schrittmoeglich;
}

bool Player::move()
{
    //    reihe = aktPosition / m_groesseSpielfeld;
    //    spalte = aktPosition % m_groesseSpielfeld;
    char eingabe;
    cin >> eingabe;
    eingabe = toupper(eingabe);
    switch (eingabe)
    {
    case 'B':
        return false;

    case 'D':
        geheEinFeld( 1 ,0);
        break;

    case 'W':
        geheEinFeld(0,-1);;
        break;

    case 'S':
        geheEinFeld(0 ,1);
        break;

    case 'A':
        geheEinFeld( -1 ,0);
        break;


    default:
        cout << "Falsche Eingabe" << endl;
        break;
        return true;
    }
}

void Player::machSpielfeld(uint8_t size)
{
    position = new int [size*size]{0};
    m_position.reihe  = aktPosition /m_groesseSpielfeld;
    m_position.spalte = aktPosition % m_groesseSpielfeld;
}


void Player::geheEinFeld( int x, int y)
{
    if (x)
    {
        if((m_position.spalte < m_groesseSpielfeld-1 && x > 0))
            m_position.spalte += 1;
        else if (m_position.spalte > 0 && x < 0)
            m_position.spalte -=1;
        else
            cout << "Ende des Spielfelds erreicht" << endl;

    }
    else if (y)
    {
        if (m_position.reihe >= 1 && y < 0)
            m_position.reihe -= 1;
        else if (m_position.reihe < m_groesseSpielfeld -1 && y > 0)
            m_position.reihe +=1;
        else
            cout << "Ende des Spielfelds erreicht" << endl;
    }

}
