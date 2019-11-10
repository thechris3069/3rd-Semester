#include "brush.h"
#include "background.h"


Brush::Brush()
    :m_width(30), m_height(30)
{

}

void Brush::setColor(Color *pc)
{

}

void Brush::getColor(Color *pc)
{

}

bool Brush::drawsAt(unsigned int row, unsigned int col)
{
        for(int i = row -m_width/2; i < (row + m_width/2); ++i)
        {
            switch (i % 3){
            case(0): // CM: Klammern sind hier unüblich
                = Color.red;
                Background::pixelval[i] = Color.red;
                break;

            case(1):
                 pixelval[i] = Color.green;
                break;

            case(2):
                this->pixelval[i] = Color.blue;
                break;
            }
        }
}

