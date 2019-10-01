// Beispiel zu Namensraeumen aus Skript Informatik 2
// Claudia Meitinger
// -> Vorlesung 19.3.2019

#include <iostream>
using namespace std;

namespace Augsburg
{
    unsigned int einwohner = 286000;
    void hallo()
    {
        cout << "Hallo aus Augsburg!" << endl;
    }
}

namespace Muenchen
{
    unsigned int einwohner = 1545000;
    void hallo()
    {
        cout << "Hallo aus Muenchen!" << endl;
    }
}

using namespace Augsburg;

int main()
{
    cout << "Augsburg: " << einwohner << '\n';
    cout << "Muenchen: " << Muenchen::einwohner << '\n';
    hallo();
    Muenchen::hallo();

    return 0;
}
