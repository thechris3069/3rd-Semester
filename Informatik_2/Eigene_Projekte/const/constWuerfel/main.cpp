#include <iostream>


#include "wuefel.h"

using namespace std;

int main()
{
    Wuefel wuefel1;
    cout << wuefel1.zeigeZahl() <<endl;
    wuefel1.wuerfeln();
    cout << wuefel1.zeigeZahl() <<endl;
    cout << "Hello World!" << endl;
    return 0;
}
