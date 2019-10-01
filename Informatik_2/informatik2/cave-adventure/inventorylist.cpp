#include "inventorylist.h"

InventoryList::InventoryList()
{
}

InventoryList::InventoryList(const InventoryList &o)
{
    for (Inventory *it = o.m_anchor; it != nullptr; it = it->getNext()) {
        this->pushBack(it->getDuplicate());
    }
}

InventoryList &InventoryList::operator=(const InventoryList &o)
{
    if (this != &o) { // Selbstzuweisung verhindern
        clear(); // alten Speicher freigeben
        for (Inventory *it = o.m_anchor; it != nullptr; it = it->getNext()) {
            this->pushBack(it->getDuplicate());
        }
    }
    return *this; // Kettenzuweisung ermoeglichen
}

InventoryList::~InventoryList()
{
    clear();
}

void InventoryList::clear()
{
    while (m_anchor != nullptr) {
        Inventory *p = m_anchor;
        m_anchor = p->getNext();
        delete p;
    }
}

void InventoryList::pushFront(Inventory *p)
{
    if (!p)
        return;

    p->setNext(m_anchor);
    m_anchor = p;
}

void InventoryList::pushBack(Inventory *p)
{
    if (!p)
        return;

    // Liste ist leer => Element am Anfang einfuegen
    if (m_anchor == nullptr) {
        pushFront(p);
    } else { // Liste ist nicht leer
        // Zum (vor)letzten Element gehen, beginnend beim ersten Element
        // Dieses ist hier sicher nicht nullptr (Liste nicht leer!) -
        // somit darf im folgenden it->getNext aufgerufen werden.
        Inventory *it;
        for (it = m_anchor; it->getNext() != nullptr; it = it->getNext())
            ;
        // Neues Element anfuegen
        it->setNext(p);
        p->setNext(nullptr);
    }
}

const Inventory *InventoryList::getElementAt(unsigned int idx) const
{
    unsigned int i = 0;
    Inventory *p = m_anchor;
    while (p != nullptr && i < idx) {
        p = p->getNext();
        ++i;
    }
    return p;
}

unsigned int InventoryList::size() const
{
    unsigned int count = 0;
    Inventory *p = m_anchor;
    while (p != nullptr) {
        ++count;
        p = p->getNext();
    }
    return count;
}

std::string InventoryList::getInfo() const
{
    std::string text;
    int i = 1;
    for (Inventory *p = m_anchor; p != nullptr; p = p->getNext()) {
        text += std::to_string(i++);
        text += ": ";
        text += p->getInfo();
        text += '\n';
    }
    return text;
}

void InventoryList::remove(unsigned int idx)
{
    Inventory *tmp, *tmpDel;
    unsigned int i = 0;

    // Liste leer => Abbruch
    if (!m_anchor)
        return;

    // 1. Element => Anker veraendern
    if (idx == 0) {
        tmpDel = m_anchor;
        m_anchor = m_anchor->getNext();
        delete tmpDel;
    } else {
        // zum Element vor dem zu loeschenden iterieren
        tmp = m_anchor;
        for (i = 0; i < idx-1 && tmp->getNext() != nullptr; ++i) {
            tmp = tmp->getNext();
        }
        // nur loeschen, wenn richtiges Element vorhanden ist
        if (i == idx-1) {
            tmpDel = tmp->getNext();
            tmp->setNext(tmpDel->getNext());
            delete tmpDel;
        }
    }
}
