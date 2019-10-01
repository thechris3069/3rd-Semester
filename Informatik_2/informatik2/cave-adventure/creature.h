/*
 * Modellierung der feindlichen Kreaturen in der Hoehlenwelt im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 5.4.2019
 *
 * 15.4.2019 - Angriff auf Kreatur hinzugefuegt
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
private:
    int m_healthPoints; // Gesundheitszustand der Kreatur
    int m_damagePoints; // Anzahl der Punkte, die der Spieler verliert, wenn er mit der Kreatur in Kontakt kommt
    std::string m_name; // Bezeichnung der Kreatur

public:
    /*
     * Konstruktor - zufaellige Initialisierung der Art der Kreatur
     */
    Creature();

    /*
     * Kopierkonstruktor
     */
    Creature(const Creature &o) = delete;

    /*
     * Zuweisungsoperator
     */
    Creature &operator=(const Creature &o) = delete;

    /*
     * Destruktor
     */
    ~Creature();

    /*
     * Abfrage von Zustandsgroessen
     */
    bool isAlive() const;
    int getHealthPoints() const { return m_healthPoints; }
    int getDamagePoints() const { return m_damagePoints; }
    std::string getName() const { return m_name; }

    /*
     * Angriff
     */
    void attack(int damage);
};

#endif // CREATURE_H
