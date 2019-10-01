/*
 * Vorlesungsbeispiel Informatik 2 zur Einfuehrung von Vererbung / Polymorphie
 *
 * Claudia Meitinger
 */

#include <iostream>
#include <string>
using namespace std;

// ===============================================
// --- Klasse Aufgabe
// ===============================================
class Aufgabe
{
private:
    string m_Verantwortlicher;
    string m_Termin;
protected:
    bool   m_istErledigt;
public:
    Aufgabe(string termin = "9.11.2016, 9:00", string name = "niemand");
    virtual ~Aufgabe();
    void setVerantwortlichen(string name);
    void setTermin(string datum);
    string getTermin();
    virtual void ausfuehren();
};

// ===============================================
// --- Klasse PruefungSchreiben
// ===============================================
class PruefungSchreiben : public Aufgabe
{
private:
    string m_Fach;
    void blattBeschreiben();
    void blattAbgeben();
public:
    PruefungSchreiben(string fach);
    ~PruefungSchreiben();
    void ausfuehren();
};

// ===============================================
// --- Klasse PartyFeiern
// ===============================================
class PartyFeiern : public Aufgabe
{
private:
    string m_Ort;
    void leuteAbholen();
public:
    PartyFeiern(string ort);
    ~PartyFeiern();
    void ausfuehren();
};

// ===============================================
// --- Methodendefinitionen der Klasse Aufgabe ---
// ===============================================
Aufgabe::Aufgabe(string termin, string name)
    : m_Termin(termin), m_Verantwortlicher(name)
{
    cout << "Konstruktor Aufgabe" << endl;
    m_istErledigt      = false;
}

Aufgabe::~Aufgabe()
{
    cout << "Destruktor Aufgabe" << endl;
}

void Aufgabe::setVerantwortlichen(string name)
{
    m_Verantwortlicher = name;
}

void Aufgabe::setTermin(string datum)
{
    m_Termin = datum;
}

string Aufgabe::getTermin()
{
    return m_Termin;
}

void Aufgabe::ausfuehren()
{
    cout << "Fuehre Aufgabe aus..." << endl;
}

// =========================================================
// --- Methodendefinitionen der Klasse PruefungSchreiben ---
// =========================================================
PruefungSchreiben::PruefungSchreiben(string fach)
{
    cout << "Konstruktor PruefungSchreiben" << endl;
    m_Fach = fach;
}

PruefungSchreiben::~PruefungSchreiben()
{
    cout << "Destruktor PruefungSchreiben" << endl;
}

void PruefungSchreiben::blattBeschreiben()
{
    cout << "Ich schreibe..." << endl;
}

void PruefungSchreiben::blattAbgeben()
{
    cout << "Fertig!" << endl;
}

void PruefungSchreiben::ausfuehren()
{
    // Ok: Zugriff auf private Elemente der eigenen Klasse
    cout << "Pruefung im Fach " << m_Fach << endl;
    blattBeschreiben();

    // Fehler: Zugriff auf private Elemente der Basisklasse ist nicht moeglich
    // cout << "muss fertig sein bis " << m_Termin << endl;

    // Ok: Zugriff auf public Elemente der Basisklasse
    cout << "muss fertig sein bis " << getTermin() << endl;

    blattAbgeben();
    // Ok: Zugriff auf protected Elemente der Basisklasse
    m_istErledigt = true;
}

// ===================================================
// --- Methodendefinitionen der Klasse PartyFeiern ---
// ===================================================
PartyFeiern::PartyFeiern(string ort)
    : Aufgabe("11.11.2016, 18 Uhr", "Oma")
{
    cout << "Konstruktor PartyFeiern" << endl;
    m_Ort = ort;
}

PartyFeiern::~PartyFeiern()
{
    cout << "Destruktor PartyFeiern" << endl;
}

void PartyFeiern::leuteAbholen()
{
    cout << "Ich sammle Freunde ein..." << endl;
}

void PartyFeiern::ausfuehren()
{
    // Ok: Zugriff auf private Elemente der eigenen Klasse
    cout << "Party bei " << m_Ort << endl;
    leuteAbholen();

    // Fehler: Zugriff auf private Elemente der Basisklasse ist nicht moeglich
    // cout << "geht los um " << m_Termin << endl;

    // Ok: Zugriff auf public Elemente der Basisklasse
    cout << "geht los um " << getTermin() << endl;

    // Ok: Zugriff auf protected Elemente der Basisklasse
    m_istErledigt = true;
}


// ===============================================
// --- Hauptprogramm
// ===============================================
int main()
{
    Aufgabe a;
    // a.m_Verantwortlicher = "Claudia"; // Fehler: private
    // a.m_istErledigt = true;           // Fehler: protected
    a.ausfuehren();                      // Ok: public

    PruefungSchreiben info("Informatik 2");
    info.setVerantwortlichen("Claudia"); // Ok: public in Basisklasse
    info.ausfuehren();                   // Ok: public in abgeleiteter Klasse

    PartyFeiern party("Steffi");
    party.setTermin("10.11.2016, 17 Uhr"); // Ok: public in Basisklasse
    party.ausfuehren();                    // Ok: public in abgeleiteter Klasse

    // Basisklassenzeiger
    Aufgabe *pA = &info;

    info.ausfuehren();
    pA->ausfuehren();

    return 0;
}

