#ifndef BRUSH_H
#define BRUSH_H

#include <iostream>

#include "color.h"

class Brush
{
public:
    Color *m_Std_Farbe = new Color(0,255,0);       //Hier funktioniert nur der StandardKonstruktor Fehler bei Color m_Std_Farbe(1,0,1)
    Color *m_currentColor = nullptr;               //std_Farbe als std currentColor
    Brush(int groesseX = 1, int groesseY = 1);
    void malemitFarbe();
    void malemitFarbe(Color *Farbe);
    void getFarbe();
    void setFarbe(Color *farbe);
    bool drawAt(int col, int row, int val);
    int getBrushWidth()
    {return m_xgroesse;
    }
    int getBrushHeight()
    {
        return m_ygroesse;
    } 
    const int m_xgroesse, m_ygroesse;

};

#endif // BRUSH_H
