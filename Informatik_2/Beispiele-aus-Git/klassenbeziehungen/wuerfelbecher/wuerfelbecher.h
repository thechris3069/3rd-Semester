/*
 * Klasse Wuerfelbecher zur Repraesentation eines Wuerfelbechers, mit dem bis zu 5 Wuerfel
 * gewuerfelt werden koennen.
 * Diese Wuerfel koennen nach Bedarf in den Wuerfelbecher eingeworfen bzw. aus diesem entfernt werden.
 * Beim Auswerfen der Wuerfel werden alle Wuerfel gewuerfelt.
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef WUERFELBECHER_H
#define WUERFELBECHER_H

#include "wuerfel.h"

#define ANZAHL_WUERFEL 5

class Wuerfelbecher
{
private:
    Wuerfel *m_Wuerfel[ANZAHL_WUERFEL]; // max. 5 Wuerfel im Wuerfelbecher
    unsigned int m_AnzahlWuerfel = 0;   // Anzahl der Wuerfel im Wuerfelbecher

public:
    // Konstruktor; zu Beginn ist der Wuerfelbecher leer.
    Wuerfelbecher();

    // Wuerfel an der Adresse pW in den Wuerfelbecher hineinlegen
    void einwerfen(Wuerfel *pW);

    // Alle Wuerfel wuerfeln und aus dem Becher entfernen
    void auswerfen();
};

#endif // WUERFELBECHER_H
