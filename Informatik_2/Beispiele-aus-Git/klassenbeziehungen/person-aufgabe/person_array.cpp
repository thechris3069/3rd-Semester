/*
 * Vorlesungsbeispiel Informatik 2, 2.4.2019
 *
 * Thema: Realisierung von Assoziationen in C++
 *        Statisches Array vs. dynamisches Array
 *
 * hier: Klasse Person_Array, die Verweise auf max. 5 Aufgaben in einem statischen Array vorhalten kann
 *
 * Claudia Meitinger
 */

#include <iostream>
using namespace std;

#include "person_array.h"

Person_Array::Person_Array(string name)
{
    m_name = name;

    // Zu Beginn hat die Person keine Aufgaben: Kennzeichnung durch nullptr
    for (unsigned int i = 0; i < MAX_AUFGABEN; ++i) {
        m_aufgaben[i] = nullptr;
    }
}

Person_Array::~Person_Array()
{
    // Speicher der Aufgaben freigeben, die der Person zugeordnet sind
    for (unsigned int i = 0; i < MAX_AUFGABEN; ++i) {
        if (m_aufgaben[i])
            delete m_aufgaben[i];
    }
}

bool Person_Array::aufgabeHinzufuegen(Aufgabe *neueAufgabe)
{
    // Falls noch Kapazitaet fuer Aufgaben verfuegbar ist (Eintrag nullptr),
    // wird die neue Aufgabe der Person zugeordnet
    for (unsigned int i = 0; i < MAX_AUFGABEN; ++i) {
        if (m_aufgaben[i] == nullptr) {
            m_aufgaben[i] = neueAufgabe;
            return true;
        }
    }
    return false; // keine Kapazitaet mehr fre
}

void Person_Array::zeigeAufgaben()
{
    cout << "Aufgaben von " << m_name << ": " << endl;
    for (unsigned int i = 0; i < MAX_AUFGABEN; ++i) {
        if (m_aufgaben[i] != nullptr) {
            cout << "* ";
            m_aufgaben[i]->ausgeben();
        }
    }
}
