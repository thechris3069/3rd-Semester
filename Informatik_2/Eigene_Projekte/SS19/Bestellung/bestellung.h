#ifndef BESTELLUNG_H
#define BESTELLUNG_H
#include <iostream>

class Datum
{
private:
public:
//protected:
    int m_tag, m_monat;
public:
    Datum(int tag,int monat= 70)
        :m_tag(tag)
    { m_monat = monat;   }
    int getTag() {return m_tag;}
    int getMonat() {return m_monat;}
};

class Punkt
{
    public:
    int m_x, m_y;

};


class Bestellung
{
public:
    Bestellung(int ap, int tag);
    Bestellung(const Bestellung &p);
    ~Bestellung();
    int getTag() const{return d.m_tag;}
private:
    Datum d;
public:
    void anzeigen()
    {
        std::cout << "Datum: Tag: Monat: " << d.m_monat << " " << d.getTag() <<std::endl;
    }
    Punkt *m_punkt;
        int anzahlpunkte;
};



#endif // BESTELLUNG_H
