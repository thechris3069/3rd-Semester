#ifndef RAUM_H
#define RAUM_H

#include <iostream>

class Raum
{
public:
    Raum();
    ~Raum();
    virtual void getEntryText();
protected:
    std::string ausgabetext;
};

class RaumGold : public Raum
{
public:
    int anzahlGold;
RaumGold();
~RaumGold();
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
};

class RaumEXIT : public Raum
{
    public:
RaumEXIT();
~RaumEXIT();
};

class RaumEINGANG : public Raum
{
    public:
RaumEINGANG();
~RaumEINGANG();
};

class RaumLEER : public Raum
{
    public:
RaumLEER();
~RaumLEER();
};



#endif // RAUM_H
