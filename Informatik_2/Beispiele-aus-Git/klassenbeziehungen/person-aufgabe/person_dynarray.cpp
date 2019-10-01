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

#include <iostream>
using namespace std;

#include "person_dynarray.h"

Person_DynArray::Person_DynArray(string name)
{
    m_name = name;
    // Zu Beginn sind keine Aufgaben vorhanden
    m_aufgaben = nullptr;
    m_anzahlAufgaben = 0;
}


Person_DynArray::~Person_DynArray()
{
    // Speicher der Aufgaben freigeben, die der Person zugeordnet sind
    for (unsigned int i = 0; i < m_anzahlAufgaben; ++i)
        delete m_aufgaben[i];
    // Speicher des Feldes mit Anfangsadressen der Aufgaben freigeben
    delete[] m_aufgaben;
}

bool Person_DynArray::aufgabeHinzufuegen(Aufgabe *neueAufgabe)
{
    // Speicherbereich fuer eine Aufgabenadresse mehr reservieren
    Aufgabe **temp = new Aufgabe *[m_anzahlAufgaben + 1];

    // Alte Verweise auf Aufgaben in neuen Speicherbereich umkopieren
    for (unsigned int i = 0; i < m_anzahlAufgaben; ++i)
        temp[i] = m_aufgaben[i];

    // neue Aufgabe hinzufuegen
    temp[m_anzahlAufgaben] = neueAufgabe;

    // Anzahl Aufgaben aktualisieren
    m_anzahlAufgaben++;

    // Alten Speicherbereich freigeben
    delete[] m_aufgaben;

    // Startadresse des neuen Speicherbereichs im Objekt hinterlegen
    m_aufgaben = temp;

    return true;

    // TODO: Moegliche Exception beim Anfordern von new abfangen und infolgedessen false zurueckgeben
}

void Person_DynArray::zeigeAufgaben()
{
    cout << "Aufgaben von " << m_name << ": " << endl;
    for (unsigned int i = 0; i < m_anzahlAufgaben; ++i) {
        cout << "* ";
        m_aufgaben[i]->ausgeben();
    }
}

