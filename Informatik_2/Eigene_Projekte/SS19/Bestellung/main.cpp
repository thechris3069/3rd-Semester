#include <iostream>
#include "bestellung.h"

using namespace std;

int main()
{
    Bestellung meineBestellung(5, 60);
    Bestellung kopie(meineBestellung);
    int tag = meineBestellung.getTag();

            cout << "Original" << endl;
    for(int i = 0; i < meineBestellung.anzahlpunkte; ++i)
    {

        cout <<"X: " << meineBestellung.m_punkt[i].m_x<< endl;
        cout <<"Y: " << meineBestellung.m_punkt[i].m_y << endl;
}
    cout << "Kopie" <<endl;
    for(int i = 0; i < kopie.anzahlpunkte; ++i)
    {
        cout <<"X: " << kopie.m_punkt[i].m_x<< endl;
        cout <<"Y: " << kopie.m_punkt[i].m_y << endl;
}


    return 0;
}
