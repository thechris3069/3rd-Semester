/*
 * Erste objektorienterte Variante des Spiels 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 1.4.2019
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef CAVEADVENTURE_H
#define CAVEADVENTURE_H

#include "player.h"
#include "world.h"

class CaveAdventure
{
private:
    Player m_player;
    World  m_world;

    /*
     * Ausfuehren eines Spielschritts
     */
    void doOneStep(char action);

public:
    /*
     * Konstruktor:
     * - Initialisierung des Spielers (Name)
     * - Initialisierung der Welt (impliziter Konstruktoraufruf!)
     * - falls Pfad uebergeben wird, wird nach Hoehlendateien gesucht, sonst wird Welt zufaellig erzeugt
     */
    CaveAdventure(std::string pfadZuHoehlendateien = "");

    /*
     * Kopierkonstruktor
     */
    CaveAdventure(const CaveAdventure &o) = delete;

    /*
     * Zuweisungsoperator
     */
    CaveAdventure &operator=(const CaveAdventure &o) = delete;

    /*
     * Destruktor - aktuell ohne Funktionalitaet
     */
    ~CaveAdventure();

    /*
     * Abfrage, ob Spiel zu Ende ist
     */
    bool isGameFinished() const;

    /*
     * Abfrage der Eingabe vom Nutzer und Ausfuehren eines Spielschritts
     * mittels der Methode doOneStep
     */
    void getAndProcessUserInput();
};

#endif // CAVEADVENTURE_H
