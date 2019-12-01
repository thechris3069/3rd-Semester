#include "player.h"

using namespace  std;

//Player::Player(const uint8_t groesseSpielfeld)
//    :m_anzahl_armor(5),m_groesseSpielfeld(groesseSpielfeld), m_anzahl_health(80), m_anzahl_gold(20), aktPosition(12)
//{
//    initpos(groesseSpielfeld);
//    ausgabe();
//}

Player::Player(const std::string name, const uint8_t groesseSpielfeld)
    :m_name(name) ,m_anzahl_armor(5),m_groesseSpielfeld(groesseSpielfeld), m_anzahl_health(80), m_anzahl_gold(20), aktPosition(12)
{
    initpos(groesseSpielfeld);
    ausgabe();
}

Player::~Player()
{
    std::cout << "Destruktor aufgerufen" << std::endl;
}

void Player::ausgabe() const
{
    cout << "Sie sind in der Reihe " << m_position.reihe +1 << " und Spalte " << m_position.spalte +1 << endl;
    cout << endl << endl;
}

bool Player::nextmove()
{
    bool schrittmoeglich = false;
    schrittmoeglich = move();
    return schrittmoeglich;
}

void Player::zeigeStatus() const
{
    cout << m_name << endl;
    cout << "Leben: " << static_cast<int>(m_anzahl_health) << endl;
    cout << "Rüstung: " << static_cast<int>(m_anzahl_armor) <<endl;
    cout << "Gold: " << static_cast<int>(m_anzahl_gold) <<endl;
}

bool Player::move()
{
    std::cout << "Geben Sie ein, wo Sie hingehen möchten" << std::endl << std::endl;
    char eingabe;
    std::cin >> eingabe;
    eingabe = toupper(eingabe);
    switch (eingabe)
    {
    case 'B':       //BEENDEN
        return false;

    case 'D':
        geheEinFeld( 1 ,0);
        break;

    case 'W':
        geheEinFeld(0,-1);
        break;

    case 'S':
        geheEinFeld(0 ,1);
        break;

    case 'A':
        geheEinFeld( -1 ,0);
        break;
    case 'I':
        showinventory();
        break;


    default:
        std::cout << "Falsche Eingabe" << std::endl;
        break;
        return true;
    }
    cin.ignore(INT_MAX, '\n');
}

void Player::initpos(uint8_t size)
{
    m_position.reihe  = aktPosition /m_groesseSpielfeld;
    m_position.spalte = aktPosition % m_groesseSpielfeld;
}


void Player::geheEinFeld(const  int x, const int y, const int anzahl_schritte)
{
    if (x)
    {
        if((m_position.spalte < m_groesseSpielfeld-anzahl_schritte && x > 0))
            m_position.spalte += anzahl_schritte;
        else if (m_position.spalte >= 0+anzahl_schritte
                 && x < 0)
            m_position.spalte -=anzahl_schritte;
        else
            cout << "Ende des Spielfelds erreicht" << endl;

    }
    else if (y)
    {
        if (m_position.reihe >= anzahl_schritte && y < 0)
            m_position.reihe -= anzahl_schritte;
        else if (m_position.reihe < m_groesseSpielfeld -anzahl_schritte && y > 0)
            m_position.reihe +=anzahl_schritte;
        else
            cout << "Ende des Spielfelds erreicht" << endl;
    }
}


//bool Player::verringereGold(int anzahl_goldstuecke)
//{
//    if (anzahl_goldstuecke >= m_anzahl_gold)
//    {
//        return false;
//    }
//    else
//        m_anzahl_gold -= anzahl_goldstuecke;
//    return true;
//}

void Player::veraendereGold(int anzahl_goldstuecke)
{
    m_anzahl_gold += anzahl_goldstuecke;
}


bool Player::verringereLeben(int anzahl_lebenspunkte)
{
    if(m_anzahl_health > anzahl_lebenspunkte)
    {
        m_anzahl_health -= anzahl_lebenspunkte;
        return true;
    }
    else
    {
        std::cout << "Game over" << std::endl;
        return false;
    }
}


void Player::showinventory() const
{
    cout <<"Gold: " << static_cast <int> (m_anzahl_gold) << endl;
    cout << "Leben: " << static_cast <int> (m_anzahl_health) <<endl;
    cout <<"Ruestung: " << static_cast <int> (m_anzahl_armor) << endl;
}
