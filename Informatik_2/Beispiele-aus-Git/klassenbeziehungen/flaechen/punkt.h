/*
 * Klasse zur Repraesentation eines Punktes in einer Ebene
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef PUNKT_H
#define PUNKT_H

#include <string>

class Punkt
{
private:
    double      m_x;
    double      m_y;
    std::string m_bezeichnung;
public:
    Punkt(double x, double y, std::string bezeichnung = "P");

    double getX() { return m_x; }
    double getY() { return m_y; }

    void ausgeben();
};

#endif // PUNKT_H
