#include <iostream>
using namespace std;

#include "room.h"

Room::Room()
{
    m_entryText = "Dieser Raum ist undefiniert. Es sollte ihn nicht geben.";
}

Room::~Room()
{
}

RoomEmpty::RoomEmpty()
{
    m_entryText = "Hier herrscht gaehnende Leere...";
}

RoomEmpty::~RoomEmpty()
{
}

RoomEntry::RoomEntry()
{
    m_entryText = "Du bist am Eingang einer Hoehle mit flackernden Fackeln an der Wand...\n";
    m_entryText += "Suche den Weg nach draussen und sei' auf der Hut!";
}

RoomEntry::~RoomEntry()
{

}

RoomExit::RoomExit()
{
    m_entryText = "Du kannst ein helles Licht in der Ferne sehen...\n";
    m_entryText += "... es wird groesser! Es ist das Sonnenlicht!\n\n";
    m_entryText += "Du hast den Ausgang gefunden!";
}

RoomExit::~RoomExit()
{
}

string RoomExit::interactWithPlayer(Player *p)
{
    string text = "Du hast gewonnen!";
    p->setWon();
    return text;
}

RoomCreature::RoomCreature()
{
    try {
        m_creature = new Creature();
        m_entryText = "Eine gefaehrlich aussehende Kreatur (";
        m_entryText += m_creature->getName();
        m_entryText += ") erwartet Dich!";
    } catch (std::bad_alloc &e) {
        cerr << "Kreatur konnte nicht erzeugt werden!" << endl;
        cerr << e.what() << endl;
        throw; // re-throw
    }
}

RoomCreature::~RoomCreature()
{
    delete m_creature;
}

string RoomCreature::interactWithPlayer(Player *p)
{
    string text;
    if (m_creature->isAlive()) {
        p->decreaseHealth(m_creature->getDamagePoints());
        text = "Ihr Zustand: " + to_string(m_creature->getHealthPoints()) + " Punkte.";
    } else {
        text = "Sie ist keine Gefahr mehr!";
    }
    return text;
}


RoomTrader::RoomTrader()
{
    try {
        m_trader = new Trader();
        m_entryText = "Eine duestere Gestalt steht in der Ecke.\n";
        m_entryText += "Sie sieht so aus, als wolle sie mit Dir Geschaefte machen...";
    } catch (std::bad_alloc &e) {
        cerr << "Haendler konnte nicht erzeugt werden!" << endl;
        cerr << e.what() << endl;
        throw; // re-throw
    }
}

RoomTrader::~RoomTrader()
{
    delete m_trader;
}

string RoomTrader::interactWithPlayer(Player *p)
{
    string text;

    cout << "Angebot: " << endl;
    m_trader->showInventory();
    cout << "Was willst Du kaufen (0: nichts)? ";
    int val;
    cin >> val;
    if (cin.good() && val > 0) {
        val--;
        if (m_trader->getPrice(val) <= p->getGold() ) {
            Inventory *inv = m_trader->sellInventory(val);
            p->buyInventory(inv);
            if (inv)
                text = "Herzlichen Glueckwunsch zum Kauf!";
            else
                text = "Das war wohl nichts...";
        } else {
            text = "Das ist fuer Dich zu teuer!!!";
        }
    } else {
        cin.clear();
        while (cin.get() != '\n');
        text = "Vielleicht beim naechsten Mal...";
    }

    return text;
}

RoomGold::RoomGold()
{
    m_entryText = "Du bist in einer Goldgrube gelandet!";
    m_gold = rand() % 50 + 1; // max. 50 Goldstuecke im Raum
}

RoomGold::~RoomGold()
{
}

string RoomGold::interactWithPlayer(Player *p)
{
    string text;

    if (m_gold == 0)
        text = "Leider ist kein Gold mehr da!";
    else
        text = "Viel Spass mit " + to_string(m_gold) + " Goldstuecken!";

    p->increaseGold(m_gold);

    m_gold = 0;

    return text;
}
