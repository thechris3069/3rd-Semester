/*
 * Definition von Methoden der Klasse LcdDisplay
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "lcddisplay.h"

#include <iostream>
using namespace std;

LcdDisplay::LcdDisplay()
{
}

void LcdDisplay::zeigeText(string text)
{
    cout << "LCD: " << text << endl;
}


