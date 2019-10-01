/*
 * Hauptprogramm des Spiels 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 1.4.2019
 *
 * 16.5.2019 - CM - optionale Angabe eines Pfades, in dem nach bekannten Hoehlen gesucht wird statt zufaellig eine Hoehle zu erzeugen
 */

#include <cstdlib>
#include <ctime>
using namespace std;

#include "caveadventure.h"

int main(int argc, char *argv[])
{
    string pfadZuHoehlendateien("");

    if (argc > 1) {
        string value(argv[1]);
        if (value == "--help") {
            cout << "Aufruf ohne Parameter erzeugt zufaellige Hoehle.\n";
            cout << "Wird als Parameter ein Pfad angegeben, so wird in diesem Pfad\n";
            cout << "nach vordefinierten Hoehlen gesucht, z. B.\n";
            cout << argv[0] << " " << "./caves" << endl;
        } else {
            pfadZuHoehlendateien = argv[1];
        }
    }

    srand(time(0));

    try {
        CaveAdventure ca(pfadZuHoehlendateien);

        while (!ca.isGameFinished())
            ca.getAndProcessUserInput();
    } catch (...) {
        cerr << "Eine Exception verhindert das Spiel..." << endl;
    }

    return 0;
}

