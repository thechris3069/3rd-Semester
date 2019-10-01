/*
 * Wenn Sie mit cin eine Zahl einlesen wollen, der Nutzer aber Zeichen
 * eingibt, die nicht in eine Zahl konvertiert werden können, so wird
 * das "failbit" gesetzt (vgl. http://en.cppreference.com/w/cpp/io/ios_base/iostate, letzter Zugriff: 5.12.2017).
 *
 * Ob dieses Bit gesetzt ist, können Sie mit Hilfe der Methode fail
 * (vgl. http://en.cppreference.com/w/cpp/io/basic_ios/fail, letzter Zugriff: 5.12.2017)
 * abfragen. In diesem Fall können Sie mit den Aufrufen
 *    cin.clear();
 *    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 * das failbit wieder löschen und den Eingabepuffer leeren.
 *
 * - Implementieren Sie (noch ohne Exceptions) ein Bespielprogramm,
 *   bei dem der Nutzer so lange immer wieder aufgefordert wird, eine ganze
 *   Zahl einzugeben, bis er dies tatsächlich tut.
 * - Identifizieren Sie die Anteile „Fehlererkennung“, „Fehlermeldung“
 *   und „Fehlerbehandlung“ in Ihrem Programm.
 *
 * cin kann nun so konfiguriert werden, dass beim Setzen des failbits
 * eine Ausnahme geworfen wird.
 *
 * - Konfigurieren Sie cin mit der Methode exceptions
 *   (vgl. http://en.cppreference.com/w/cpp/io/basic_ios/exceptions, letzter Zugriff: 5.12.2017)
 *   so, dass beim Setzen des failbits eine Ausnahme geworfen wird.
 * - Ändern Sie Ihr Programm so ab, dass die Fehlerbehandlung mit Exceptions
 *   erfolgt!
 *
 * Mit Ihrem Programm sollen nun zwei ganze Zahlen eingelesen werden,
 * die dividiert werden sollen.
 * - Erweitern Sie Ihr Programm um eine Funktion dividiere, die eine
 *   Ausnahme bei einer Division durch 0 wirft und sonst das Ergebnis
 *   der ganzzahligen Division zurückgibt.
 * - Fangen Sie die Ausnahme im Hauptprogramm in geeigneter Art und Weise ab!
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 * 5.12.2017
 */

/* ----- INCLUDES ----- */
#include <iostream>
#include <limits>
using namespace std;

/* ----- FUNKTION ----- */
// gibt den ganzzahligen Quotienten dividend/divisor zurueck, falls
// divisor != 0
// Fuer den Fall divisor == 0 wird eine Ausnahme geworfen
int dividiere(int dividend, int divisor)
{
    if (divisor == 0)
        throw "Teilen durch 0 ist nicht erlaubt!";
    return dividend/divisor;
}

/* ----- HAUPTPROGRAMM ----- */
int main()
{
    int dividend = 0;
    int divisor  = 0;

    // --------------------------------------------
    // -- Eingabe des Dividenden ohne Exceptions --
    // --------------------------------------------
    while(1) {
        cout << "Dividend eingeben: ";
        cin >> dividend;
        if (cin.fail()) { // Fehlererkennung
            cerr << "FEHLER! Das war keine ganze Zahl!" << endl; // Fehlermeldung
            cin.clear(); // Fehlerbehandlung (in Kombination mit ignore und Schleife)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else { // kein Fehler aufgetreten -> Schleife verlassen.
            break;
        }
    }
    cout << "Dividend: " << dividend << endl;

    // -----------------------------------------
    // -- Eingabe des Divisors mit Exceptions --
    // -----------------------------------------
    cin.exceptions(std::istream::failbit); // Werfen von Exceptions aktivieren
    while(1) {
        try {
            cout << "Divisor eingeben: ";
            cin >> divisor;
            break; // kein Fehler aufgetreten -> Schleife verlassen.
        }
        catch(const exception &e)
        {
            cerr << "FEHLER! Das war keine ganze Zahl! " << e.what() << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    cout << "Divisor: " << divisor << endl;

    // ---------------------------
    // -- Division durchfuehren --
    // ---------------------------
    try {
        cout << "Quotient: " << dividiere(dividend, divisor) << endl;
    }
    catch(const char *msg) {
        cerr << "FEHLER! " << msg << endl;
    }

    return 0;
}

