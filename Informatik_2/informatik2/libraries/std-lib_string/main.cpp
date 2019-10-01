// Beispiel zur Nutzung der Klasse string aus der C++-Standardbibliothek
// Claudia Meitinger
// -> Vorlesung 19.3.2019

#include <iostream>
using namespace std;

int main()
{
    string name;

    name = "Claudia";
    cout << name << endl;

    name.append(" Meitinger");
    cout << name << endl;

    cout << "Laenge des Namens: " << name.size() << endl;

    return 0;
}

