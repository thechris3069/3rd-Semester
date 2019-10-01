/*
 * Fuer ein Zeichenprogramm sollen verschiedene Grafikobjekte
 * (Rechtecke, Quadrate, Kreise, Ellipsen,...) modelliert werden.
 * Hierbei wird davon ausgegangen, dass jede zweidimensionale geometrische
 * Flaeche einen Bezugspunkt hat.
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#include "ellipse.h"
#include "kreis.h"
#include "rechteck.h"

#include <iostream>
using namespace std;

int main()
{
    Ellipse e1(Punkt(4, 5, "E"), 4, 5);
    e1.ausgeben();
    cout << "Flaeche: " << e1.getFlaecheninhalt() << endl << endl;

    Kreis k1(Punkt(0, 0, "K"), 3);
    k1.ausgeben();
    cout << "Flaeche: " << k1.getFlaecheninhalt() << endl << endl;

    Rechteck r1(Punkt(0, 0, "P1"), Punkt(5, 7, "P2"));
    r1.ausgeben();
    cout << "Flaeche: " << r1.getFlaecheninhalt() << endl;

    return 0;
}

