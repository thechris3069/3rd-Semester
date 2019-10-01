/*
 * Vorlesungsbeispiel Informatik 2, 2.4.2019
 *
 * Thema: Realisierung von Assoziationen in C++
 *        Statisches Array vs. dynamisches Array
 *
 * hier: Klasse Person_DynArray, die Verweise auf beliebig viele Aufgaben in einem
 *       dynamisch wachsenden Array vorhalten kann
 *
 * Aufgabe: Aendern Sie die Implementierung so ab, dass nicht beim Hinzufuegen JEDER
 *          neuen Aufgabe neuer Speicher allokiert werden muss, sondern z.B. in Pakete von 5 Aufgaben!
 *
 * Claudia Meitinger
 */


#ifndef PERSON_DYNARRAY_H
#define PERSON_DYNARRAY_H

#include <string>
#include "aufgabe.h"

class Person_DynArray
{
private:
    std::string m_name;
    Aufgabe **m_aufgaben; // Startadresse eines Feldes mit m_anzahlAufgaben Adressen von zugeordneten Aufgaben
    unsigned int m_anzahlAufgaben;

public:
    Person_DynArray(std::string name);
    ~Person_DynArray();
    bool aufgabeHinzufuegen(Aufgabe *neueAufgabe);
    void zeigeAufgaben();
};

#endif // PERSON_DYNARRAY_H
