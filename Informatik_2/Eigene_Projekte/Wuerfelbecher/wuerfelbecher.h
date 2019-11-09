#ifndef WUERFELBECHER_H
#define WUERFELBECHER_H
#include <iostream>
#include "wuerfel.h"
#define ANZAHL 5


class Wuerfelbecher
{
public:
    Wuerfelbecher();

    ~Wuerfelbecher();
    void einwerfen(Wuerfel *p_Wuerfel = nullptr);
    void auswerfen();
private:
    Wuerfel *m_Wuerfel[ANZAHL]{nullptr};
};

#endif // WUERFELBECHER_H
