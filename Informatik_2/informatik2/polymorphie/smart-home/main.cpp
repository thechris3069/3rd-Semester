/* In einem "Smart Home" soll die zentrale Haussteuerung zu
 * definierten Zeitpunkten automatisiert Aktionen ausfuehren.
 * Diese Aktionen umfassen das An-/Ausschalten von Lampen und
 * das Hoch-/Runterfahren von Rollos. Waehrend fuer das Schalten
 * von Lampen das Senden einer Nachricht an eine lampenspezifische
 * Adresse noetig ist, muessen fuer das Fahren eines Rollos zwei
 * Nachrichten an zwei rollospezifische Adressen geschickt werden.
 *
 * Entwerfen Sie eine Klassenstruktur mit einer Basisklasse Aktion
 * und davon abgeleiteten Klassen fuer die spezifischen Aktionen.
 * Dokumentieren Sie diese Struktur mit einem Klassediagramm und
 * implementieren Sie sie in C++.
 *
 * In einem Hauptprogramm sollen verschiedene Aktionen in einem Feld
 * abgelegt werden und in der dort hinterlegten Reihenfolge ausgefuehrt
 * werden (hier z.B. als Bildschirmausgabe).
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 *
 * 26.10.2017
 */

/* ------------ INCLUDES ---------------- */
#include <iostream>
#include <string>
using namespace std;

#include "lichtaktion.h"
#include "rolloaktion.h"

/* ------------ HAUPTPROGRAMM ----------- */
int main()
{
    // Feld aus Zeigern auf 5 Aktionen
    Aktion *aktionen[5];

    // Feld belegen
    aktionen[0] = new LichtAktion(10, "Kueche:1:0", 1);
    aktionen[1] = new LichtAktion(20, "Kueche:1:0", 0);
    aktionen[2] = new RolloAktion(30, "Wohnzimmer:2:1", "Wohnzimmer:2:2", 0);
    aktionen[3] = new LichtAktion(40, "Bad:1:0", 0);
    aktionen[4] = new RolloAktion(50, "Schlafzimmer:3:7", "Schlafzimmer:3:8", 0);

    cout << endl << endl;

    // ausfuehren auf allen Aktionen aufrufen
    for (unsigned int i = 0; i < 5; i++)
        aktionen[i]->ausfuehren();

    return 0;
}

