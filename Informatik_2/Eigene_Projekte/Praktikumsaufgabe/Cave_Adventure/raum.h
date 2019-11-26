#ifndef RAUM_H
#define RAUM_H

#include <iostream>

class Raum
{
public:
    Raum();
    ~Raum();
    std::string getEntryText();
};

class RaumGold : public Raum
{
public:
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
