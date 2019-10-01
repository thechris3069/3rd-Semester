/*
 * Modellierung eines Haendlers in der Hoehlenwelt im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 15.4.2019
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef TRADER_H
#define TRADER_H

#include <vector>

#include "inventory.h"

class Trader
{
private:
    int m_gold;   // Anzahl der Goldstuecke
    std::vector<Inventory *> m_inventory; // zu verkaufende Gegenstaende

public:
    /*
     * Konstruktor - initialisiert Datenelemente
     */
    Trader();

    /*
     * Kopierkonstruktor
     */
    Trader(const Trader &o) = delete;

    /*
     * Zuweisungsoperator
     */
    Trader &operator=(const Trader &o) = delete;

    /*
     * Destruktor
     */
    ~Trader();

    /*
     * Inventar anzeigen
     */
    void showInventory() const;

    /*
     * Preis eines Gegenstandes an Position idx abfragen
     */
    int getPrice(unsigned int idx) const;

    /*
     * Inventar verkaufen (Entnahme eines Gegenstandes und Erhoehen der Goldmenge)
     * idx: Index des zu verkaufenden Gegenstandes im Vektor
     * Rueckgabe: Zeiger auf Inventargegenstand, der aus dem Vektor entnommen wird,
     *            um ihn dem Spieler hinzuzufuegen; nullptr im Falle eines ungueltigen Index
     */
    Inventory *sellInventory(unsigned int idx);
};

#endif // TRADER_H
