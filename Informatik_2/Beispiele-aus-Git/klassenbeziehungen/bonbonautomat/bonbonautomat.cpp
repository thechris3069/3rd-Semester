/*
 * Definition von Methoden der Klasse Bonbonautomat
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "bonbonautomat.h"

Bonbonautomat::Bonbonautomat()
    : m_ledRot("rot"), m_ledGruen("gruen")
{
    m_lcd.zeigeText("Willkommen!");
}

void Bonbonautomat::ausfuehren()
{
    while(1)
    {
        if(m_fuellstand.getFuellstand() < 3)
        {
            m_lcd.zeigeText("Fuellstand niedrig!");
            m_ledRot.schalteAn();
            m_ledGruen.schalteAus();
        }
        else
        {
            m_lcd.zeigeText("Fuellstand ok!");
            m_ledRot.schalteAus();
            m_ledGruen.schalteAn();
        }
        m_lcd.zeigeText("Geld einwerfen!");
        if(m_taster.istGedrueckt())
        {
            m_lcd.zeigeText("Bonbon kommt...");
            m_auswurf.fahreVor();
            m_auswurf.fahreZurueck();
        }
    }
}

