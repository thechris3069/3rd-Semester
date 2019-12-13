#ifndef RAUM_H
#define RAUM_H

#include <iostream>
#include "player.h"

class Raum
{
public:
    Raum(const Raum &r)
    {
    ausgabetext = r.ausgabetext;
    }
    Raum operator=(const Raum &r)
    {
        if(this != &r)
        {
            ausgabetext = r.ausgabetext;
        }
        return *this;
    }
    Raum();
    virtual ~Raum();
    void getEntryText();
    virtual void interagieremitSpieler(Player *p);

protected:
    std::string ausgabetext;
};

class RaumGold : public Raum
{
public:
    int anzahlGold;
RaumGold();
~RaumGold();
void interagieremitSpieler(Player *p);
};

class RaumHaendler : public Raum
{
    public:
RaumHaendler();
~RaumHaendler();
};

class RaumKreatur : public Raum
{
    public:
RaumKreatur();
~RaumKreatur();
void interagieremitSpieler(Player *p);
};

class RaumEXIT : public Raum
{
    public:
RaumEXIT();
void interagieremitSpieler(Player *p);
~RaumEXIT();
};

class RaumEINGANG : public Raum
{
    public:
RaumEINGANG();
void interagieremitSpieler(Player *p);
~RaumEINGANG();

};

class RaumLEER : public Raum
{
    public:
RaumLEER();
~RaumLEER();
};



#endif // RAUM_H
