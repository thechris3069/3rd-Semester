#include "lichtaktion.h"

#include <iostream>
#include <string>
using namespace std;

LichtAktion::LichtAktion(unsigned int zeit, string adr, bool an)
    : Aktion(zeit), m_lichtAdresse(adr), m_an(an)
{
    cout << "Neue Lichtaktion: " << zeit << ", " << adr << ", " << an << endl;
}

void LichtAktion::ausfuehren()
{
    cout << "Lichtaktion ausfuehren: " << getZeitstempel() << ", ";
    cout << m_lichtAdresse << ", " << m_an << endl;
}
