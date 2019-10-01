/*
 * Klasse zur Repraesentation eines Rechtecks in einer Ebene
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef RECHTECK
#define RECHTECK

#include "flaeche.h"

#include <iostream>

// Bezugspunkt des Rechtecks ist ein Eckpunkt
class Rechteck : public Flaeche
{
private:
    Punkt m_diagonalerPunkt; // zweiter Punkt diagonal entgegengesetzt dem Bezugspunkt
public:
    Rechteck(const Punkt &p1, const Punkt &p2)
        : Flaeche(p1), // Aufruf Basisklassenkonstruktor
          m_diagonalerPunkt(p2)
    {}

    double getFlaecheninhalt()
    {
        return fabs(m_bezugspunkt.getX() - m_diagonalerPunkt.getX())*
                fabs(m_bezugspunkt.getY() - m_diagonalerPunkt.getY());
    }

    void ausgeben()
    {
        std::cout << "Rechteck zwischen ";
        m_bezugspunkt.ausgeben();
        std::cout << " und ";
        m_diagonalerPunkt.ausgeben();
        std::cout << std::endl;
    }
};

#endif // RECHTECK

