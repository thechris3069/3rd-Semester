/*
 * Die Klasse PgmBild enthaelt Methoden zum Auslesen von PGM-Bildern aus den entsprechenden Dateien mit einem maximalen Graustufenwert von 255.
 * Abhaengig von der Hoehe und Breite des Bildes wird Speicher reserviert.
 * Zusaetzlich sind Methoden vorhanden, um die Helligkeit des Bildes anzupassen (Graustufenwert erhoehen bzw. verringern) und das Bild
 * anschliessend wieder in einer PGM-Datei abzuspeichern.
 *
 * - Sehen Sie sich die beiden Beispielbilder grauverlauf.pgm und magnolie.pgm im Texteditor und im Bildbetrachter an.
 * - Legen Sie fuer beide Bilder je ein Objekt der Klasse PgmBild an (magnolie1, grau1), erhoehen bzw. verringern Sie die Helligkeit und speichern Sie das Bild unter einem neuen Namen ab.
 * - Legen Sie zwei zusaetzliche Objekte der Klasse PgmBild an (magnolie2, grau2).
 *   Eines soll durch Anwendung des Kopierkonstruktors aus dem bereits existierenden Objekt erzeugt werden,
 *   eines durch Anwendung des Zuweisungsoperators.
 *   Veraendern Sie danach (!) in den urspruenglichen Objekten (magnolie1, grau1) die Helligkeit und speichern
 *   Sie anschliessend alle 4 Objekte in neuen PGM-Dateien ab - was erwarten Sie, was beobachten Sie?
 * - Implementieren Sie einen Kopierkonstruktor und Zuweisungsoperator so, dass eine tiefe Kopie der
 *   Objekte erzeugt wird!
 *
 * Vorlesungsbeispiel Informatik 2, WS 2017/18
 * Claudia Meitinger
 * 13.12.2017
 */

// ----- INCLUDES -----
#include "pgmbild.h"

#include <iostream>
using namespace std;

// ----- HAUPTPROGRAMM-----
int main()
{
    PgmBild magnolie1, grau1;

    try {
        // Bilddaten einlesen
        grau1.leseAusDatei("grauverlauf.pgm");
        magnolie1.leseAusDatei("magnolie.pgm");

        // Bild kopieren
        PgmBild grau2(grau1);

        // Bild zuweisen
        PgmBild magnolie2;
        magnolie2 = magnolie1;

        // Helligkeit aendern und als neue Bilder abspeichern
        grau1.aendereHelligkeit(-100);
        grau1.speichereInDatei("grauverlaufDunkler.pgm");

        magnolie1.aendereHelligkeit(100);
        magnolie1.speichereInDatei("magnolieHeller.pgm");

        grau2.speichereInDatei("grauverlauf2.pgm");
        magnolie2.speichereInDatei("magnolie2.pgm");
    }
    catch(const char *msg) {
        cerr << msg << endl;
    }

    return 0;
}
