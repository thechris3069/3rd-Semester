/*
 * Definition von Methoden der Klasse PgmBild
 *
 *  Vorlesungsbeispiel Informatik 2, WS 2017/18
 * Claudia Meitinger
 * 13.12.2017
 */

#include "pgmbild.h"
#include <iostream>
#include <fstream>
using namespace std;

// -------------------------------------------------
PgmBild::PgmBild()
{
    // keine weiteren Aktionen notwendig - Initialisierung der Datenelemente erfolgt direkt dort.
}

// -------------------------------------------------
PgmBild::PgmBild(const PgmBild &b)
    : m_maxGraustufen(b.m_maxGraustufen)
{
    // normale Datenelemente koennen "einfach" kopiert werden
    m_breite = b.m_breite;
    m_hoehe = b.m_hoehe;

    // von den Bilddaten muss eine tiefe Kopie angefertigt werden
    try {
        m_pBilddaten = new uint8_t[m_breite*m_hoehe];
        for (unsigned int i = 0; i < m_breite*m_hoehe; ++i)
            m_pBilddaten[i] = b.m_pBilddaten[i];
    }
    catch(const exception &e)
    {
        cerr << "Fehler - Kein Speicher fuer Kopie der Bilddaten vorhanden!" << endl;
        clear();
    }
}

// -------------------------------------------------
PgmBild &PgmBild::operator=(const PgmBild &b)
{
    if (&b != this) // Selbstzuweisung verhindern
    {
        // Vorhandene Bilddaten loeschen
        clear();

        // Neue Bilddaten kopieren
        // normale Datenelemente koennen "einfach" kopiert werden
        m_breite = b.m_breite;
        m_hoehe = b.m_hoehe;

        // von den Bilddaten muss eine tiefe Kopie angefertigt werden
        try {
            m_pBilddaten = new uint8_t[m_breite*m_hoehe];
            for (unsigned int i = 0; i < m_breite*m_hoehe; ++i)
                m_pBilddaten[i] = b.m_pBilddaten[i];
        }
        catch(const exception &e)
        {
            cerr << "Fehler - Kein Speicher fuer Kopie der Bilddaten vorhanden!" << endl;
            clear();
        }
    }

    return *this; // Kettenzuweisung ermoeglichen
}

// -------------------------------------------------
PgmBild::~PgmBild()
{
    clear();
}

// -------------------------------------------------
void PgmBild::clear()
{
    m_breite = 0;
    m_hoehe = 0;
    delete[] m_pBilddaten;
    m_pBilddaten = nullptr;
}

// -------------------------------------------------
void PgmBild::leseAusDatei(string dateiname)
{
    ifstream pgmFile;
    string line; // zeilenweises Einlesen der Datei ermoeglichen
    bool magicNumberGefunden = false;
    unsigned int maxGrauwert = 0; // 0: unbekannt, anderer Wert: aus Datei eingelesen

    // Alte Bildinhalte loeschen
    clear();

    // Datei zum Lesen im Textmodus oeffnen
    pgmFile.open(dateiname);

    // Fehler: Datei konnte nicht geoeffnet werden
    if (!pgmFile)
        throw "Fehler! Datei konnte nicht geoeffnet werden!";

    // Daten aus Dateikopf auslesen
    while(!pgmFile.eof()) {
        // Remove delimiters
        if ( pgmFile.peek() == ' ' || pgmFile.peek() == '\n' || pgmFile.peek() == '\t' || pgmFile.peek() == '\n' || pgmFile.peek() == '\r' ) {
            pgmFile.get();
            pgmFile.clear();
        }

        // Falls Zeile mit einem Kommentarzeichen beginnt...
        if ( pgmFile.peek() == '#' ) {
            // ... wird Zeileninhalt gelesen und vergessen.
            getline(pgmFile, line);
        }

        // Magic Number "P2" gefunden?
        if (!magicNumberGefunden) {
            pgmFile >> line;
            if (line == "P2")
                magicNumberGefunden = true;
            else
                throw "Fehler! Es koennen nur PGM-Bilder mit Magic Number P2 verarbeitet werden!";
        }

        // Nach der Magic Number kommt die Breite des Bildes, dann die Hoehe des Bildes, dann der
        // maximale Graustufenwert
        // Der naechste Wert wird jeweils eingelesen, wenn der vorherige zur Verfuegung steht
        // Dies wird durch einen Wert > 0 gekennzeichnet
        else if (magicNumberGefunden && m_breite == 0)
            pgmFile >> m_breite;
        else if (m_breite > 0 && m_hoehe == 0)
            pgmFile >> m_hoehe;
        else if (m_hoehe > 0 && maxGrauwert == 0 ) {
            pgmFile >> maxGrauwert;
            if (maxGrauwert != m_maxGraustufen) {
                throw "Fehler! Ungueltiger Wert fuer max. Graustufe!";
            }
        }
        else
            break;
    }

    // Nun stehen alle Bildinformationen zur Verfuegung => Speicher fuer Bilddaten reservieren
    try {
        m_pBilddaten = new uint8_t[m_breite*m_hoehe];
    }
    catch (const exception& e)
    {
        clear();
        throw "Fehler! Speicher fuer Bilddaten konnte nicht reserviert werden!";
    }

    // Bilddaten einlesen und zeilenweise in m_pBilddaten ablegen
    unsigned int idx = 0;
    unsigned int value;
    while(idx < m_breite*m_hoehe && !pgmFile.eof())
    {
        pgmFile >> value;
        m_pBilddaten[idx++] = static_cast<uint8_t>(value);
    }

    if ( idx < m_breite*m_hoehe )
        throw "Fehler! Nicht genug Bilddaten im Bild vorhanden!";

    // Datei schliessen (optional, da Destruktor ohnehin aufgerufen wird)
    pgmFile.close();
}

// -------------------------------------------------
void PgmBild::aendereHelligkeit(int wert)
{
    int neuerWert;

    for (unsigned int i = 0; i < m_breite*m_hoehe; ++i) {
        neuerWert = m_pBilddaten[i] + wert;
        if (neuerWert < 0)
            m_pBilddaten[i] = 0;
        else if (neuerWert > static_cast<int>(m_maxGraustufen))
            m_pBilddaten[i] = m_maxGraustufen;
        else
            m_pBilddaten[i] = static_cast<uint8_t>(neuerWert);
    }
}

// -------------------------------------------------
void PgmBild::speichereInDatei(string dateiname) const
{
    ofstream pgmBild(dateiname); // Datei oeffnen

    // Oeffnen ueberpruefen
    if (!pgmBild) {
        cerr << "Datei " << dateiname << " konnte nicht geoeffnet werden - Bild wird nicht gespeichert!" << endl;
        return;
    }

    // PGM-Kopf schreiben
    pgmBild << "P2\n";
    pgmBild << m_breite << " " << m_hoehe << '\n';
    pgmBild << m_maxGraustufen << '\n';

    // Bilddaten
    for (unsigned int i = 0; i < m_breite*m_hoehe; ++i)
        pgmBild << static_cast<int>(m_pBilddaten[i]) << '\n';

    pgmBild.close(); // Datei schliessen
}
