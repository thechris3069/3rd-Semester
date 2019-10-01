#include "trader.h"

#include <iostream>

using namespace std;

Trader::Trader()
{
    // 6 zufaellige Gegenstaende vorhalten
    for (unsigned int i = 0; i < 6; ++i)
    {
        try {
            switch(rand() % 5)
            {
            case 0: m_inventory.push_back(new Rock());        break;
            case 1: m_inventory.push_back(new Dagger());      break;
            case 2: m_inventory.push_back(new RustySword());  break;
            case 3: m_inventory.push_back(new CrustyBread()); break;
            case 4: m_inventory.push_back(new MagicPotion()); break;
            }
        } catch (std::bad_alloc &e) {
            cerr << "Inventar fuer Haendler konnte nicht erzeugt werden!" << endl;
            cerr << e.what() << endl;
        }
    }
}

Trader::~Trader()
{
    // Speicher freigeben
    for(Inventory *p : m_inventory) {
        delete p;
    }
    m_inventory.clear();
}

void Trader::showInventory() const
{
    int i = 1;
    for (Inventory *p : m_inventory) {
        cout << i++ << " - " << p->getInfo() << endl;
    }
}

int Trader::getPrice(unsigned int idx) const
{
    if (idx < m_inventory.size()) {
        return m_inventory[idx]->getPrice();
    }
    return 0;
}

Inventory *Trader::sellInventory(unsigned int idx)
{
    if (idx < m_inventory.size()) {
        Inventory *p = m_inventory[idx];
        m_gold += p->getPrice();
        m_inventory.erase(m_inventory.begin() + idx);
        return p;
    }
    return nullptr;
}
