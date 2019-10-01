/*
 * Klasse zur Ansteuerung eines LCD Displays
 *
 * in der aktuellen Ausfuehrung wird diese ueber eine Bildschirmausgabe simuliert
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef LCDDISPLAY_H
#define LCDDISPLAY_H

#include <string>

class LcdDisplay
{
public:
    LcdDisplay();

    // zeigt den uebergebenen text auf dem Display (bzw. Bildschirm) an
    // zuvor angezeigter Text wird geloescht/ueberschrieben
    void zeigeText(std::string text);
};

#endif // LCDDISPLAY_H
