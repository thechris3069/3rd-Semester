/*
 * Initiale Variante der Hoehlenwelt bestehend aus verschiedenen Raeumen
 * im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 1.4.2019
 *
 * 5.4.2019 - CM - Raeume hinzugefuegt
 * 16.5.2019 - CM - Initialisierung der Welt nicht ueber Konstruktor, sondern ueber separate Methode
 *                  (wahlweise zufaellig oder aus Text-Datei mit CAVE-Beschreibung)
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

#include "room.h"

class World
{
private:
    unsigned int m_nrRows; // Anzahl Zeilen der Spielewelt (0: noerdlichste Zeile .. m_nrRows-1: suedlichste Zeile)
    unsigned int m_nrCols; // Anzahl Spalten der Spielewelt (0: westlichste Spalte .. m_nrColumns-1: oestlichste Spalte)

    unsigned int m_rowStart; // Zeile Startfeld
    unsigned int m_colStart; // Spalte Startfeld

    Room ***m_rooms; // Startadresse eines zweidimensionalen Feldes mit Startadressen aus Raeumen

    /*
     * Methode, mit der zufaellig die Zeile und Spalte eines noch undefinierten Raums
     * bestimmt und an den Adressen row/col abgelegt werden.
     * Undefinierter Raum: m_rooms[*row][*col] == nullptr
     *
     * Rueckgabe: true, falls noch undefinierter Raum vorhanden war, sonst false.
     */
    bool getUndefinedRoom(unsigned int *row, unsigned int *col);

    /*
     * Methode, die rekursiv alle Dateien in einem gegebenen Pfad ermittelt
     * und versucht, Hoehlenraeume zu finden.
     * Rueckgabe: Vektor mit Dateinamen (inkl. Pfad)
     */
    std::vector<std::string> findCaves(std::string cavePath);
public:
    /*
     * Konstruktor:
     * - Festlegen der Groesse und des Inhalts der Welt (= Hoehle),
     *   zufaellig (falls kein Pfad oder Dateiverarbeitung fehlschlaegt) oder
     *   aus Datei aus uebergebenem Pfad (falls uebergeben)
     * - Bestimmen der Startposition
     */
    World(std::string cavePath = "");

    /*
     * Kopierkonstruktor
     */
    World(const World &o) = delete;

    /*
     * Zuweisungsoperator
     */
    World &operator=(const World &o) = delete;

    /*
     * Destruktor - aktuell ohne Funktionalitaet
     */
    ~World();

    /*
     * Zufaelliges Generieren einer Hoehle mit nrRols Zeilen und nrColums Spalten
     */
    void initRandom(unsigned int nrRows = 7, unsigned int nrColumns = 10);

    /*
     * Durchsucht den uebergebenen Pfad nach Hoehlendateien und
     * liest den Hoehlenaufbaus aus einer Datei.
     * Die Raeume werden entsprechend der Beschreibung in der Datei generiert:
     * --------------------
     * CAVE
     * <nrRows> <nrCols>
     * description (one line)
     * XXXXXXXX...
     * XXXXXXXX... (<nrRows> lines of <nrCols> chars)
     * ...
     * --------------------
     * X: empty room
     * E: start
     * A: exit
     * G: gold
     * H: trader
     * K: creature
     */
    bool initFromFile(std::string cavePath);

    /*
     * Abfrage eines bestimmten Raums
     */
    Room *getRoomAt(int row, int col) const;

    /*
     * Abfrage von Eigenschaften der Welt
     */
    unsigned int getNrRows() const { return m_nrRows; }
    unsigned int getNrCols() const { return m_nrCols; }
    unsigned int getRowStart() const { return m_rowStart; }
    unsigned int getColStart() const { return m_colStart; }
};

#endif // WORLD_H
