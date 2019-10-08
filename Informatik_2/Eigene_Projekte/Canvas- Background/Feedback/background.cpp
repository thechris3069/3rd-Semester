#include "background.h"



Background::Background(std::string color = "blue")
    :b_color(color), size_x(200), size_y(300), arraylength(200 * 300 *3) // CM: siehe .h: DEFINES würden eine Wiederholung der Zahlen vermeiden :-)
{
    setcolor();
}

Background::Background()
    :b_color("blue"), size_x(200), size_y(300), arraylength(size_x*size_y*3)
{
    setcolor();
}
Background::~Background()
{

}
void Background::setcolor()
{

    if(this->b_color == "red")
    {
        this->r = 255;
        this->g = 0;
        this->b = 0;
    }
    else if (this->b_color == "yellow")
    {
        this->r = 255;
        this->g = 204;
        this->b = 0;
    }
    else
    {
        this->b_color = "blue";
        this->r = 0;
        this->g = 100;
        this->b = 240;
    }
    this->paint();
}

void Background::paint()
{
    for(int i = 0; i < arraylength; ++i)
    {
        switch (i % 3){
        case(0): // CM: Klammern sind hier unüblich
            this->pixelval[i] = this->r;
            break;

        case(1):
            this->pixelval[i] = this->g;
            break;

        case(2):
            this->pixelval[i] = this->b;
            break;
        }
    }
}
