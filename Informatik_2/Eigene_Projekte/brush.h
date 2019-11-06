#ifndef BRUSH_H
#define BRUSH_H


class Brush
{
public:
    Brush();
    ~Brush();
   unsigned int getWidth();
   unsigned int getHeight();
   void setColor(Colour *pc);
   Colour* getColour();
   bool drawsAt(unsigned int row, unsigned int col);
   private:
   unsigned int m_width;
   unsigned int m_height;

};

#endif // BRUSH_H
