#include "wuerfelbecher.h"

Wuerfelbecher::Wuerfelbecher()
{
std::cout << "Konstruktor von Wuerfelbecher" << std::endl;
}

Wuerfelbecher::~Wuerfelbecher()
{
std::cout << "Destruktor von Wuerfelbecher" <<std::endl;
}

void Wuerfelbecher::einwerfen(Wuerfel *p_Wuerfel)
{
    for(int i = 0 ; i < ANZAHL; ++i)
        if(m_Wuerfel[i] = nullptr)
    m_Wuerfel[i] = p_Wuerfel;
    p_Wuerfel->wuerfeln();
    p_Wuerfel->anzeigen();
//    auswerfen();
}

void Wuerfelbecher::auswerfen()
{
    for(int i = 0; i < ANZAHL; ++i)
    {m_Wuerfel[i] = nullptr;
    }

}
