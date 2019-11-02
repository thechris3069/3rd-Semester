#include <iostream>
#include "caveadventure.h"
#include "spielfeld.h"
#include "world.h"
#include "player.h"

#define SPIELFELD 10

using namespace std;

int main()
{
    cout << "Wilkommen zu Cave Advenure" << endl;
    cout << "Sie sind in einer Höhle und müssen einen Ausweg finden. \n Steuerungsknöpfe: WASD " <<endl;
    cout <<  "Auf dem Weg begegnen ihnen Monster und Händer, Gold und Fallen, viel Glück" << endl;
    CaveAdventure spielumgebung;


    return 0;

}
