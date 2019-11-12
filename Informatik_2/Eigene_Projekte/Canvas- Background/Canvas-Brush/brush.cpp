#include "brush.h"

Brush::Brush(int groesseX, int groesseY)
    :m_xgroesse(groesseX), m_ygroesse(groesseY)
{

}

 void Brush::drawAt(int startrow, int endrow, int startcol, int endcol, Color m_Farbe)
 {
     for(int row = startrow; row <= endrow; ++row)
     {
         for(int col = startcol; col <=endcol; ++col)
         {
//             setPixel(row, col, standardFarbe);
         }
     }
 }

 void Brush::drawAt(int startrow, int endrow, int startcol, int endcol, std::string name_Pinselfarbe)
 {
     Color Pinselfarbe(name_Pinselfarbe);
//     drawline(int startrow, int endrow, int startcol, int endcol, Color = standardFarbe);
     for(int row = startrow; row <= endrow; ++row)
     {
         for(int col = startcol; col <=endcol; ++col)
         {
//             setPixel(row, col, Pinselfarbe);
         }
     }
 }
