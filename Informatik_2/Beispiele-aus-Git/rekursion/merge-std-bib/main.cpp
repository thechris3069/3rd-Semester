/*
 * Verwenden Sie den Algorithmus "merge" der C++ Standardbibliothek,
 * um zwei Felder (4, 2, 5, 1, 56) und (27, 70, 4, 19, 22, 5, 11)
 * sortiert in einem dritten Feld abzulegen!
 *
 * Hinweis: Der Parameter des merge-Algorithmus, der angibt, wo das Ergebnis
 *          abgelegt werden soll, muss ein "OutputIt" sein. Suchen Sie hierzu
 *          nach der Funktion "back_inserter", die Ihnen einen geeigneten
 *          Iterator liefert.
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 * 21.11.2017
 */

// ----- INCLUDES -----
#include <iostream>
#include <vector>    // Datenstruktur "Vektor"
#include <algorithm> // Algorithmen "sort" und "merge"
using namespace std;

// ----- Funktion zur Ausgabe eines vector<int> -----
void show(string name, const vector<int> &feld)
{
    cout << name << ": ";
    for (const int& n : feld)
        cout << n << " ";
    cout << endl;
}

// ----- HAUPTPROGRAMM -----
int main()
{
    vector<int> feld1 = {4, 2, 5, 1, 56};
    vector<int> feld2 = {27, 70, 4, 19, 22, 5, 11};
    vector<int> ergebnis;

    // Ausgabe der unsortierten Felder
    show("Feld 1", feld1);
    show("Feld 2", feld2);
    show("Ergebnis", ergebnis);

    // Felder 1 und 2 sortieren
    sort(feld1.begin(), feld1.end());
    sort(feld2.begin(), feld2.end());

    // Felder 1 und 2 in Ergebnis-Feld zusammenfuehren
    merge(feld1.begin(), feld1.end(), feld2.begin(), feld2.end(), back_inserter(ergebnis));

    // Ausgabe der sortierten / zusammengefuehrten Felder
    show("Feld 1", feld1);
    show("Feld 2", feld2);
    show("Ergebnis", ergebnis);

    return 0;
}

