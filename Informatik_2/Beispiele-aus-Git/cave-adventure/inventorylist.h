/*
 * Einfach vorwaerts verkettete Liste aus Gegenstaenden des Spielers in der Hoehlenwelt im Spiel 'Cave Adventure'
 * (vgl. Praktikumsanleitung Informatik 2 SS 2019 in moodle und
 *  Johnson, Phillip (2018): Make Your Own Python Text Adventure - A Guide To Learning Programming. apress.)
 *
 * Claudia Meitinger
 * 15.4.2019
 * 31.5.2019 - CM - Zuweisungsoperator/Kopierkonstruktor
 */

#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H

#include "inventory.h"

class InventoryList
{
private:
    Inventory *m_anchor = nullptr;
public:
    /*
     * Standardkonstruktor
     */
    InventoryList();

    /*
     * Kopierkonstruktor
     */
    InventoryList(const InventoryList &o);

    /*
     * Zuweisungsoperator
     */
    InventoryList &operator=(const InventoryList &o);

    /*
     * Destruktor - gibt Speicher aller Listenelemente frei
     */
    ~InventoryList();

    /*
     * Entfernt alle Elemente der Liste und gibt Speicher frei
     */
    void clear();

    /*
     * Einfuegen eines neuen Listenelements am Anfang der Liste;
     * Speicher fuer Listenelement muss dynamisch reserviert worden sein;
     * Liste uebernimmt Zustaendigkeit fuer Freigabe des Speicherplatzes
     */
    void pushFront(Inventory *p);

    /*
     * Einfuegen eines neuen Listenelements am Ende der Liste;
     * Speicher fuer Listenelement muss dynamisch reserviert worden sein;
     * Liste uebernimmt Zustaendigkeit fuer Freigabe des Speicherplatzes
     */
    void pushBack(Inventory *p);

    /*
     * Lesender Zugriff auf idx-tes Listenelement (0..anzahlElemente-1)
     * Im Falle eines ungueltigen Index wird der nullptr zurueckgegeben.
     */
    const Inventory *getElementAt(unsigned int idx) const;

    /*
     * Abfrage der Anzahl der Listenelemente
     */
    unsigned int size() const;

    /*
     * Bildschirmanzeige aller Eintraege in der Liste
     */
    std::string getInfo() const;

    /*
     * Methode zum Entfernen (einschl. Speicherplatzfreigabe) des Elements
     * an Position idx (0..anzahlElemente-1)
     */
    void remove(unsigned int idx);
};

#endif // INVENTORYLIST_H
