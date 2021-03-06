#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "color.h"

class Background
{
private:
    unsigned int size_x;
    unsigned int size_y;
    unsigned int arraylength;
    uint8_t *pixelval;

public:
    Color m_Farbe;
    void paint();
    void save(Background);
    void drawline(int startrow = 50, int endrow = 50, int startcol = 50, int endcol = 150, std::string namePinselfarbe = "schwarz");
    void setPixel(int row, int col, Color Pinselfarbe);
    int saveAsBmp(uint8_t bilddaten[], int b, int h);
    int saveAsPpm(uint8_t bilddaten[], int b, int h);
    Background(std::string color = "blue", int laenge = 300, int breite = 200); // CM: Das "std::" ist nur nötig, wenn kein "using namespace std;" oben steht. Da das eher in die cpp soll, bitte lassen :-)
    Background(int red, int green, int blue, int laenge, int breite);
    Background();
    ~Background();


    unsigned int getSize_x() const
    {
        return this->size_x;
    }
    unsigned int getSize_y() const
    {
        return this->size_y;
    }
};

#endif // BACKGROUND_H
