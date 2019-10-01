/*
 * Klasse zur Ansteuerung der Auswurfeinheit eines Bonbonautomaten
 *
 * in der aktuellen Ausfuehrung wird diese ueber eine Bildschirmausgabe simuliert
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef AUSWURFEINHEIT_H
#define AUSWURFEINHEIT_H

class Auswurfeinheit
{
public:
    Auswurfeinheit();

    // Auswurfeinheit in die vordere Stellung fahren
    // hierdurch erfolgt i.d.R. Auswurf des Bonbons
    void fahreVor();

    // Auswurfeinheit in die hintere Stellung fahren
    void fahreZurueck();
};

#endif // AUSWURFEINHEIT_H
