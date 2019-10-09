#ifndef WUERFEL_H
#define WUERFEL_H

#include <cstdlib>
#include<iostream>
#include <ctime>

class Wuerfel {
private:
    std::string w_Farbe;
    unsigned int maxZahl{20};
    unsigned int aktZahl{10};

public:
      Wuerfel(std::string farbe = "lila", unsigned  int max = 6);
     ~Wuerfel();
     void wuerfeln();
     void anzeigen();
     unsigned int getZahl(int *);
     unsigned int getZahl()  // INLINE PROGRAMMIERUNG IM HEADER????
     {
         return aktZahl;
     }

};

#endif // WUERFEL_H
