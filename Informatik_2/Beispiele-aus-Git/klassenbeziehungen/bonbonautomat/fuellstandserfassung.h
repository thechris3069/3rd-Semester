/*
 * Klasse zur Ansteuerung einer Einheit zur Erfassung des Fuellstands eines Bonbonautomaten
 *
 * in der aktuellen Ausfuehrung wird diese ueber eine Tastatureingabe simuliert
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef FUELLSTANDSERFASSUNG_H
#define FUELLSTANDSERFASSUNG_H


class Fuellstandserfassung
{
public:
    Fuellstandserfassung();

    // Rueckgabe: Anzahl der Bonbons im Automaten
    unsigned int getFuellstand();
};

#endif // FUELLSTANDSERFASSUNG_H
