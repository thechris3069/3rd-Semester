/*
 * Klasse zur Repraesentation einer Ellipse in einer Ebene
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "flaeche.h"

#include <cmath>
#include <iostream>

// Bezugspunkt der Ellipse ist der Mittelpunkt
class Ellipse : public Flaeche
{
protected:
    double m_a; // grosse Halbachse
    double m_b; // kleine Halbachse
public:
    Ellipse(const Punkt &p, double a, double b)
        : Flaeche(p), // Aufruf Basisklassenkonstruktor
          m_a(a),
          m_b(b)
    {}

    double getFlaecheninhalt()
    {
        return m_a * m_b * M_PI;
    }

    void ausgeben()
    {
        std::cout << "Ellipse um Mittelpunkt ";
        m_bezugspunkt.ausgeben();
        std::cout << " mit Halbachsen " << m_a << " und " << m_b << std::endl;
    }
};

#endif // ELLIPSE_H
