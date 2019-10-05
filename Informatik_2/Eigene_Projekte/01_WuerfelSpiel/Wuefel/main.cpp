#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Wuerfel {
private:
    std::string w_Farbe;
    unsigned int maxZahl;
    unsigned int aktZahl;

public:
      Wuerfel(std::string farbe = "lila", unsigned  int max = 6);
     ~Wuerfel();
     void wuerfeln();
     unsigned int anzeigen();
     unsigned int getZahl()
     {
         return aktZahl;
     }

};

Wuerfel::Wuerfel(std::string farbe,unsigned int max)
//    :w_Farbe(farbe), maxZahl(max)
{
    w_Farbe = farbe;
    maxZahl = max;

}

Wuerfel::~Wuerfel()
{
    cout << "Destruktor aufgerufen" << endl;
}

int main()
{
    string var = "rot";
    Wuerfel w1(var, 10);
//    Wuerfel w2();
    srand(time(0));

    cout << "Hello World!" << endl;
    return 0;
}
