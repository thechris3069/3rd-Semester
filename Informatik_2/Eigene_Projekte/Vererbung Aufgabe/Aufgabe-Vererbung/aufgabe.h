#ifndef AUFGABE_H
#define AUFGABE_H
#include <iostream>
#include <string>

class Aufgabe
{
public:
    Aufgabe();
    virtual ~Aufgabe();
    void setVerantwortlichen(std::string person);
    void setTermin(std::string termin);
    std::string getTermin();
    virtual void ausfuehren();

private:
    std::string m_verantwortlicher;
    std::string m_termin;
protected:
    bool m_istErledigt;
};


class PruefingSchreiben : public Aufgabe
{
private:

    std::string m_fach;
    void blattbeschreiben();
    void blattabgeben();
public:
        PruefingSchreiben(std::string fach = 0);
    void ausfuehren();
};

class PartyFeiern : public Aufgabe
{
  private:


    std::string m_ort;
    void leuteAbholen();
public:
        PartyFeiern();
           ~PartyFeiern();
   void ausfuehren();
   void funktion();
};


#endif // AUFGABE_H
