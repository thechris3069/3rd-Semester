#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>

#include "brush.h"
#include "color.h"

class Background
{
private:
    unsigned int size_x;
    unsigned int size_y;
    unsigned int arraylength;
    uint8_t *pixelval;
    void setPixelWithBrush(int row, int col);

    void setPixel(int row, int col, Color c);
    int saveAsBmp(uint8_t bilddaten[], int b, int h);
    int saveAsPpm(uint8_t bilddaten[], int b, int h);
    int berechnealphafarbe(int alterFarbwert, int FarbevonPinsel, int alphavonPinsel);
public:
    Brush *m_currenBrush = nullptr;
    Brush m_stdPinsel;
    void setPinsel(Brush *Pinsel = nullptr);
    Brush* getPinsel();
    Background(Color *color = nullptr, int laenge = 300, int breite = 200);
    Background(int red, int green, int blue, int laenge, int breite);
    Background();
    ~Background();
void zeichneLinie(int x, int y, int laenge, int winkel);
    void paint(Color *c); // wird nur bei maleHintergrund aufgerufen
    void save(); // ruft beide save Funktions auf, saveasbmp und saveasppm
    void drawline(int startrow = 50, int endrow = 50, int startcol = 50, int endcol = 150);
    void drawlineWinkel(int startx, int starty, int laenge, double winkel);
//    void waehlePinsel(Brush *Pinsel);
//    void waehlePinsel();
    unsigned int getSize_x() const
    {    return this->size_x;}
    unsigned int getSize_y() const
    {return this->size_y;}
};
#endif // BACKGROUND_H
