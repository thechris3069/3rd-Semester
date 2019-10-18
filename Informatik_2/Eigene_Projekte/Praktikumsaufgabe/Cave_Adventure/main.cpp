#include <iostream>

#include "player.h"

#define SPIELFELD 200

using namespace std;

int main()
{


    cout << "Wilkommen zu Cave Advenure" << endl;
    cout << "Sie sind in einer Höhle und müssen einen Ausweg finden. \n Steuerungsknöpfe: WASD " <<endl;
    cout <<  "Auf dem Weg begegnen ihnen Monster und Händer, Gold und Fallen, viel Glück" << endl;

    Player player1(SPIELFELD);
    player1.ausgabe();


    cout << "Hello World!" << endl;
    return 0;
}
