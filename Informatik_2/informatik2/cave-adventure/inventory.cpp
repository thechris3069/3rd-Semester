#include "inventory.h"

#include <iostream>

Inventory::Inventory()
{
}

Inventory::Inventory(const Inventory &o)
{
    std::cout << "Copying inventory..." << std::endl;
    m_pNext = nullptr;
    m_price = o.m_price;
    m_name = o.m_name;
}

Inventory::~Inventory()
{
}

Weapon::Weapon()
{
}

std::string Weapon::getInfo() const
{
    std::string text;
    text = m_name + " (" + m_description;
    text += ", Preis: " + std::to_string(m_price);
    text += ", Schaden: " + std::to_string(m_damage);
    text += ")";
    return text;
}

Rock::Rock()
{
    m_name = "Stein";
    m_description = "ein faustgrosser Stein";
    m_damage = 5;
    m_price = 1;
}

Inventory* Rock::getDuplicate()
{
    return new Rock(*this);
}

Dagger::Dagger()
{
    m_name = "Dolch";
    m_description = "ein nicht ganz scharfer Dolch";
    m_damage = 10;
    m_price = 20;
}

Inventory* Dagger::getDuplicate()
{
    return new Dagger(*this);
}

RustySword::RustySword()
{
    m_name = "Rostiges Schwert";
    m_description = "ein verrostetes Schwert, das in die Jahre gekommen ist und trotzdem noch nuetzlich sein kann";
    m_damage = 20;
    m_price = 100;
}

Inventory* RustySword::getDuplicate()
{
    return new RustySword(*this);
}

Consumable::Consumable()
{
}

std::string Consumable::getInfo() const
{
    std::string text;
    text = m_name;
    text += " (Preis: " + std::to_string(m_price);
    text += ", Punkte: " + std::to_string(m_healingValue);
    text += ")";
    return text;
}

CrustyBread::CrustyBread()
{
    m_name = "Brotrinde";
    m_healingValue = 10;
    m_price = 12;
}

Inventory* CrustyBread::getDuplicate()
{
    return new CrustyBread(*this);
}

MagicPotion::MagicPotion()
{
    m_name = "Zaubertrank";
    m_healingValue = 50;
    m_price = 60;
}

Inventory* MagicPotion::getDuplicate()
{
    return new MagicPotion(*this);
}
