/*
 * Vorlesungsbeispiel Informatik 2, 2.4.2019
 *
 * Thema: Realisierung von Assoziationen in C++
 *        Statisches Array vs. dynamisches Array
 *
 * Erweiterung: Ergaenzen Sie Methoden, um Aufgaben von einer Person auf eine andere zu uebertragen und wenden Sie diese im Hauptprogramm an!
 *
 * Claudia Meitinger
 */

#include <iostream>
using namespace std;

#include "person_array.h"
#include "person_dynarray.h"
#include "person_vector.h"

void erzeugeAufgabenFuerClaudia(Person_Array *p)
{
    Aufgabe *pA1 = new Aufgabe("Vorlesung vorbereiten");
    Aufgabe *pA2 = new Aufgabe("Screencast machen");

    p->aufgabeHinzufuegen(pA1);
    p->aufgabeHinzufuegen(pA2);
}

void erzeugeAufgabenFuerHans(Person_DynArray *p)
{
    Aufgabe *pA1 = new Aufgabe("Radtour planen");
    Aufgabe *pA2 = new Aufgabe("Besprechung vorbereiten");

    p->aufgabeHinzufuegen(pA1);
    p->aufgabeHinzufuegen(pA2);
}

void erzeugeAufgabenFuerVerena(Person_Vector *p)
{
    Aufgabe *pA1 = new Aufgabe("Informatik lernen");
    Aufgabe a2("Projektplan aktualisieren");

    p->aufgabeHinzufuegen(pA1);
//    p->aufgabeHinzufuegen(&a2); // <-- syntaktisch korrekt; trotzdem falsch wg. Lebensdauer des Objekts a2!
}


int main()
{
    Person_Array c("Claudia");
    Person_DynArray h("Hans");
    Person_Vector v("Verena");

    erzeugeAufgabenFuerClaudia(&c);
    erzeugeAufgabenFuerHans(&h);
    erzeugeAufgabenFuerVerena(&v);

    c.zeigeAufgaben();
    h.zeigeAufgaben();
    v.zeigeAufgaben();

    return 0;
}

