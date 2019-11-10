
/*
 * Codebeispiel zum Abspeichern von Bildern aus RGB-Daten als BMP-/PPM-Datei.
 *
 * Ein Bild besteht aus Pixeln, die in Zeilen und Spalten angeordnet sind.
 * Jedes Pixel hat einen Rot-, Grün- und Blau-Wert zwischen 0 und 255. Der Ursprung
 * des Bildes befindet sich links oben:
 *  (0,0) ---------- (0, breite-1)
 *    |                  |
 *    |       (z,s)      |
 *    |                  |
 *   (hoehe-1,0) --- (hoehe-1, breite-1)
 * Diese Pixel werden in einem eindimensionalen Feld zeilenweise abgelegt und zwar in
 * der Reihenfolge
 * R[0,0] G[0,0] B[0,0] R[0,1] G[0,1] B[0,1] R[0,2] G[0,2] B[0,2]...
 * R[1,0] G[1,0] B[1,0] R[1,1] G[1,1] B[1,1] R[1,2] G[1,2] B[1,2]...
 * ...
 * R[hoehe-1,0] G[hoehe-1,0] B[hoehe-1,0] R[hoehe-1,1] G[hoehe-1,1] B[hoehe-1,1] R[hoehe-1,2] G[hoehe-1,2] B[hoehe-1,2]...
 * ... R[hoehe-1,breite-2] G[hoehe-1,breite-2] B[hoehe-1,breite-2] R[hoehe-1,breite-1] G[hoehe-1,breite-1] B[hoehe-1,breite-1]
 *
 * Die benoetigte Feldgroesse betraegt daher breite*hoehe*3 Bytes, da pro R,G,B-Wert 1 Byte benoetigt wird.
 * Der Zugriff auf die Farbwerte eines Pixels in Zeile z und Spalte s kann wie folgt erfolgen:
 * R-Wert: feld[(z*breite + s)*3 + 0]
 * G-Wert: feld[(z*breite + s)*3 + 1]
 * B-Wert: feld[(z*breite + s)*3 + 2]
 */

#include <iostream>


#include "background.h"

using namespace std;

/* Funktion, die RGB-Daten eines Bildes der Breite b und Hoehe h, die
 * in einem eindimensionalen Feld bilddaten der Groesse b*h*3 hinterlegt sind (siehe oben),
 * im BMP-Format als Datei test.bmp abspeichert
 */


int main()
{
    Background pictureOne("yellow");
    pictureOne.saveAsBmp(pictureOne.getarray(), pictureOne.getSize_x(), pictureOne.getSize_y());
    pictureOne.saveAsPpm(pictureOne.getarray(), pictureOne.getSize_x(), pictureOne.getSize_y());

    std::cout << "Hello World" <<std::endl;
    return 0;
}

//Wann ist der this-> Pointer nötig, ich kann ja in der Klasse immer auf den this Zeiger verzichten? Nur bei Scope, ... mehrfacher Belegung von Variablen?
// Wie deklariere ich die Array Länge, wenn ich die Größe des Hintergrunds übergeben übergeben möchte?
//Wenn ich nichts übergebe, bekomme ich einen Fehler, verstehe aber nicht wieso, ich habe ja einen Standard Konstruktor, sowie einen spezifischen Konstruktor, wieso wird kein Objekt erstellt?
//Wo kommt ein namespace hin, in die Header, oder in die .cpp file
// Inline Programmierung im Header? - also Definition in einer Header File?
