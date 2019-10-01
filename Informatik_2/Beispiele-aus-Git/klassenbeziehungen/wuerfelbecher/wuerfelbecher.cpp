/*
 * Definition von Methoden der Klasse Wuerfelbecher
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "wuerfelbecher.h"

Wuerfelbecher::Wuerfelbecher()
{
    m_AnzahlWuerfel = 0;
    for ( unsigned int i = 0; i < ANZAHL_WUERFEL; ++i )
    {
        m_Wuerfel[i] = nullptr;
    }
}

void Wuerfelbecher::einwerfen(Wuerfel *pW)
{
    // Nullptr wird nicht weiter beruecksichtigt
    if ( !pW )
        return;
    // Solange der Wuerfelbecher noch nicht voll ist,
    // kann ein weiterer Wuerfel hinzugefuegt werden
    if ( m_AnzahlWuerfel < ANZAHL_WUERFEL )
    {
        m_Wuerfel[m_AnzahlWuerfel++] = pW;
    }
}

void Wuerfelbecher::auswerfen()
{
    for ( unsigned int i = 0; i < m_AnzahlWuerfel; ++i )
    {
        m_Wuerfel[i]->wuerfeln();
    }
    m_AnzahlWuerfel = 0;
}
