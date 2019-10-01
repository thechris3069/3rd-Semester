/*
 * Vorlesungsbeispiel Informatik 2, 2.4.2019
 * Thema: Realisierung von Assoziationen in C++
 *
 * Klasse Aufgabe: enthaelt Beschreibung einer Aufgabe (kann verschiedenen Personen zugewiesen werden)
 *
 * Claudia Meitinger
 */

#ifndef AUFGABE_H
#define AUFGABE_H

#include <iostream>

class Aufgabe
{
private:
    std::string m_beschreibung;
public:
    Aufgabe(std::string beschreibung);
    void ausgeben();
};

#endif // AUFGABE_H
