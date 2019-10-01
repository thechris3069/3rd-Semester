/*
 * In einem Wuerfelspiel gibt es fuenf Wuerfel. Jeder Spieler darf bis zu drei Mal mit ein bis fuenf
 * Wuerfeln seiner Wahl wuerfeln, während die restlichen Wuerfel auf dem Tisch liegen bleiben.
 * Im Rahmen dieser Aufgabe soll dies elektronisch fuer einen Spieler umgesetzt werden.
 *
 * Konkret soll der Spieler die aktuellen Augenwerte aller Wuerfel angezeigt bekommen und auswaehlen
 * koennen, welche Wuerfel in den Wuerfelbecher kommen und nochmals geworfen werden. Dieser Vorgang
 * soll wie oben beschrieben wiederholt werden koennen.
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include <iostream>
using namespace std;

#include "wuerfel.h"
#include "wuerfelbecher.h"

int main()
{
    srand(time(0));

    Wuerfel alleWuerfel[ANZAHL_WUERFEL]; // Es gibt fuenf Wuerfel auf dem "Tisch"
    Wuerfelbecher becher;

    // Am Anfang werden alle Wuerfel in den Becher gelegt
    for ( unsigned int i = 0; i < ANZAHL_WUERFEL; i++ )
    {
        becher.einwerfen(alleWuerfel + i);
    }

    // Drei Versuche
    for ( unsigned int i = 0; i < 3; i++ )
    {
        // Wuerfeln
        becher.auswerfen();
        // Anzeigen
        for ( unsigned int j = 0; j < ANZAHL_WUERFEL; j++ )
        {
            cout << j << ": ";
            alleWuerfel[j].anzeigen();
        }
        // Welche Wuerfel in den Becher?
        if ( i < 2 )
        {
            while(1)
            {
                char eingabe;
                cout << "Welcher Wuerfel soll in den Becher (Abbruch mit x)? ";
                cin >> eingabe;
                while ( getchar() != '\n' );
                if ( eingabe == 'x' )
                    break;
                else if ( eingabe - '0' >= 0 && eingabe - '0' <= 4 )
                {
                    becher.einwerfen(alleWuerfel + (eingabe - '0'));
                }
                else
                    cout << "Ungueltige Wuerfelbezeichnung!" << endl;
            }
        }
    }

    return 0;
}
