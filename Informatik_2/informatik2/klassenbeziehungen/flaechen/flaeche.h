/*
 * Klasse zur Repraesentation einer Flaeche mit einem Bezugspunkt in einer Ebene
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef FLAECHE_H
#define FLAECHE_H

#include "punkt.h"

class Flaeche
{
protected: // Zugriff auf Bezugspunkt wird aus abgeleiteten Klassen ermoeglicht
    Punkt m_bezugspunkt;
public:
    Flaeche(const Punkt &p)
        : m_bezugspunkt(p)
    {}
};

#endif // FLAECHE_H
