/*
 * Graustufenbilder koennen z.B. im PGM (Portable Graymap Format) abgespeichert werden.
 * Falls die Daten textbasiert abgelegt werden, ist eine Datei wie folgt aufgebaut:
 *
 * - Magischer Wert "P2" (Portable Graymap ASCII)
 * - Leerraum (Leerzeichen, Tabulator, \n oder \r)
 * - Breite des Bildes (dezimal in ASCII)
 * - Leerraum
 * - Hoehe des Bildes (dezimal in ASCII)
 * - Leerraum
 * - Maximalwert fuer die Helligkeit (dezimal in ASCII, typ: 255 oder 65535)
 * - Leerraum
 * - Bildpunkte (getrennt durch Leerraeume)
 *
 * Kommentarzeilen im Dateikopf (vor den Bildpunkten) muessen mit # am Beginn der Zeile gekennzeichnet werden.
 *
 * Quellen:
 * http://netpbm.sourceforge.net/doc/pgm.html, letzter Zugriff: 13.12.2017
 * https://de.wikipedia.org/wiki/Portable_Graymap, letzter Zugriff: 13.12.2017
 *
 * Beispiele:
 * grauverlauf.pgm: Eine Datei mit einem Grauverlauf wuerde beispielsweise wie folgt aussehen:
 * P2
 * 10
 * 13
 * 255
 * 0 0 0 0 0 0 0 0 0 0
 * 20 20 20 20 20 20 20 20 20 20
 * 40 40 40 40 40 40 40 40 40 40
 * 60 60 60 60 60 60 60 60 60 60
 * 80 80 80 80 80 80 80 80 80 80
 * 100 100 100 100 100 100 100 100 100 100
 * 120 120 120 120 120 120 120 120 120 120
 * 140 140 140 140 140 140 140 140 140 140
 * 160 160 160 160 160 160 160 160 160 160
 * 180 180 180 180 180 180 180 180 180 180
 * 200 200 200 200 200 200 200 200 200 200
 * 220 220 220 220 220 220 220 220 220 220
 * 240 240 240 240 240 240 240 240 240 240
 *
 * magnolie.pgm: Diese Datei enthaehlt eine Magnolie im PGM-Format.
 *
 * Die Klasse PgmBild enthaelt Methoden zum Auslesen von PGM-Bildern aus den entsprechenden Dateien mit einem maximalen Graustufenwert von 255.
 * Abhaengig von der Hoehe und Breite des Bildes wird Speicher reserviert.
 * Zusaetzlich sind Methoden vorhanden, um die Helligkeit des Bildes anzupassen (Graustufenwert erhoehen bzw. verringern) und das Bild
 * anschliessend wieder in einer PGM-Datei abzuspeichern.
 *
 * Vorlesungsbeispiel Informatik 2, WS 2017/18
 * Claudia Meitinger
 * 13.12.2017
 */

#ifndef PGMBILD_H
#define PGMBILD_H

#include <cstdint> // uint8_t
#include <string>

class PgmBild
{
private:
    unsigned int       m_breite        = 0;       // Breite des PGM-Bildes in Pixeln
    unsigned int       m_hoehe         = 0;       // Hoehe des PGM-Bildes in Pixeln
    unsigned int       m_maxGraustufen = 255;     // Diese Klasse kann nur mit Bildern umgehen, die einen max. Graustufenwert von 255 haben (-> uint8_t Bilddaten) (sollte const sein; dann ist Demonstration der Std-Zuweisung nicht moeglich...)
    uint8_t *          m_pBilddaten    = nullptr; // Startadresse des Feldes, in dem Bilddaten abgelegt werden.
public:
    // Standardkonstruktor
    // -> leeres Bild
    PgmBild();

    // Kopierkonstruktur
    PgmBild(const PgmBild &b);

    // Zuweisungsoperator
    PgmBild &operator=(const PgmBild &b);

    // Destruktor
    // -> Freigabe des fuer die Bilddaten reservierten Speicherplatzes
    ~PgmBild();

    // Existierende Bildinhalte verwerfen, d.h. Speicher freigeben und Werte fuer Hoehe und Breite zuruecksetzen
    void clear();

    // Bilddaten aus Datei einlesen
    // -> wirft im Fehlerfall eine Ausnahme
    void leseAusDatei (std::string dateiname);

    // Helligkeit des Bildes veraendern
    // -> zu jedem Bildpixel wird "wert" addiert. Ist wert positiv, wird das Bild heller, sonst dunkler.
    //    Wenn durch die Addition der Wertebereich 0 .. m_maxGraustufen verlassen wuerde, wird bei 0 bzw. m_maxGraustufen abgeschnitten,
    //    z.B. fuer m_maxGraustufen = 255 ergibt 240 + 100 den Wert 255, 40 - 100 den Wert 0.
    void aendereHelligkeit (int wert);

    // Bild als Datei abspeichern
    // -> gibt im Fehlerfall eine Meldung auf dem Bildschirm aus und speichert das Bild nicht ab
    void speichereInDatei (std::string dateiname) const;
};

#endif // PGMBILD_H
