#ifndef BRUSH_H
#define BRUSH_H

#include <iostream>

#include "color.h"

class Brush
{
public:
    Brush(int groesseX = 1, int groesseY = 1);
   Color standardFarbe;
   Color* jetzigeFarbe;
    int getWidth()
    {return m_xgroesse;
    }
    int getHeight()
    {return m_ygroesse;
    }
    void setColor(Color *pc)
    {
    jetzigeFarbe = pc;
    }
//    Color * getColor()
//    {

//    }

     void drawAt(int startrow, int endrow, int startcol, int endcol, std::string name_Pinselfarbe);
    void drawAt(int startrow, int endrow, int startcol, int endcol, Color m_farbe);
private:
    int m_xgroesse, m_ygroesse;

};

#endif // BRUSH_H
