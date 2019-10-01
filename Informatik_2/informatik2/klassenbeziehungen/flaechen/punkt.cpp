/*
 * Definition von Methoden der Klasse Punkt
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "punkt.h"

#include <iostream>
using namespace std;

Punkt::Punkt(double x, double y, string bezeichnung)
    : m_x(x), m_y(y), m_bezeichnung(bezeichnung)
{
}

void Punkt::ausgeben()
{
    std::cout << m_bezeichnung << " (" << m_x << ", " << m_y << ")";
}

