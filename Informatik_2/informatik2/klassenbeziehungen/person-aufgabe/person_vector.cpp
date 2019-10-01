/*
 * Vorlesungsbeispiel Informatik 2, 2.4.2019
 *
 * Thema: Realisierung von Assoziationen in C++
 *        Statisches Array vs. dynamisches Array
 *
 * hier: Klasse Person_Vector, die Verweise auf beliebig viele Aufgaben in einem
 *       Vektor der C++ Standardbibliothek vorhalten kann
 *
 * Claudia Meitinger
 */

#include <iostream>
using namespace std;

#include "person_vector.h"

Person_Vector::Person_Vector(string name)
{
    m_name = name;

}

Person_Vector::~Person_Vector()
{
    // Speicher der Aufgaben freigeben, die der Person zugeordnet sind
    for (unsigned int i = 0; i < m_aufgaben.size(); ++i)
        delete m_aufgaben[i];
}

bool Person_Vector::aufgabeHinzufuegen(Aufgabe *neueAufgabe)
{
    m_aufgaben.push_back(neueAufgabe);
    return true;
}

void Person_Vector::zeigeAufgaben()
{
    cout << "Aufgaben von " << m_name << ": " << endl;
    for (unsigned int i = 0; i < m_aufgaben.size(); ++i) {
        cout << "* ";
        m_aufgaben[i]->ausgeben();
    }
}
