#include "brush.h"

Brush::Brush(int groesseX, int groesseY)
    :m_xgroesse(groesseX), m_ygroesse(groesseY)
{

}

void Brush::malemitFarbe(Color *Farbe)
{
    if(Farbe == nullptr)
    m_currentColor = m_Std_Farbe;
    else
    m_currentColor = Farbe;
}

void Brush::malemitFarbe()
{
    if (m_currentColor != nullptr) {return;}
    else
        m_currentColor = m_Std_Farbe;
}
