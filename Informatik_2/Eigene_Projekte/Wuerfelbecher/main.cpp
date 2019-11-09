#include <iostream>
#include "wuerfel.h"
#include "wuerfelbecher.h"
#include <cstdlib>
#include <time.h>


using namespace std;

int main()
{
    srand(time(NULL));
    Wuerfelbecher m_Wuerfelbecher;
    Wuerfel w1[1];
//    Wuerfel *pW = new Wuerfel("blau", 10);
//    Wuerfel *pNochFuenf = new Wuerfel[5] { {"blau", 5}, {"blau", 5}, {"blau", 5}, {"blau", 5}, {"blau", 5} };
    Wuerfel w2("blau, 5");
    int size = sizeof(w1)/sizeof(Wuerfel);
    for(int j = 0; j< 30; j++)
    {
    for(int i = 0;i < size; ++i)
    {
        m_Wuerfelbecher.einwerfen(&w1[i]);
    }
//    Wuerfel *pWuerfel = new Wuerfel[5];

    m_Wuerfelbecher.einwerfen(&w2);
   // m_Wuerfelbecher.einwerfen(w2);
m_Wuerfelbecher.auswerfen();
    }
    cout << "Hello World!" << endl;
//    delete pW ;
    return 0;
}
