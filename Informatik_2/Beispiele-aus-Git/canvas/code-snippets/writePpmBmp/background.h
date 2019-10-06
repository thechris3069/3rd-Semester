#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>

using namespace std; // NAMESPACE IN DEN HEADER ODER INS CPP FILE?

class Background
{
private:

    string b_color;
    unsigned int arraylength;
    unsigned int size_x;
    unsigned int size_y;


    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t pixelval[200*300*3];
    void setcolor();
    void paint();


public:


    Background(std::string color);
    Background();
    uint8_t * getarray()
    {
        return this->pixelval;
    }
    unsigned int getSize_x()
    {
        return this->size_x;
    }
    unsigned int getSize_y()
    {
        return this->size_y;
    }
    ~Background();

};

#endif // BACKGROUND_H
