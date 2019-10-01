// Beispiel zum Ueberladen von Funktionen
// Claudia Meitinger
// -> Vorlesung 19.3.2019

#include <iostream>
#include <cstring>
using namespace std;

int min(int a, int b)
{
    cout << "min fuer zwei int" << endl;
    if (a <= b)
        return a;
    return b;
}

double min(double a, double b)
{
    cout << "min fuer zwei double" << endl;
    if (a <= b)
        return a;
    return b;
}

double min(double a, double b, double c)
{
    cout << "min fuer drei double" << endl;
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    return c;
}

const char *min(const char *a, const char *b)
{
    cout << "min fuer zwei Zeichenketten" << endl;
    if (strcmp(a, b) < 0)
        return a;
    return b;
}

int main()
{
    cout << min(3, 5) << endl;
    cout << min("Hallo", "Anna") << endl;
    cout << min(27.11, 22.5) << endl;
    cout << min(27.11, 22.5, 19.4) << endl;
//  cout << min("a", 'b') << endl;
//  cout << min(27.11, 22) << endl;

    return 0;
}


