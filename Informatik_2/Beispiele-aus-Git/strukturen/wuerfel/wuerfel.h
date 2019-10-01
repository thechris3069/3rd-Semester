#ifndef WUERFEL_H
#define WUERFEL_H

#define LAENGE_FARBE 20

// Deklaration des neuen Datentyps 'struct Wuerfel'
struct Wuerfel
{
    char m_farbe[LAENGE_FARBE]; // Farbe des Wuerfels
    int m_aktAugen;             // aktuell gewuerfelte Zahl
    int m_maxAugen;             // maximal moegliche Zahl
};

// Funktionsprototypen zum Verwenden eines Wuerfels
// Initialisieren eines Wuerfels mit der angegebenen Farbe und maximalen Augenzahl
void initWuerfel(struct Wuerfel *pW, const char *farbe, int maxAugen);

// wuerfeln => aktuelle Augenzahl wird zufaellig zwischen 1 und
// maxAugen in Einerschritten variiert
// im Hauptprogramm muss zuvor srand aufgerufen werden
void wuerfeln(struct Wuerfel *pW);

// Wuerfelinformationen auf dem Bildschirm ausgeben
void anzeigen(struct Wuerfel w);

#endif // WUERFEL_H
