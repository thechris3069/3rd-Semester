/*
 * Die Summe aller ganzen Zahlen von 1 bis n soll mit einem rekursiven
 * Algorithmus berechnet werden. Implementieren Sie eine entsprechende
 * Funktion!
 * Wie koennte eine iterative Variante aussehen?
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 * 21.11.2017
 */

// ----- INCLUDES -----
#include <iostream>
using namespace std;

// ----- FUNKTIONEN -----
/*
 * Rekursive Funktion, die die Summe aller ganzen Zahlen
 * zwischen 1 und der uebergebenen Zahl bildet und zurueckgibt
 */
unsigned int summeRekursiv(unsigned int zahl)
{
    unsigned int ergebnis = 0;

    if (zahl <= 1) // Trivialer Fall
    {
        ergebnis = 1;
    }
    else // Rekursionsfall
    {
        ergebnis = zahl + summeRekursiv(zahl-1);
    }

    return ergebnis;
}

/*
 * Iterative Funktion, die die Summe aller ganzen Zahlen
 * zwischen 1 und der uebergebenen Zahl bildet und zurueckgibt
 */
unsigned int summeIterativ(unsigned int zahl)
{
    unsigned int ergebnis = 0;

    for (unsigned int i = 0; i <= zahl; ++i)
        ergebnis += i;

    return ergebnis;
}

// ----- HAUPTPROGRAMM -----
int main()
{
    unsigned int zahl;
    cout << "Positive Zahl eingeben: ";
    cin >> zahl;

    cout << "Die Summe der Zahlen von 1 bis " << zahl << " lautet: ";
    cout << summeIterativ(zahl);
    cout << " bzw. ";
    cout << summeRekursiv(zahl);
    cout << "." << endl;

    return 0;
}

