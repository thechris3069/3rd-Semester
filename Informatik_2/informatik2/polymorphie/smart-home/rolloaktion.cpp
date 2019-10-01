#include "rolloaktion.h"

#include <iostream>
#include <string>
using namespace std;

RolloAktion::RolloAktion(unsigned int zeit, string adr1, string adr2, bool hoch)
    : Aktion(zeit), m_rolloAdresse1(adr1), m_rolloAdresse2(adr2), m_hoch(hoch)
{
    cout << "Neue Rolloaktion: " << zeit << ", " << adr1 << ", " << adr2 << ", " << hoch << endl;
}

void RolloAktion::ausfuehren()
{
    cout << "Rolloaktion ausfuehren: " << getZeitstempel() << ", ";
    cout << m_rolloAdresse1 << ", " << m_rolloAdresse2 << ", ";
    cout << m_hoch << endl;
}
