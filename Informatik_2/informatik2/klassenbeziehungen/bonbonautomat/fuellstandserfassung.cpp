/*
 * Definition von Methoden der Klasse Fuellstandserfassung
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "fuellstandserfassung.h"

#include <iostream>
using namespace std;

Fuellstandserfassung::Fuellstandserfassung()
{
}

unsigned int Fuellstandserfassung::getFuellstand()
{
    unsigned int anzahl;
    cout << "Wie viele Bonbons sind da? ";
    cin >> anzahl;
    while(getchar() != '\n');
    cin.clear();

    return anzahl;
}
