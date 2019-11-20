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
RaumGold();
~RaumGold();
};

class RaumHaendler : public Raum
{
RaumHaendler();
~RaumHaendler();
};

class RaumKreatur : public Raum
{
RaumKreatur();
~RaumKreatur();
};

class RaumEXIT : public Raum
{
RaumEXIT();
~RaumEXIT();
};

class RaumEINGANG : public Raum
{
RaumEINGANG();
~RaumEINGANG();
};

class RaumLEER : public Raum
{
RaumLEER();
~RaumLEER();
};



#endif // RAUM_H
