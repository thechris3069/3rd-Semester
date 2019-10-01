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

#ifndef PERSON_VECTOR_H
#define PERSON_VECTOR_H

#include <string>
#include <vector>

#include "aufgabe.h"

class Person_Vector
{
private:
    std::string m_name;
    std::vector<Aufgabe *> m_aufgaben;

public:
    Person_Vector(std::string name);
    ~Person_Vector();
    bool aufgabeHinzufuegen(Aufgabe *neueAufgabe);
    void zeigeAufgaben();
};

#endif // PERSON_VECTOR_H


