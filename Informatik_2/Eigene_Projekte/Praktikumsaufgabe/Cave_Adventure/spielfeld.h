#ifndef SPIELFELD_H
#define SPIELFELD_H
#include <iostream>

class Spielfeld
{
public:
    Spielfeld();
    unsigned int reihe, spalte;
    std::string m_inhalt{"Hallo Welt"};
};

#endif // SPIELFELD_H
