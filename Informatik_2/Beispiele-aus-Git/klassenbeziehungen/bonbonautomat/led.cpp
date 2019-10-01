/*
 * Definition von Methoden der Klasse Led
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "led.h"

#include <iostream>
using namespace std;


Led::Led(string farbe)
    : m_farbe(farbe)
{
    schalteAus();
}

void Led::ausgeben()
{
    cout << "LED " << m_farbe << " ist ";
    if (m_an)
        cout << "an";
    else
        cout << "aus";
    cout << "!" << endl;
}

void Led::schalteAn()
{
    m_an = true;
    ausgeben();
}

void Led::schalteAus()
{
    m_an = false;
    ausgeben();
}
