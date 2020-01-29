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

int fakultaet(int zahl)
{
    int ergebnis = 0;
    if(zahl <= 1)
    {
        ergebnis = ergebnis +1;
    }
    else
    {
        ergebnis = zahl * fakultaet(zahl -1);
    }
    return ergebnis;
}

int summe(int zahl)
{
    int ergebnis = 0;
    if (zahl <= 1)
    {
        ergebnis = 1;
    }
    else
    {
        ergebnis = zahl + summe(zahl -1);
    }
    return ergebnis;
}



void permutation ( char feld [], int n)
{
    char temp ;
    if (n == 1) {
        cout << " Kombination : " << feld << endl ;
    }
    else {
        permutation (feld , n -1);
        for ( int i = n -2; i >= 0; i --) {
            temp = feld [n -1];
            feld [n -1] = feld [i];
            feld [i] = temp ;
            permutation (feld , n -1);
            temp = feld [n -1];
            feld [n -1] = feld [i];
            feld [i] = temp ;
        }
    }

}


int main()
{
    int zahl1 = 5;
    int zahl2 = 3;

    char pin [] = {'3', '5', '8', '\0'};
    permutation (pin , 3);

    int zahl3 = funk(zahl1, zahl2);
//    int zahl3 = fakultaet(zahl1);
//    int zahl3 = summe(zahl1);
    cout << zahl3 << endl;
    return 0;
}

