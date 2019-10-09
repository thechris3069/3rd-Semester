#include <iostream>
#include <cstdlib>
#include <ctime>

#include "wuerfel.h"

using namespace std;

int main()
{
    srand(time(0));
    string var = "rot";
    Wuerfel w1(var, 10);
    w1.anzeigen();
    w1.wuerfeln();
    w1.anzeigen();
    Wuerfel w2("gelb");
//    Wuerfel w4(500); Findet keinen passenden Konstruktor
    Wuerfel w3; // allgemeiner Konstruktor wird aufgerufen
    w3.anzeigen();
    w2.anzeigen();
    w3.wuerfeln();
    w3.anzeigen();


    cout << "Hello World!" << endl;
    return 0;
}
