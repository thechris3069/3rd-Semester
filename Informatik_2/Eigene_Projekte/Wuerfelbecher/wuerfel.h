#ifndef WUERFEL_H
#define WUERFEL_H
#include <iostream>
#include <cstdlib>
#include <time.h>

class Wuerfel
{
public:
//    Wuerfel();

    Wuerfel(std::string farbe = "rot", int groessteZahl = 6);
    void anzeigen();
    void wuerfeln();

private:
     std::string m_farbe;
     int m_groessteZahl;
     int aktZahl;

};

#endif // WUERFEL_H
