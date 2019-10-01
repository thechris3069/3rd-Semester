/*
 * Klasse zur Repraesentation eines Kreises in einer Ebene
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef KREIS_H
#define KREIS_H

#include "ellipse.h"

#include <cmath>

class Kreis : public Ellipse
{
public:
    // Kreis um Mittelpunkt p mit Radius r
    Kreis(const Punkt &p, double r)
        : Ellipse(p, r, r) // Aufruf Basisklassenkonstruktor
    {}

    void ausgeben()
    {
        std::cout << "Kreis um Mittelpunkt ";
        m_bezugspunkt.ausgeben();
        std::cout << " mit Radius " << m_a << std::endl;
    }
};

#endif // KREIS_H
