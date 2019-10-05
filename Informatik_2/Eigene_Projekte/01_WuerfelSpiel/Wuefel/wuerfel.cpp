#include "wuerfel.h"

//#include <iostream>   //INCLUDES IN DIE HEADER, ODER IN DIE CPP DATEI

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

//unsigned int Wuerfel::getZahl()
//{
//    return aktZahl;
//}

void Wuerfel::anzeigen()
{
    cout << "Wuerfelfarbe: " << w_Farbe << " MaxZahl: " << maxZahl << " Zufallzahl: " << aktZahl << endl;

}

Wuerfel::~Wuerfel()
{
    cout << "Destruktor aufgerufen" << endl;
}

