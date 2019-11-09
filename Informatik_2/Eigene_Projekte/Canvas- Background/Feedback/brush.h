#ifndef BRUSH_H
#define BRUSH_H

#include "color.h"
//#include "background.h"

class Brush
{
public:
    Brush();
    Color *schwarz;
    unsigned int getWidth();
    unsigned int getHeight();
    void setColor(Color *pc);
    void getColor(Color *pc);
    bool drawsAt(unsigned int row, unsigned int col);

private:
    unsigned int m_width;
    unsigned int m_height;



};

#endif // BRUSH_H
