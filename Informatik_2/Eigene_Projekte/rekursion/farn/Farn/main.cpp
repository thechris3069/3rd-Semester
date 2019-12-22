#include <iostream>

using namespace std;

int funk (int a, int b)
{
    if (!b)
    {
        return 0;
    }
    else if(b > 0)
    {

        return a + funk(a, b-1);

    }
    else
    {
        return a + funk(a, b+1);
    }
}

int main()
{
    int zahl1 = 5;
    int zahl2 = -6;
    int zahl3 = funk(zahl1, zahl2);
    cout << zahl3 << endl;
    return 0;
}
