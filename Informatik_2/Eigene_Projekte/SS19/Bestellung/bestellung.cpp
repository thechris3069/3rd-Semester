#include "bestellung.h"

//class Punkt()
//{
//    public m_x, m_y;

//};

Bestellung::Bestellung(int ap, int tag)
    :d(tag)
{
    anzahlpunkte = ap;
m_punkt = nullptr;
m_punkt = new Punkt[anzahlpunkte];


for(int i = 0; i< anzahlpunkte; ++i)
{
    m_punkt[i].m_x = i*2;
    m_punkt[i].m_y = i*3;
}

}
Bestellung::Bestellung(const Bestellung &p)
    :d(p.getTag())
{
    if(p.m_punkt){
        anzahlpunkte = p.anzahlpunkte;
        m_punkt = new Punkt[anzahlpunkte];
        for(int i = 0; i < anzahlpunkte; ++i)
        {
            m_punkt[i].m_x = p.m_punkt[i].m_x;
            m_punkt[i].m_y = p.m_punkt[i].m_y;
        }
    }
}

Bestellung::~Bestellung()
{
    if(m_punkt)
        delete m_punkt;
}

