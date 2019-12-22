#include "background.h"

using namespace std;

Background::Background(Color *color, int laenge, int breite)
    :size_x(breite), size_y(laenge), arraylength(laenge* breite * 3)
{
      m_currenBrush = nullptr;
    Color *hintergrundfarbe = color;
    pixelval = new uint8_t[arraylength];
    paint(hintergrundfarbe);
}

void Background::zeichneLinie(int x, int y, int laenge, int winkel)
{
    drawlineWinkel(x, y, laenge, winkel);
    if(laenge < 5)
    {
        return;
    }
    else
    {
        zeichneLinie(x - cos(winkel) *laenge,y - sin(winkel) *laenge, laenge *0.7, winkel + M_PI/8);
        zeichneLinie(x - cos(winkel) *laenge,y - sin(winkel) *laenge, laenge *0.7, winkel - M_PI/8);
        zeichneLinie(x - cos(winkel) *laenge,y - sin(winkel) *laenge, laenge *0.7, winkel);
    }
}

Background::Background()
    :size_x(200), size_y(300), arraylength(size_x*size_y*3)
{
    m_currenBrush = nullptr;
    Color c;
    paint(&c);
}

Background::Background(int red, int green, int blue, int laenge, int breite)
    :size_x(breite), size_y(laenge), arraylength(size_x*size_y*3)
{
      m_currenBrush = nullptr;
    Color m_currentColor(red, green, blue);
    paint(&m_currentColor);
}

int Background::berechnealphafarbe(int alterFarbwert, int FarbevonPinsel, int alphavonPinsel)
{
    int neuefarbe = alterFarbwert*alphavonPinsel/255 + FarbevonPinsel*(255- alphavonPinsel)/255;
    return neuefarbe;
}


Background::~Background()
{
    delete[] pixelval;
}

void Background::paint(Color *c)
{
    for(unsigned int i = 0; i < arraylength; ++i)
    {
        switch (i % 3){
        case 0:
            pixelval[i] = c->getRed();
            break;
        case 1:
            pixelval[i] = c->getGreen();
            break;
        case 2:
            pixelval[i] = c->getBlue();
            break;
        }
    }
}



void Background::drawline(int startrow, int startcol, int endrow, int endcol)
{
    m_currenBrush = getPinsel();
    m_currenBrush->malemitFarbe();


       int deltay = endcol - startcol;
               int deltax = endrow - startrow;
       int dist = static_cast<int> (sqrt((pow(deltay, 2))+ pow(deltax, 2)));
       int maleany;

for(int i = 0; i < dist; ++i)
{
   int  col = startcol + (deltax*i)/dist;
    int row = startrow + (deltay*i)/dist ;
setPixelWithBrush(row, col);
}
}

void Background::drawlineWinkel(int startx, int starty, int laenge, double winkel)
{
    m_currenBrush = getPinsel();
    m_currenBrush->malemitFarbe();

    int radWinkel = winkel*M_PI /180;

    for(int i = 0; i < laenge; ++i)
    {
        double neuesx = startx + cos(winkel) *i;
        double neuesy = startx + sin(winkel) *i;
        setPixelWithBrush(neuesy, neuesx);
    }
}


void Background::setPinsel(Brush *Pinsel)
{
    if (Pinsel == nullptr)
    {
        m_currenBrush = &m_stdPinsel;
    }
    m_currenBrush = Pinsel;
}

Brush* Background::getPinsel()
{
    if (m_currenBrush == nullptr)
        m_currenBrush = &m_stdPinsel;
    return m_currenBrush;
}


void Background::setPixel(int row, int col, Color c)
{

    pixelval[(row*size_x+col)*3+0] = berechnealphafarbe(pixelval[(row*size_x+col)*3+0], c.getRed(), c.getalpha());
    pixelval[(row*size_x+col)*3+1] =  berechnealphafarbe(pixelval[(row*size_x+col)*3+1], c.getGreen(), c.getalpha());
    pixelval[(row*size_x+col)*3+2] =  berechnealphafarbe(pixelval[(row*size_x+col)*3+2], c.getBlue(), c.getalpha());
}

void Background::setPixelWithBrush(int row, int col) //TODO: noch ausarbeiten
{
//Zugriff sicherstelleen, dass im feld geschrieben weird

    int brushHoehe =  m_currenBrush->getBrushHeight();
    int brushBreite =  m_currenBrush->getBrushWidth();
    int maleanPositionCol = col - brushHoehe/2;
    int maleanPositionRow = row -brushBreite/2;
    for(int aktuellebreite = 0; aktuellebreite < brushBreite; aktuellebreite++)
    {
        if((maleanPositionCol+aktuellebreite < 0) || (maleanPositionCol+aktuellebreite > getSize_x()))
            break;
        for(int aktuellehoehe=0; aktuellehoehe < brushHoehe; aktuellehoehe++)
        {
            if((maleanPositionRow+aktuellehoehe < 0) || (maleanPositionRow+aktuellehoehe > getSize_y()))
                break;
            setPixel(maleanPositionRow+aktuellebreite, maleanPositionCol+aktuellehoehe, *(m_currenBrush->m_currentColor));
        }
    }
}

void Background::save()
{
    saveAsBmp(pixelval, getSize_x(), getSize_y());
    saveAsPpm(pixelval, getSize_x(), getSize_y());
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

