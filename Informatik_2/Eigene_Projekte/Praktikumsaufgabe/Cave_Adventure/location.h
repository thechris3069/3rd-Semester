#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <cstdlib>
#include <string>


class Location
{
public:
    Location();

private:
    std::string zuweisen();
    std::string m_inhalt;
};

#endif // LOCATION_H
