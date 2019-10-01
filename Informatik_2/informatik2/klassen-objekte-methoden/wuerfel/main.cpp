/*
 * Für ein Wuerfelspiel sind mehrere Wuerfel in unterschiedlichen
 * Farben und mit verschiedenen Maximalwerten notwendig.
 * Diese Wuerfel sollen elektronisch zur Verfuegung gestellt werden.
 * Implementieren Sie ein Programm, bei dem im Hauptprogramm drei
 * verschiedene Wuerfel (gruen, 1-20; gelb, 1-6; rot, 1-10)
 * je 10x gewürfelt werden und die gewuerfelte Augenzahl auf dem
 * Bildschirm ausgegeben wird!
 *
 * Vorlesungsbeispiel Informatik 2
 *
 * Claudia Meitinger
 * 16.10.2017
 */

#include <iostream>
#include <cstdlib> // srand, rand
using namespace std;

#include "wuerfel.h"

#define ANZAHL_WUERFEL 3

int main()
{
    Wuerfel w[ANZAHL_WUERFEL] { { "gruen", 20 }, { "gelb" }, { "rot", 10 } };

    // Pseudo-Zufallszahlengenerator initialisieren
    srand(time(0));

    // 10x wuerfeln
    for ( unsigned int i = 0; i < 10; i++ )
    {
        // ... jeden Wuerfel ...
        for ( unsigned int j = 0; j < ANZAHL_WUERFEL; j++ )
        {
            w[j].wuerfeln();
            w[j].anzeigen();
        }
        cout << endl;
    }

    return 0;
}

