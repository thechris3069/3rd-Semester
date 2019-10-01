/*
 * Definition von Methoden der Klasse Taster
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "taster.h"

#include <iostream>
using namespace std;

Taster::Taster()
{
}

bool Taster::istGedrueckt()
{
    char c;
    cout << "Taster gedrueckt (j/n)? ";
    cin >> c;
    while(getchar() != '\n');
    cin.clear();

    // j oder J bedeuten "gedrueckt"
    if ( c == 'j' || c == 'J' )
        return true;

    // alles andere "nicht gedrueckt"
    return false;
}

