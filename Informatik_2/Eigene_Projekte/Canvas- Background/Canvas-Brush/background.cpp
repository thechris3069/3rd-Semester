#include "background.h"

using namespace std;

Background::Background(std::string color, int laenge, int breite)
    :m_Farbe(color), size_x(breite), size_y(laenge), arraylength(laenge* breite * 3)
{
    pixelval = new uint8_t[arraylength];
    paint();
}

void Background::save()
{
    saveAsBmp(pixelval, getSize_x(), getSize_y());
    saveAsPpm(pixelval, getSize_x(), getSize_y());
}

Background::Background()
    :m_Farbe("blue") , size_x(200), size_y(300), arraylength(size_x*size_y*3)
{
    paint();
}

Background::Background(int red, int green, int blue, int laenge, int breite)
    :m_Farbe(red, green, blue) , size_x(breite), size_y(laenge), arraylength(size_x*size_y*3)
{
paint();
}

Background::~Background()
{
//    delete pixelval; // Nicht nötig?
    // Macht der das von selber?
}

void Background::paint()
{
    for(int i = 0; i < arraylength; ++i)
    {
        switch (i % 3){
        case 0:
            pixelval[i] = m_Farbe.getRed();
            break;

        case 1:
            pixelval[i] = m_Farbe.getGreen();
            break;

        case 2:
            pixelval[i] = m_Farbe.getBlue();
            break;
        }
    }
}

void Background::drawline(int startrow, int endrow, int startcol, int endcol, std::string name_Pinselfarbe)
{

    Color Pinselfarbe(name_Pinselfarbe);
    for(int row = startrow; row <= endrow; ++row)
    {
        for(int col = startcol; col <=endcol; ++col)
        {
            setPixel(row, col, Pinselfarbe);
        }
    }
}

void Background::waehlePinsel(Brush *Pinsel)
{
    if(Pinsel == nullptr)
        m_currenBrush = &schmallerPinsel;
    else
        m_currenBrush = Pinsel;

}

void Background::malemitFarbe(Color *Farbe)
{
    if(Farbe == nullptr)
    m_currentColor = &m_Farbe;
    else
    m_currentColor = Farbe;
}

void Background::setPixel(int row, int col, Color Pinselfarbe)
{
    pixelval[(row*size_x+col)*3+0] = Pinselfarbe.getRed();
    pixelval[(row*size_x+col)*3+1] = Pinselfarbe.getGreen();
    pixelval[(row*size_x+col)*3+2] = Pinselfarbe.getBlue();

}

// CM: Sie könnten die Funktionen auch als Methoden in die Klasse integrieren (siehe https://git.etech.fh-augsburg.de/claudia.meitinger/informatik2/tree/master/canvas). Dann wäre die Funktionalität nch etwas schöner gekapselt und der "save"-Aufruf im Hauptprogramm noch einfacher für den Benutzer.
/* Funktion, die RGB-Daten eines Bildes der Breite b und Hoehe h, die
 * in einem eindimensionalen Feld bilddaten der Groesse b*h*3 hinterlegt sind (siehe oben),
 * im BMP-Format als Datei test.bmp abspeichert
 */
int Background::saveAsBmp(uint8_t bilddaten[], int b, int h)
{
    // Formatbeschreibung siehe https://en.wikipedia.org/wiki/BMP_file_format
    // letzter Zugriff: 11.9.2019

    ofstream f("test.bmp", ios::binary);

    // BMP Header
    f.put(0x42); f.put(0x4D); // ID field
    uint32_t size = 54 + b * h * 3 + h * ((4 - (b * 3) % 4) % 4); // BMP file size: 54 Bytes Header + 3 Bytes pro Pixel
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    for (unsigned int i = 0; i < 4; ++i) // unused
        f.put(0x00);
    uint32_t offset = 54;  // offset of pixel array = header size = 54 Bytes
    for (unsigned int i = 0; i < 4; ++i)
        f.put((offset >> i*8) & 0xFF);

    // DIB Header
    size = 40; // DIB header size
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    size = b; // width of image
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    size = -h; // height of image (negative for top to bottom)
    for (unsigned int i = 0; i < 4; ++i)
        f.put((size >> i*8) & 0xFF);
    f.put(0x01); f.put(0x00); // 1 color plane
    f.put(0x18); f.put(0x00); // 24 bits per pixel
    for (unsigned int i = 0; i < 4; ++i) // no pixel array compression
        f.put(0x00);
    f.put(0x10); f.put(0x00); f.put(0x00); f.put(0x00); // 16 Bits per pixel (incl. paddding)
    f.put(0x13); f.put(0x0b); f.put(0x00); f.put(0x00); // print resolution hor
    f.put(0x13); f.put(0x0b); f.put(0x00); f.put(0x00); // print resolution ver
    for (unsigned int i = 0; i < 4; ++i) // no colour palette
        f.put(0x00);
    for (unsigned int i = 0; i < 4; ++i) // no important colours
        f.put(0x00);

    // image data
    for (unsigned int row = 0; row < h; ++row) {
        for (unsigned int col = 0; col < b; ++col) {
            f.put(bilddaten[(row*b + col)*3 + 2]);
            f.put(bilddaten[(row*b + col)*3 + 1]);
            f.put(bilddaten[(row*b + col)*3 + 0]);
        }
        // padding (jede Zeile Vielfaches von 4 Bytes)
        for (unsigned int i = 0; i < (4 - (b * 3) % 4) % 4; ++i)
            f.put(0x00);
    }
    return 0;
}

int Background::saveAsPpm(uint8_t bilddaten[], int b, int h)
{
    // Formatbeschreibung siehe https://en.wikipedia.org/wiki/Portable_Graymap_File_Format
    // letzter Zugriff: 11.9.2019

    ofstream f("test.ppm");
    if (!f) {
        cerr << "Datei konnte nicht geoeffnet werden!" << endl;
        return -1;
    }

    f << "P3" << endl; // magic number fuer PPM im ASCII Format
    f << b << " " << h << endl; // Breite und Hoehe in Anzahl Pixeln
    f << "255" << endl; // maximaler Wert pro R, G, B-Wert

    for (unsigned int row = 0; row < h; ++row) {
        for (unsigned int col = 0; col < b; ++col) {
            f << static_cast<unsigned int>(bilddaten[(row*b + col)*3 + 0]);
            f << " ";
            f << static_cast<unsigned int>(bilddaten[(row*b + col)*3 + 1]);
            f << " ";
            f << static_cast<unsigned int>(bilddaten[(row*b + col)*3 + 2]);
            f << " ";
        }
        f << endl;
    }
    return 0;
}
