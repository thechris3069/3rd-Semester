/*
 * Deklaration einer Klasse Wuerfel zur Repraesentation von
 * Wuerfeln mit
 * - unterschiedlichen Farben
 * - unterschiedlichen max. Augenzahlen (1..maxAugen)
 *
 * Vorlesungsbeispiel Informatik 2
 * TODO: const ergaenzen
 *
 * Claudia Meitinger
 * 16.10.2017
 */

#ifndef WUERFEL_H
#define WUERFEL_H

#include <string>

class Wuerfel
{
private:
    std::string m_farbe; // Farbe des Wuerfels
    int m_aktAugen;      // aktuell gewuerfelte Zahl
    int m_maxAugen = 6;  // maximal moegliche Zahl

public:
    // Standardkonstruktor
    // falls nicht anders angegeben: Wuerfel in rot mit Zahlen 1 .. 6
    Wuerfel(std::string farbe = "rot", int maxAugen = 6);

    // wuerfeln => aktuelle Augenzahl wird zufaellig zwischen 1 und
    // maxAugen in Einerschritten variiert
    // im Hauptprogramm muss zuvor srand aufgerufen werden
    void wuerfeln();

    // Wuerfelinformationen auf dem Bildschirm ausgeben
    void anzeigen();

    // Aktuelle Augenzahl abfragen
    int getAktuelleAugenzahl() { return m_aktAugen; }
};

#endif // WUERFEL_H
