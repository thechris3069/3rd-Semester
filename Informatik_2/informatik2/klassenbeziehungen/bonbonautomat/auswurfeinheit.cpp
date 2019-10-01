/*
 * Definition von Methoden der Klasse Auswurfeinheit
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "auswurfeinheit.h"

#include <iostream>
using namespace std;

Auswurfeinheit::Auswurfeinheit()
{
    fahreZurueck();
}

void Auswurfeinheit::fahreVor()
{
    cout << "Auswurfeinheit faehrt nach vorne..." << endl;
}

void Auswurfeinheit::fahreZurueck()
{
    cout << "Auswurfeinheit faehrt zurueck..." << endl;
}
