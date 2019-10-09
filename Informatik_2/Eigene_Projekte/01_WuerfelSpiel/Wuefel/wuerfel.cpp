#include "wuerfel.h"

using namespace std;


Wuerfel::Wuerfel(std::string farbe,unsigned int max)
    :w_Farbe(farbe), maxZahl(max)
{
    if(maxZahl < 1)
        maxZahl = 1;
    wuerfeln();
}

void Wuerfel::wuerfeln()
{
    aktZahl = rand() % maxZahl +1;
}

unsigned int Wuerfel::getZahl(int *)
{
    return aktZahl;
}

void Wuerfel::anzeigen()
{
    cout << "Wuerfelfarbe: " << w_Farbe << " MaxZahl: " << maxZahl << " Zufallzahl: " << aktZahl << endl;

}

Wuerfel::~Wuerfel()
{
    cout << "Destruktor aufgerufen" << endl;
}

