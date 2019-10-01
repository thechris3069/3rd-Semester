/*
 * Wegsuche durch ein Labyrinth mit Hilfe des Backtracking-Algorithmus
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 * 21.11.2017
 */

// ----- INCLUDES -----
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// ----- DEFINES -----
#define BESUCHT ':'

// ----- KLASSEN -----
class Labyrinth
{
private:
    char                m_laby[17][17]; // E: Eingang, A: Ausgang, X: Mauer, blank: freier Weg, :: besuchter Weg
    const unsigned int  m_sizeX;
    const unsigned int  m_sizeY;

public:
    // Konstruktor: Definition des Labyrinths
    Labyrinth();

    // Ausgabe des Labyrinths auf dem Bildschirm
    // mit curX und curY kann eine zu markierende Position angegeben werden,
    // die nicht Bestandteil des Labyrinths ist
    void print(int curX, int curY);

    // Abfrage von X- und Y-Koordinate des Eingangs
    int getEingangX(void);
    int getEingangY(void);

    // Markieren der uebergebenen Position als 'besucht'
    void drawPosToLaby(int x, int y);

    // Markieren der uebergebenen Position als 'nicht besucht'
    void removePosFromLaby(int x, int y);

    // Abfrage, ob an der uebergebenen Position der Ausgang oder eine Mauer ist
    // bzw. ob die Position schon besucht wurde oder sich ausserhalb des
    // Labyrinths befindet
    bool isAusgang(int x, int y);
    bool isMauer(int x, int y);
    bool isBesucht(int x, int y);
    bool isAussen(int x, int y);
};

class Wegfinder
{
private:
    Labyrinth *m_pLaby;    // Zeiger auf Labyrinth, in dem Weg gesucht werden soll
    bool sucheWeg(int x, int y); // Suche des Wegs zum Ausgang ausgehend von der Pos x,y

public:
    // Konstruktor
    Wegfinder(Labyrinth *pL);

    // Wegsuche ausgehend vom Eingang des Labyrinths
    void findeWeg(void);
};

// ----- METHODEN -----
Labyrinth::Labyrinth()
    : m_sizeX(17),m_sizeY(17)
{
    // -------------> x (0..16)
    // |
    // |
    // |
    // v
    // y (0..16)
    // => m_laby[y][x]
    strncpy(m_laby[0],  "XXXXXXXXXEXXXXXXX", 17);
    strncpy(m_laby[1],  "X       X X     X", 17);
    strncpy(m_laby[2],  "X X XXXXX XXX X X", 17);
    strncpy(m_laby[3],  "X X X         X X", 17);
    strncpy(m_laby[4],  "X X X XXXXX XXX X", 17);
    strncpy(m_laby[5],  "X X X X     X   X", 17);
    strncpy(m_laby[6],  "X X X XXXXXXX XXX", 17);
    strncpy(m_laby[7],  "X X       X X   X", 17);
    strncpy(m_laby[8],  "X XXXXXXX X XXX X", 17);
    strncpy(m_laby[9],  "X       X X X   X", 17);
    strncpy(m_laby[10], "X XXXXX X X X XXX", 17);
    strncpy(m_laby[11], "X X     X   X   X", 17);
    strncpy(m_laby[12], "X XXXXX XXXXX X X", 17);
    strncpy(m_laby[13], "X     X X     X X", 17);
    strncpy(m_laby[14], "XXX XXX X XXXXX X", 17);
    strncpy(m_laby[15], "X   X   X X     X", 17);
    strncpy(m_laby[16], "XXXXXXXXXAXXXXXXX", 17);
}

void Labyrinth::print(int curX, int curY)
{
    for (int i = 0; i < m_sizeY; i++) {
        for (int j = 0; j < m_sizeX; j++) {
            if (i == curY && j == curX) {
                cout << "o";
            }
            else {
                cout << m_laby[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int Labyrinth::getEingangX(void)
{
    for (int i = 0; i < m_sizeY; ++i) {
        for (int j = 0; j < m_sizeX; ++j) {
            if (m_laby[i][j] == 'E') {
                return j;
            }
        }
    }
}

int Labyrinth::getEingangY(void)
{
    for (int i = 0; i < m_sizeY; ++i) {
        for (int j = 0; j < m_sizeX; ++j) {
            if (m_laby[i][j] == 'E') {
                return i;
            }
        }
    }
}

void Labyrinth::drawPosToLaby(int x, int y)
{
    if (x >= 0 && x < m_sizeX && y >= 0 && y < m_sizeY) {
        m_laby[y][x] = BESUCHT;
    }
}

void Labyrinth::removePosFromLaby(int x, int y)
{
    if (x >= 0 && x < m_sizeX && y >= 0 && y < m_sizeY) {
        m_laby[y][x] = ' ';
    }
}

bool Labyrinth::isAusgang(int x, int y)
{
    if (x >= 0 && x < m_sizeX && y >= 0 && y < m_sizeY) {
        if (m_laby[y][x] == 'A') {
            return true;
        }
    }
    return false;
}

bool Labyrinth::isMauer(int x, int y)
{
    if (x >= 0 && x < m_sizeX && y >= 0 && y < m_sizeY) {
        if (m_laby[y][x] == 'X') {
            return true;
        }
    }
    return false;
}

bool Labyrinth::isBesucht(int x, int y)
{
    if (x >= 0 && x < m_sizeX && y >= 0 && y < m_sizeY) {
        if (m_laby[y][x] == BESUCHT) {
            return true;
        }
    }
    return false;
}

bool Labyrinth::isAussen(int x, int y)
{
    if (x >= 0 && x < m_sizeX && y >= 0 && y < m_sizeY) {
        return false;
    }
    return true;
}

Wegfinder::Wegfinder(Labyrinth *pL)
    : m_pLaby(pL)
{
    if (!pL) {
        cerr << "NULL pointer for Laby!" << endl;
    }
}

void Wegfinder::findeWeg(void)
{
    if (m_pLaby)
    {
        int x = m_pLaby->getEingangX();
        int y = m_pLaby->getEingangY();
        if (sucheWeg(x, y)) {
            cout << "SUCCESS!" << endl;
        }
        else {
            cout << "FAILURE!" << endl;
        }
    }
}

bool Wegfinder::sucheWeg(int x, int y)
{
    m_pLaby->print(x,y);
    cin.get();

    // Trivialer Fall
    if (m_pLaby->isAusgang(x,y)) {
        return true;
    }
    else if (m_pLaby->isMauer(x,y)) {
        return false;
    }
    else if (m_pLaby->isBesucht(x,y)) {
        return false;
    }
    else if (m_pLaby->isAussen(x,y)) {
        return false;
    }
    else { // Rekursiver Fall
        // aktuelle Stelle als "besucht" markieren
        m_pLaby->drawPosToLaby(x, y);

        // nach unten gehen
        if (sucheWeg(x, y+1) == true)
            return true;
        // nach oben gehen
        if (sucheWeg(x, y-1) == true)
            return true;
        // nach rechts gehen
        if (sucheWeg(x+1, y) == true)
            return true;
        // nach links gehen
        if (sucheWeg(x-1, y) == true)
            return true;

        // von der betrachteten Stelle aus ging es in
        // keine Richtung weiter -> zurueckgehen
        m_pLaby->removePosFromLaby(x, y);
        return false;
    }
}

// ----- HAUPTPROGRAMM -----
int main()
{
    Labyrinth laby;
    Wegfinder finder ( &laby );
    finder.findeWeg();
    return 0;
}

