/*
 * Modellierung der Gegenstaende des Spielers in der Hoehlenwelt im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Ebenso wie der Spieler kann auch der Haendler solche Gegenstaende besitzen und damit handeln.
 *
 * Claudia Meitinger
 * 15.4.2019
 * 3.5.2019 - CM - getPrice
 *                 Typbestimmung
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

class Inventory
{
private:
    Inventory *m_pNext = nullptr; // next-Zeiger zur Verwendung in einer verketteten Liste

protected:
    int m_price; // Preis (in Anzahl Goldstuecken)
    std::string m_name; // Kurzbezeichnung des Inventarstueckes

public:
    /*
     * Konstruktor
     */
    Inventory();

    /*
     * Kopierkonstruktor
     */
    Inventory(const Inventory &o);

    /*
     * Zuweisungsoperator
     */
    Inventory &operator=(const Inventory &o) = delete;

    /*
     * Destruktor
     */
    virtual ~Inventory();

    /*
     * Zugriff auf next-Zeiger
     */
    void setNext(Inventory *p) { m_pNext = p; }
    Inventory *getNext() const { return m_pNext; }

    /*
     * Bildschirmanzeige
     */
    virtual std::string getInfo() const = 0;

    /*
     * getter
     */
    int getPrice() const { return m_price; }

    /*
     * Typabfrage (fuer Handeln, stilistisch fragwuerdig)
     */
    virtual bool isWeapon() { return false; }
    virtual bool isConsumable() { return false; }

    /*
     * Speicher fuer Duplikat eines Objekts (aller abgeleiteten Klassen) anfordern
     * und Zeiger darauf zurueckgeben
     */
    virtual Inventory *getDuplicate() = 0;
};

class Weapon : public Inventory
{
protected:
    std::string m_description; // Beschreibung der Waffe
    int         m_damage; // Schaden, der einer Kreatur mit dieser Waffe zugefuegt werden kann

public:
    /*
     * Konstruktor
     */
    Weapon();

    /*
     * Kopierkonstruktor
     */
    // Standardverhalten ok; Weapon(const Weapon &o) = delete;

    /*
     * Zuweisungsoperator
     */
    Weapon &operator=(const Weapon &o) = delete;

    /*
     * Abfrage von Schadenshoehe
     */
    int getDamage() const { return m_damage; }

    /*
     * Abfrage von Information
     */
    std::string getInfo() const;

    /*
     * Typabfrage (fuer Handeln, stilistisch fragwuerdig)
     */
    virtual bool isWeapon() { return true; }
};

class Rock : public Weapon
{
public:
    Rock();
    // Standardverhalten ok; Rock(const Rock &o) = delete;
    Rock &operator=(const Rock &o) = delete;
    virtual Inventory *getDuplicate();
};

class Dagger : public Weapon
{
public:
    Dagger();
    // Standardverhalten ok; Dagger(const Dagger &o) = delete;
    Dagger &operator=(const Dagger &o) = delete;
    virtual Inventory *getDuplicate();
};

class RustySword : public Weapon
{
public:
    RustySword();
    // Standardverhalten ok; RustySword(const RustySword &o) = delete;
    RustySword &operator=(const RustySword &o) = delete;
    virtual Inventory *getDuplicate();
};

class Consumable : public Inventory
{
protected:
    int m_healingValue; // Anzahl der Punkte, die beim Konsumieren auf den Gesundheitszustand des Spielers addiert werden

public:
    /*
     * Konstruktor
     */
    Consumable();

    /*
     * Kopierkonstruktor
     */
    // Standardverhalten ok; Consumable(const Consumable &o) = delete;

    /*
     * Zuweisungsoperator
     */
    Consumable &operator=(const Consumable &o) = delete;

    /*
     * Abfrage der Gesundheitspunkte
     */
    int getHealingValue() const { return m_healingValue; }

    /*
     * Abfrage von Information
     */
    std::string getInfo() const;

    /*
     * Typabfrage (fuer Handeln, stilistisch fragwuerdig)
     */
    virtual bool isConsumable() { return true; }
};

class CrustyBread : public Consumable
{
public:
    CrustyBread();
    // Standardverhalten ok; CrustyBread(const CrustyBread &o) = delete;
    CrustyBread &operator=(const CrustyBread &o) = delete;
    virtual Inventory *getDuplicate();
};

class MagicPotion : public Consumable
{
public:
    MagicPotion();
    // Standardverhalten ok; MagicPotion(const MagicPotion &o) = delete;
    MagicPotion &operator=(const MagicPotion &o) = delete;
    virtual Inventory *getDuplicate();
};

#endif // INVENTORY_H
