#include "aufgabe.h"

Aufgabe::Aufgabe()
{
std::cout << "Konstruktor aufgerufen" << std::endl;
}

void Aufgabe::setTermin(std::string termin)
{
    m_termin = termin;
}
std::string Aufgabe::getTermin()
{
    return m_termin;
}

Aufgabe::~Aufgabe()
{
       std::cout << "Destruktor Basisklasse" <<std::endl;
}

void Aufgabe::setVerantwortlichen(std::string person)
{
    m_verantwortlicher = person;
}

void Aufgabe::ausfuehren()
{
    std::cout << "Aufgabe::ausfuehren()" <<std::endl;
}


void PruefingSchreiben::ausfuehren()
{
    std::cout << "PruefingSchreben::ausfuehren()" <<std::endl;
}

void PruefingSchreiben::blattabgeben()
{

}

void PruefingSchreiben::blattbeschreiben()
{

}

PruefingSchreiben::PruefingSchreiben(std::string fach)
{
m_fach = fach;
std::cout << "Pruefung in " << m_fach <<" schreiben" <<std::endl;
}

PartyFeiern::PartyFeiern()
{
    std::cout << "Konstruktor ParyFeiern" <<std::endl;
}

void PartyFeiern::leuteAbholen()
{

}

PartyFeiern::~PartyFeiern()
{
       std::cout << "PartyFeiern Destruktor" <<std::endl;
}

void PartyFeiern::ausfuehren()
{
   std::cout << "Partyausfuehren::ausfuehren()" <<std::endl;
}

void PartyFeiern::funktion()
{
    Aufgabe *pA = new PruefingSchreiben("Informatik 2");
    pA->ausfuehren();
    delete pA;
}

