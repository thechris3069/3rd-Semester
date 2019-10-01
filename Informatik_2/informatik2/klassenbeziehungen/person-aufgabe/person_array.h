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

#ifndef PERSON_ARRAY_H
#define PERSON_ARRAY_H

#include <string>
#include "aufgabe.h"

#define MAX_AUFGABEN 5

class Person_Array
{
private:
    std::string m_name;
    Aufgabe *m_aufgaben[MAX_AUFGABEN];

public:
    Person_Array(std::string name);
    ~Person_Array();
    bool aufgabeHinzufuegen(Aufgabe *neueAufgabe);
    void zeigeAufgaben();
};

#endif // PERSON_ARRAY_H
