/*
 * Klasse zur Ansteuerung einer LED
 *
 * in der aktuellen Ausfuehrung wird diese ueber eine Bildschirmausgabe simuliert
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef LED_H
#define LED_H

#include <string>

class Led
{
private:
    std::string m_farbe;
    bool        m_an;    // true: LED leuchtet, false: LED leuchtet nicht
    void ausgeben();     // Infos zur LED auf dem Bildschirm ausgeben
public:
    Led(std::string farbe);
    void schalteAn();    // LED anschalten
    void schalteAus();   // LED ausschalten
};

#endif // LED_H
