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
//    Wuerfel w3(500);
    Wuerfel w3;
    w3.anzeigen();
    w2.anzeigen();
//    w2.wuerfeln();
//    w2.anzeigen();


    cout << "Hello World!" << endl;
    return 0;
}
