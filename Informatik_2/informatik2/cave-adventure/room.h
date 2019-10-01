/*
 * Initiale Variante der Raeume der Hoehlenwelt im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 5.4.2019
 *
 * 5.4.2019 - CM - Interaktion mit Spieler hinzugefuegt
 * 3.5.2019 - CM - Haendler hinzugefuegt
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef ROOM_H
#define ROOM_H

#include <string>

#include "player.h"
#include "creature.h"
#include "trader.h"

class Room
{
protected:
    std::string m_entryText;

public:
    /*
     * Konstruktor: Festlegen der Begruessungsnachricht, die beim Betreten eines
     *              Raums ausgegeben wird.
     */
    Room();

    /*
     * Kopierkonstruktor
     */
    Room(const Room &o) = delete;

    /*
     * Zuweisungsoperator
     */
    Room &operator=(const Room &o) = delete;

    /*
     * Destruktor
     */
    virtual ~Room();

    /*
     * Abfragen der Begruessungsnachricht
     */
    std::string getEntryText() const { return m_entryText; }

    /*
     * Interaktion mit dem Spieler durchfuehren - je nach Raum verschieden => virtual
     * Standardmaessig findet keine Interaktion statt.
     *
     * Rueckgabe: Text zur Information des Spielers
     */
    virtual std::string interactWithPlayer(Player *p) { return std::string(); }
};

class RoomEmpty : public Room
{
public:
    /*
     * Konstruktor
     */
    RoomEmpty();

    /*
     * Kopierkonstruktor
     */
    RoomEmpty(const RoomEmpty &o) = delete;

    /*
     * Zuweisungsoperator
     */
    RoomEmpty &operator=(const RoomEmpty &o) = delete;

    /*
     * Destruktor
     */
    ~RoomEmpty();
};

class RoomEntry : public Room
{
public:
    /*
     * Konstruktor
     */
    RoomEntry();

    /*
     * Kopierkonstruktor
     */
    RoomEntry(const RoomEntry &o) = delete;

    /*
     * Zuweisungsoperator
     */
    RoomEntry &operator=(const RoomEntry &o) = delete;

    /*
     * Destruktor
     */
    ~RoomEntry();
};

class RoomExit : public Room
{
public:
    /*
     * Konstruktor
     */
    RoomExit();

    /*
     * Kopierkonstruktor
     */
    RoomExit(const RoomExit &o) = delete;

    /*
     * Zuweisungsoperator
     */
    RoomExit &operator=(const RoomExit &o) = delete;

    /*
     * Destruktor
     */
    ~RoomExit();

    /*
     * Interaktion mit dem Spieler durchfuehren:
     * Spiel gewonnen
     */
    virtual std::string interactWithPlayer(Player *p);
};

class RoomCreature : public Room
{
private:
    Creature *m_creature;

public:
    /*
     * Konstruktor
     */
    RoomCreature();

    /*
     * Kopierkonstruktor
     */
    RoomCreature(const RoomCreature &o) = delete;

    /*
     * Zuweisungsoperator
     */
    RoomCreature &operator=(const RoomCreature &o) = delete;

    /*
     * Destruktor
     */
    ~RoomCreature();

    /*
     * Interaktion mit dem Spieler durchfuehren:
     * Kreatur (falls lebend) fuegt dem Spieler Schaden zu
     */
    virtual std::string interactWithPlayer(Player *p);

    /*
     * Zugriff auf Kreatur ermoeglichen
     */
    Creature *getCreature() { return m_creature; }
};

class RoomTrader : public Room
{
private:
    Trader *m_trader;
public:
    /*
     * Konstruktor
     */
    RoomTrader();

    /*
     * Kopierkonstruktor
     */
    RoomTrader(const RoomTrader &o) = delete;

    /*
     * Zuweisungsoperator
     */
    RoomTrader &operator=(const RoomTrader &o) = delete;

    /*
     * Destruktor
     */
    ~RoomTrader();

    /*
     * Interaktion mit dem Spieler durchfuehren:
     * Warenaustausch: wird spaeter hinzugefuegt
     */
    virtual std::string interactWithPlayer(Player *p);
};

class RoomGold : public Room
{
private:
    unsigned int m_gold;
public:
    /*
     * Konstruktor
     */
    RoomGold();

    /*
     * Kopierkonstruktor
     */
    RoomGold(const RoomGold &o) = delete;

    /*
     * Zuweisungsoperator
     */
    RoomGold &operator=(const RoomGold &o) = delete;

    /*
     * Destruktor
     */
    ~RoomGold();

    /*
     * Interaktion mit dem Spieler durchfuehren:
     * Gefundenes Gold hinzufuegen
     */
    virtual std::string interactWithPlayer(Player *p);
};

#endif // ROOM_H
