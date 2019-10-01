/*
 * Klasse zur Abfrage eines Tasters
 *
 * in der aktuellen Ausfuehrung wird diese ueber eine Tastatureingabe simuliert
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef TASTER_H
#define TASTER_H

class Taster
{
public:
    Taster();

    // Rueckgabe true, falls gedrueckt, sonst false
    bool istGedrueckt();
};

#endif // TASTER_H
