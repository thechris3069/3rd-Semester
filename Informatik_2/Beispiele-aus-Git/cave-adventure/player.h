/*
 * Initiale Variante des Spielers im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 25.3.2019
 *
 * 1.4.2019 - Name des Spielers hinzugefuegt
 *            isAlive hinzugefuegt
 *            setPosition hinzugefuegt
 * 5.4.2019 - Abfrage der Spielerposition hinzugefuegt
 *            "gewonnen" mit Setzen und Abfragen hinzugefuegt
 *            Veraenderung von Gold hinzugefuegt
 *            decreaseHealth hinzugefuegt
 * 15.4.2019 - Inventar hinzugefuegt
 *             Aktionen abhaengig vom aktuellen Raum
 *             getBestWeapon
 * 3.5.2019  - buyInventory
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "inventorylist.h"
class Room;

class Player
{
private:
    int m_posRow; // Zeile im Spielfeld, an der sich der Spieler befindet (0: Norden, ROW_MAX: Sueden)
    int m_posCol; // Spalte im Spielfeld, an der sich der Spieler befindet (0: Westen, COL_MAX: Osten)
    unsigned int m_nrRows; // ROW_MAX (wird ueber Welt festgelegt)
    unsigned int m_nrCols; // COL_MAX (wird ueber Welt festgelegt)
    int m_healthPoints; // Gesundheitszustand des Spielers (0: sehr schlecht .. 100: sehr gut)
    int m_gold;   // Anzahl der Goldstuecke
    bool m_hasWon; // true, wenn gewonnen, false sonst
    const std::string m_name; // Name des Spielers
    InventoryList m_weapons; // Liste mit Waffen
    InventoryList m_consumables; // Liste mit Verbrauchsgegenstaenden
    /*
     * Methode, um den Spieler um deltaRow und deltaCol Spielfelder in jeder Richtung zu bewegen
     */
    void move(int deltaRow, int deltaCol);
    /*
     * Methoden, um Spieler einen Schritt in der jeweiligen Himmelsrichtung zu bewegen
     */
    void moveNorth();
    void moveSouth();
    void moveWest();
    void moveEast();
    /*
     * Methode zum Abruf der wirksamsten Waffe aus dem Inventar - Rueckgabe des nullptr, falls keine vorhanden
     */
    const Weapon *getBestWeapon() const;
    /*
     * Methode zum Bestimmen, ob Consumables im Inventar vorhanden sind
     */
    bool hasConsumable() const;
    /*
     * Methode zum Angreifen einer Kreatur in einem Raum
     */
    void attackCreature(Room *pRoom) const;
    /*
     * Methode zur Anzeige des Inventars
     */
    void showInventory() const;
    /*
     * Methode zum Verbrauchen eines Lebensmittels aus dem Inventar
     */
    void consume();
public:
    /*
     * Konstruktor - initialisiert Datenelemente
     */
    Player(std::string name = "");

    /*
     * Kopierkonstruktor
     */
    Player(const Player &o) = delete;

    /*
     * Zuweisungsoperator
     */
    Player &operator=(const Player &o) = delete;

    /*
     * Destruktor - aktuell ohne Funktionalitaet
     */
    ~Player();

    /*
     * Anzeige aller moeglichen Spieleraktionen auf dem Bildschirm (abhaengig vom aktuellen Raum)
     * - Bewegung nach (w)esten, (o)sten, (n)orden, (s)ueden
     * - (i)nventar anzeigen
     * - (k)reatur angreifen
     * - (h)andeln
     * - (g)esundheitszustand verbessern
     */
    void showActions(Room *pRoom) const;

    /*
     * Ausfuehrung einer Spieleraktion (vgl. showActions)
     */
    void executeAction(char action, Room *pRoom);

    /*
     * Anzeige des Spielerstatus (Position, Gesundheitszustand, Goldstuecke)
     * auf dem Bildschirm
     */
    void showInfo() const;

    /*
     * Abfrage, ob Spieler noch spielfaehig ist (Gesundheitszustand > 0 Punkte)
     */
    bool isAlive() const;

    /*
     * Verringerung des Gesundheitszustands (z.B. infolge Angriff einer Kreatur)
     */
    void decreaseHealth(unsigned int health);

    /*
     * Gold hinzufuegen und abfragen
     */
    void increaseGold(unsigned int gold) { m_gold += gold; }
    int getGold() const { return m_gold; }

    /*
     * gewonnen-Zustand setzen und abfragen
     */
    void setWon() { m_hasWon = true; }
    bool hasWon() const { return m_hasWon; }

    /*
     * Spielfeldgrenzen festlegen => row in [0 .. nrRows-1], col in [0 .. nrCols-1]
     */
    void setPositionBoundaries (unsigned int nrRows, unsigned int nrCols);

    /*
     * Spieler an bestimmte Position im Spielfeld setzen (z.B. Startposition)
     */
    void setPosition (int row, int col);

    /*
     * Abfrage der Spielerposition
     */
    int getRow() { return m_posRow; }
    int getCol() { return m_posCol; }

    /*
     * Methode zum Kaufen von Inventar, Preis wird vom Gold abgezogen
     */
    void buyInventory(Inventory *p);
};

#endif // PLAYER_H
