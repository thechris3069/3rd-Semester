#include "wuefel.h"

Wuefel::Wuefel()
    :maxZahl(6), aktZahl(2)
{
    std::srand(time(nullptr));
    wuerfeln();

}

Wuefel::~Wuefel()
{

}

void Wuefel::wuerfeln()
{
    aktZahl = std::rand() % 6 +1;

}

int Wuefel::zeigeZahl() const
{
    return aktZahl;

}
