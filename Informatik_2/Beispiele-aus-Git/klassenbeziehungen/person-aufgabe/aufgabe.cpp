/*
 * Vorlesungsbeispiel Informatik 2, 2.4.2019
 * Thema: Realisierung von Assoziationen in C++
 *
 * Klasse Aufgabe: enthaelt Beschreibung einer Aufgabe (kann verschiedenen Personen zugewiesen werden)
 *
 * Claudia Meitinger
 */

#include "aufgabe.h"
#include <iostream>

using namespace std;

Aufgabe::Aufgabe(std::string beschreibung)
{
    m_beschreibung = beschreibung;
}


void Aufgabe::ausgeben()
{
    cout << m_beschreibung << endl;
}
