#ifndef WUEFEL_H
#define WUEFEL_H

#include <cstdlib>
#include "ctime"


class Wuefel
{
public:
    Wuefel();
    ~Wuefel();
        void wuerfeln();
    int zeigeZahl () const;

private:

    int maxZahl;
    int aktZahl;

};

#endif // WUEFEL_H
