#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include "brush.h"
#include <fstream>
#include <cstdlib>

// CM: #include <string> (fuer string) ergänzen

using namespace std; // NAMESPACE IN DEN HEADER ODER INS CPP FILE? // CM: CPP

class Background
{
private:

    string b_color;
    unsigned int size_x;
    unsigned int size_y;
    unsigned int arraylength;


    uint8_t r; // CM: <- Was sollen diese drei Werte?
    uint8_t g;
    uint8_t b;
//    uint8_t pixelval[200*300*3]; // CM: Falls variable Größe des Bildes verwendet werden soll, steht hier nur die Startadresse des Feldes: uint8_t *pixelval;
    // CM: Sie könnten auch mit DEFINES für die Zahlen arbeiten :-)
    void setcolor();
public:
    Brush dreiBreit;
    uint8_t pixelval[200*300*3];
    void paint();
    int saveAsBmp(uint8_t bilddaten[], int b, int h);
    int saveAsPpm(uint8_t bilddaten[], int b, int h);




    Background(std::string color); // CM: Das "std::" ist nur nötig, wenn kein "using namespace std;" oben steht. Da das eher in die cpp soll, bitte lassen :-)
                                   // CS: Was soll ich lassen? Die Farbe wird als String übergeben?
    Background();
    ~Background();

    uint8_t * getarray() // CM: unnötig, wenn save-Methdoen in der Klasse sind. So öffnen Sie durch Rückgabe der Startadresse des Feldes unkontrolliert den Zugriff auf den Bildinhalt.
                         // CS: Angenommen die Funktion ist nicht teil der Klasse, sondern aus einer anderen Library, dann eine Kopie des Feldes Übergeben? Wie Übergebe ich ein Feld als Kopie?
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
     // CS: Übergabe ist call by pointer, call by value wäre dann?? oder als static übergeben, also read only? oder ist es const??


};

#endif // BACKGROUND_H
