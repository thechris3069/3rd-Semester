/*
 * Definition der Methoden der Klasse Wuerfel
 *
 * Vorlesungsbeispiel Informatik 2
 * TODO: const ergaenzen
 *
 * Claudia Meitinger
 * 16.10.2017
 */

#include "wuerfel.h"

#include <iostream>
using namespace std;

Wuerfel::Wuerfel(string farbe, int maxAugen)
    : m_farbe(farbe), m_maxAugen(maxAugen)
{
    // Sicherstellen, dass max. Augenzahl >= 1 ist
    if(m_maxAugen <= 0)
        m_maxAugen = 1;

    // initialen Wuerfelwert bestimmen
    wuerfeln();
}

void Wuerfel::wuerfeln()
{
    m_aktAugen = rand() % m_maxAugen + 1;
}

void Wuerfel::anzeigen()
{
    cout << "Wuerfel mit der Farbe " << m_farbe << " zeigt ";
    cout << m_aktAugen << " an!" << endl;
}
