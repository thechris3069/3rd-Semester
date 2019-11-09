#include "wuerfel.h"

Wuerfel::Wuerfel(std::string farbe, int groessteZahl)
    :m_farbe(farbe), m_groessteZahl(groessteZahl)
{
std::cout << "Konstruktor von Wuerfel" << std::endl;
}

void Wuerfel::wuerfeln()
{
Wuerfel::aktZahl = (rand() & m_groessteZahl-1)+1;
}

void Wuerfel::anzeigen()
{
std::cout << "Es wurde " << aktZahl << "gewuerfelt" <<std::endl;
}
