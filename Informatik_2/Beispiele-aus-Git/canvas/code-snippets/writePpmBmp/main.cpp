
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
#include <fstream>
#include <cstdlib>

#include "background.h"

using namespace std;

/* Funktion, die RGB-Daten eines Bildes der Breite b und Hoehe h, die
 * in einem eindimensionalen Feld bilddaten der Groesse b*h*3 hinterlegt sind (siehe oben),
 * im BMP-Format als Datei test.bmp abspeichert
 */
int saveAsBmp(uint8_t bilddaten[], int b, int h)
{
    // Formatbeschreibung siehe https://en.wikipedia.org/wiki/BMP_file_format
    // letzter Zugriff: 11.9.2019

    ofstream f("test.bmp", ios::binary);

    // BMP Header
    f.put(0x42); f.put(0x4D); // ID field
    uint32_t size = 54 + b * h * 3 + h * ((4 - (b * 3) % 4) % 4); // BMP file size: 54 Bytes Header + 3 Bytes pro Pixel
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    for (unsigned int i = 0; i < 4; ++i) // unused
        f.put(0x00);
    uint32_t offset = 54;  // offset of pixel array = header size = 54 Bytes
    for (unsigned int i = 0; i < 4; ++i)
        f.put((offset >> i*8) & 0xFF);

    // DIB Header
    size = 40; // DIB header size
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    size = b; // width of image
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    size = -h; // height of image (negative for top to bottom)
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    f.put(0x01); f.put(0x00); // 1 color plane
    f.put(0x18); f.put(0x00); // 24 bits per pixel
    for (unsigned int i = 0; i < 4; ++i) // no pixel array compression
        f.put(0x00);
    f.put(0x10); f.put(0x00); f.put(0x00); f.put(0x00); // 16 Bits per pixel (incl. paddding)
    f.put(0x13); f.put(0x0b); f.put(0x00); f.put(0x00); // print resolution hor
    f.put(0x13); f.put(0x0b); f.put(0x00); f.put(0x00); // print resolution ver
    for (unsigned int i = 0; i < 4; ++i) // no colour palette
        f.put(0x00);
    for (unsigned int i = 0; i < 4; ++i) // no important colours
        f.put(0x00);

    // image data
    for (unsigned int row = 0; row < h; ++row) {
        for (unsigned int col = 0; col < b; ++col) {
            f.put(bilddaten[(row*b + col)*3 + 2]);
            f.put(bilddaten[(row*b + col)*3 + 1]);
            f.put(bilddaten[(row*b + col)*3 + 0]);
        }
        // padding (jede Zeile Vielfaches von 4 Bytes)
        for (unsigned int i = 0; i < (4 - (b * 3) % 4) % 4; ++i)
            f.put(0x00);
    }
    return 0;
}

/* Funktion, die RGB-Daten eines Bildes der Breite b und Hoehe h, die
 * in einem eindimensionalen Feld bilddaten der Groesse b*h*3 hinterlegt sind (siehe oben),
 * im PPM-Format als Datei test.ppm abspeichert
 */
int saveAsPpm(uint8_t bilddaten[], int b, int h)
{
    // Formatbeschreibung siehe https://en.wikipedia.org/wiki/Portable_Graymap_File_Format
    // letzter Zugriff: 11.9.2019

    ofstream f("test.ppm");
    if (!f) {
        cerr << "Datei konnte nicht geoeffnet werden!" << endl;
        return -1;
    }

    f << "P3" << endl; // magic number fuer PPM im ASCII Format
    f << b << " " << h << endl; // Breite und Hoehe in Anzahl Pixeln
    f << "255" << endl; // maximaler Wert pro R, G, B-Wert

    for (unsigned int row = 0; row < h; ++row) {
        for (unsigned int col = 0; col < b; ++col) {
            f << static_cast<unsigned int>(bilddaten[(row*b + col)*3 + 0]);
            f << " ";
            f << static_cast<unsigned int>(bilddaten[(row*b + col)*3 + 1]);
            f << " ";
            f << static_cast<unsigned int>(bilddaten[(row*b + col)*3 + 2]);
            f << " ";
        }
        f << endl;
    }
    return 0;
}

int main()
{
    Background pictureOne("yellow");
    saveAsBmp(pictureOne.getarray(), pictureOne.getSize_x(), pictureOne.getSize_y());
    saveAsPpm(pictureOne.getarray(), pictureOne.getSize_x(), pictureOne.getSize_y());

    std::cout << "Hello World" <<std::endl;
    return 0;
}

//Wann ist der this-> Pointer nötig, ich kann ja in der Klasse immer auf den this Zeiger verzichten? Nur bei Scope, ... mehrfacher Belegung von Variablen?
// Wie deklariere ich die Array Länge, wenn ich die Größe des Hintergrunds übergeben übergeben möchte?
//Wenn ich nichts übergebe, bekomme ich einen Fehler, verstehe aber nicht wieso, ich habe ja einen Standard Konstruktor, sowie einen spezifischen Konstruktor, wieso wird kein Objekt erstellt?
//Wo kommt ein namespace hin, in die Header, oder in die .cpp file
// Inline Programmierung im Header? - also Definition in einer Header File?
