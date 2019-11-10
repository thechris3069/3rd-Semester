#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "brush.h"


using namespace std; // NAMESPACE IN DEN HEADER ODER INS CPP FILE?

class Background
{
private:

    string b_color;
    unsigned int size_x;
    unsigned int size_y;
    unsigned int arraylength;



    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t pixelval[200*300*3];
    void setcolor();
    void paint();


public:
Brush stdPinsel;
int saveAsPpm(uint8_t bilddaten[], int b, int h);
int saveAsBmp(uint8_t bilddaten[], int b, int h);
    Background(std::string color);
    Background();
    ~Background();

    uint8_t * getarray()
    {
        return pixelval;
    }
    unsigned int getSize_x()
    {
        return size_x;
    }
    unsigned int getSize_y()
    {
        return size_y;
    }


};

#endif // BACKGROUND_H
