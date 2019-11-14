#include "brush.h"

Brush::Brush(int groesseX, int groesseY)
    :m_xgroesse(groesseX), m_ygroesse(groesseY)
{
    m_currentColor = nullptr;
}

void Brush::malemitFarbe(Color *Farbe)
{
    if(Farbe == nullptr)
    m_currentColor = m_Std_Farbe;
    else
    m_currentColor = Farbe;
}

void Brush::setFarbe(Color *farbe)
{
    m_currentColor = farbe;
}

void Brush::getFarbe()
{
    if(m_currentColor == nullptr)
    {
        m_currentColor = m_Std_Farbe;
    }
}

void Brush::malemitFarbe()
{
    if (m_currentColor != nullptr) {return;} //Abfrage ändern, funktioniert nicht
    else
        m_currentColor = m_Std_Farbe;
}
