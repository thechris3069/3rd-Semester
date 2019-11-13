#ifndef BRUSH_H
#define BRUSH_H

#include <iostream>

#include "color.h"

class Brush
{
public:
    Brush(int groesseX = 1, int groesseY = 1);
    int getWidth()
    {return m_xgroesse;
    }
    int getHeight()
    {
        return m_ygroesse;
    } 
    const int m_xgroesse, m_ygroesse;
};

#endif // BRUSH_H
