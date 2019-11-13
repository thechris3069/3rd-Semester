#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "brush.h"
#include "color.h"

class Background
{
private:
    unsigned int size_x;
    unsigned int size_y;
    unsigned int arraylength;
    uint8_t *pixelval;
    void setPixel(int row, int col);
    int saveAsBmp(uint8_t bilddaten[], int b, int h);
    int saveAsPpm(uint8_t bilddaten[], int b, int h);
protected:
           Brush *m_currenBrush;
           Brush schmallerPinsel;
           Color *m_Std_Farbe = new Color(0,255,0);       //Hier funktioniert nur der StandardKonstruktor Fehler bei Color m_Std_Farbe(1,0,1)
           Color *m_currentColor = nullptr;               //std_Farbe als std currentColor
public:
    void paint(); // wird nur bei maleHintergrund aufgerufen
    void save(); // ruft beide save Funktions auf, save as bmp und ppm
    void drawline(int startrow = 50, int endrow = 50, int startcol = 50, int endcol = 150);
    void malemitFarbe(Color *Farbe);
    void malemitFarbe();
    void waehlePinsel(Brush *Pinsel = nullptr);
    Background(Color *color = nullptr, int laenge = 300, int breite = 200);
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
