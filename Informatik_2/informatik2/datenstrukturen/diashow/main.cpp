/**
  * Einfach vorwaerts verkettete Liste aus Fotos
  *
  * Vorlesungsbeispiel Informatik 2
  * Claudia Meitinger
  * 17.11.2017
  */

#include <iostream>
using namespace std;

#include "diashow.h"

int main()
{
    /* Beispiel: Neuen Knoten anlegen
    Foto *pF = new Foto ( "Fortezza von Rethymno", "Claudia", "Kreta/013_R41.JPG");
    pF->show();
    delete pF;
    */

    /* Beispiel: Fotos zu einer Diashow hinzufuegen und Diashow anzeigen */
    Diashow urlaub;

    Foto *pF = new Foto ( "Fortezza von Rethymno", "Claudia", "Kreta/013_R41.JPG");
    urlaub.pushBack(pF);
    pF = new Foto ( "Samaria Schlucht", "Claudia", "Kreta/014_L27.JPG");
    urlaub.pushBack(pF);
    pF = new Foto ( "Samaria Schlucht", "Claudia", "Kreta/014_L35.JPG" );
    urlaub.pushBack(pF);
    pF = new Foto ( "Sonnenaufgang", "Claudia", "Kreta/015_L43.JPG" );
    urlaub.pushBack(pF);
    pF = new Foto ( "Palast von Knossos", "Claudia", "Kreta/015_R39.JPG" );
    urlaub.pushBack(pF);

    urlaub.anzeigen();


    /* Beispiel: Foto einfuegen und Fotos entnehmen */
    pF = new Foto ( "Kaputter Schuh", "Tom", "Kreta/tom14.JPG" );
    urlaub.insert(pF, 2);
    urlaub.remove(4);
    urlaub.anzeigen();

    /* Beispiel: Diashow abspeichern */
    urlaub.speichern("test.diashow");


    /* Beispiel: Abgespeicherte Diashow einlesen und anzeigen */
    urlaub.einlesen("test.diashow");
    urlaub.anzeigen();

    return 0;
}

