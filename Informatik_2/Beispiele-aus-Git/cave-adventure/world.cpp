#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "world.h"

World::World(string filename)
{
    try {
        bool success = false;
        if (!filename.empty()) {
            success = initFromFile(filename);
        }
        if (!success) {
            initRandom();
        }
    } catch(...)
    {
        throw;
    }
}

World::~World()
{
    // Speicherplatz der Raeume freigeben
    for (unsigned int row = 0; row < m_nrRows; ++row) {
        for (unsigned int col = 0; col < m_nrCols; ++col) {
            delete m_rooms[row][col];
        }
    }

    // Speicherplatz des zweidimensionalen Feldes freigeben
    for (unsigned int i = 0; i < m_nrRows; ++i) {
        delete[] m_rooms[i];
    }
    delete[] m_rooms;

}

void World::initRandom(unsigned int nrRows, unsigned int nrColumns)
{
    m_nrRows = nrRows <= 20 ? nrRows : 20;
    m_nrCols = nrColumns <= 30 ? nrColumns : 30;

    cout << "Zufaellige Welt mit " << m_nrRows << " Zeilen und " << m_nrCols << " Spalten wird angelegt!" << endl;

    // Position des Startfeldes festlegen
    m_rowStart = rand() % m_nrRows;
    m_colStart = rand() % m_nrCols;

    // TODO: Error/exception handling ergaenzen!

    // Speicher fuer Zeilen reservieren
    try {
        m_rooms = new Room **[m_nrRows];
    } catch (std::bad_alloc &e) {
        cerr << "Speicher fuer m_rooms konnte nicht allokiert werden!" << endl;
        cerr << e.what() << endl;
        throw; // re-throw
    }
    // Speicher fuer Spalten reservieren
    for (unsigned int i = 0; i < m_nrRows; ++i) {
        try {
            m_rooms[i] = new Room *[m_nrCols];
        } catch (std::bad_alloc &e) {
            cerr << "Speicher fuer m_rooms[i] konnte nicht allokiert werden!" << endl;
            cerr << e.what() << endl;
            for (unsigned int j = 0; j < i; j++)
                delete[] m_rooms[j];
            delete[] m_rooms;
            throw; // re-throw
        }
    }

    // Raeume undefiniert initialisieren
    for (unsigned int row = 0; row < m_nrRows; ++row) {
        for (unsigned int col = 0; col < m_nrCols; ++col) {
            m_rooms[row][col] = nullptr;
        }
    }

    // Raeume erzeugen
    try {
        unsigned int row, col;
        // - Eingang
        m_rooms[m_rowStart][m_colStart] = new RoomEntry();
        // - Ausgang
        if (getUndefinedRoom(&row, &col))
            m_rooms[row][col] = new RoomExit();
        // - ca. 1/3 der Raeume: Kreaturen
        for (unsigned int nr = 0; nr < (m_nrCols*m_nrRows)/3; ++nr)
        {
            if (getUndefinedRoom(&row, &col))
                m_rooms[row][col] = new RoomCreature();
        }
        // - ca. 1/4 der Raeume: Gold
        for (unsigned int nr = 0; nr < (m_nrCols*m_nrRows)/4; ++nr)
        {
            if (getUndefinedRoom(&row, &col))
                m_rooms[row][col] = new RoomGold();
        }
        // 2 Haendler
        for (unsigned int nr = 0; nr < 2; ++nr)
        {
            if (getUndefinedRoom(&row, &col))
                m_rooms[row][col] = new RoomTrader();
        }
        // Rest: leere Raeume
        for (unsigned int row = 0; row < m_nrRows; ++row) {
            for (unsigned int col = 0; col < m_nrCols; ++col) {
                if (m_rooms[row][col] == nullptr)
                    m_rooms[row][col] = new RoomEmpty();
            }
        }
    } catch (std::bad_alloc &e) {
        cerr << "Speicher fuer m_rooms[i][j] konnte nicht allokiert werden!" << endl;
        cerr << e.what() << endl;
        for (unsigned int row = 0; row < m_nrRows; ++row) {
            for (unsigned int col = 0; col < m_nrCols; ++col) {
                if (m_rooms[row][col])
                    delete m_rooms[row][col];
            }
        }
        for (unsigned int i = 0; i < m_nrRows; ++i) {
            delete[] m_rooms[i];
        }
        delete[] m_rooms;
        throw; // re-throw
    }
}

vector<string> World::findCaves(string cavePath)
{
    vector<string> caveFiles;
    DIR *pDir = opendir(cavePath.c_str());
    if(pDir) {
        while (1) {
            struct dirent *dirEntry = readdir(pDir);
            if (!dirEntry) // keine Eintraege mehr im Verzeichnis
                break;
            // Typ des Verzeichniseintrags ermitteln
            string entryName = dirEntry->d_name;
            string entry = cavePath + "/" + entryName;
            struct stat info;
            stat(entry.c_str(), &info);
            if (S_ISREG(info.st_mode)) { // regulaere Datei -> trivialer Fall
                caveFiles.push_back(entry);
            } else if (S_ISDIR(info.st_mode)) { // Verzeichnis
                if (entryName == string(".") || entryName == string("..")) { // trivialer Fall: aktuelles oder uebergeordnetes Verzeichnis
                } else { // rekursiver Fall: echtes Unterverzeichnis
                    vector<string> moreCaves = findCaves(entry); // rekursiver Aufruf
                    for (string cave : moreCaves) {
                        caveFiles.push_back(cave);
                    }
                }
            }
        }
    }
    closedir(pDir);

    return caveFiles;
}

bool World::initFromFile(std::string cavePath)
{
    // Hoehle aus allen im Pfad verfuegbaren Dateien auswaehlen
    vector<string> allCaves = findCaves(cavePath);
    int i = 0, nr;
    cout << "Welche Hoehle willst Du betreten? " << endl;
    for (string cave : allCaves) {
        cout << i++ << ": " << cave << endl;
    }
    cout << "Deine Wahl: ";
    cin >> nr;

    if (nr < 0 || nr >= allCaves.size()) {
        cout << "Ungueltige Eingabe!" << endl;
        return false;
    }

    // Hoehle auslesen
    ifstream f(allCaves[nr]);
    if (!f) {
        cout << "Fehler beim Oeffnen von " << allCaves[nr] << "!" << endl;
        return false;
    }

    char line[512];
    f.getline(line, 512);
    istringstream lineinput(line);

    // CAVE
    string input;
    lineinput >> input;
    if (input != string("CAVE")) {
        cout << "Datei beginnt nicht mit CAVE!" << endl;
        return false;
    }

    // Anzahl Zeilen und Spalten
    f.getline(line, 512);
    lineinput = istringstream(line);
    lineinput >> m_nrRows;
    lineinput >> m_nrCols;
    if (m_nrRows > 100 || m_nrCols > 100)
        return false;
    cout << "Hoehle besteht aus " << m_nrRows << " Zeilen und ";
    cout << m_nrCols << " Spalten." << endl;

    // Kommentar
    f.getline(line, 512);
    cout << line << endl;

    // Inhalt auslesen
    // - Speicher fuer Zeilen reservieren
    try {
        m_rooms = new Room **[m_nrRows];
    } catch (std::bad_alloc &e) {
        cerr << "Speicher fuer m_rooms konnte nicht allokiert werden!" << endl;
        cerr << e.what() << endl;
        throw; // re-throw
    }
    // - Speicher fuer Spalten reservieren
    for (unsigned int row = 0; row < m_nrRows; row++) {
        try {
            m_rooms[row] = new Room *[m_nrCols];
        } catch (std::bad_alloc &e) {
            cerr << "Speicher fuer m_rooms[i] konnte nicht allokiert werden!" << endl;
            cerr << e.what() << endl;
            for (unsigned int i = 0; i < row; ++i) {
                delete[] m_rooms[i];
            }
            delete[] m_rooms;
            throw; // re-throw
        }
    }

    // - Raeume einlesen und befuellen
    for (unsigned int row = 0; row < m_nrRows; row++)
        for (unsigned int col = 0; col < m_nrCols; col++)
            m_rooms[row][col] = nullptr;

    try {
        for (unsigned int row = 0; row < m_nrRows; row++) {
            f.getline(line, 512);
            lineinput = istringstream(line);
            for (unsigned int col = 0; col < m_nrCols; col++) {
                char room = 'X';
                lineinput >> room;
                switch(room) {
                case 'E': m_rooms[row][col] = new RoomEntry();
                    m_rowStart = row;
                    m_colStart = col;
                    break;
                case 'A': m_rooms[row][col] = new RoomExit();
                    break;
                case 'G': m_rooms[row][col] = new RoomGold();
                    break;
                case 'K': m_rooms[row][col] = new RoomCreature();
                    break;
                case 'H': m_rooms[row][col] = new RoomTrader();
                    break;
                case 'X':
                default:  m_rooms[row][col] = new RoomEmpty();
                    break;
                }
            }
        }
    } catch (std::bad_alloc &e) {
        cerr << "Speicher fuer m_rooms[i][j] konnte nicht allokiert werden!" << endl;
        cerr << e.what() << endl;
        for (unsigned int row = 0; row < m_nrRows; ++row) {
            for (unsigned int col = 0; col < m_nrCols; ++col) {
                if (m_rooms[row][col])
                    delete m_rooms[row][col];
            }
        }
        for (unsigned int i = 0; i < m_nrRows; ++i) {
            delete[] m_rooms[i];
        }
        delete[] m_rooms;
        throw; // re-throw
    }
    return true;
}

bool World::getUndefinedRoom(unsigned int *row, unsigned int *col)
{
    bool roomAvailable = false;

    // bestimmen, ob noch ein undefinierter Raum vorhanden ist
    for (unsigned int row = 0; row < m_nrRows; ++row) {
        for (unsigned int col = 0; col < m_nrCols; ++col) {
            if (m_rooms[row][col] == nullptr) {
                roomAvailable = true;
                break;
            }
        }
        if (roomAvailable)
            break;
    }

    if (!roomAvailable)
        return false;

    // mindestens ein undefinierter Raum ist vorhanden =>
    // zufaellig Zeile und Spalte bestimmen
    while (1)
    {
        *row = rand() % m_nrRows;
        *col = rand() % m_nrCols;
        if (m_rooms[*row][*col] == nullptr)
            return true;
    }

    return false;
}

Room *World::getRoomAt(int row, int col) const
{
    if (row >= 0
            && static_cast<unsigned int>(row) < m_nrRows
            && col >= 0
            && static_cast<unsigned int>(col) < m_nrCols)
        return m_rooms[row][col];
    string errorMsg = "Ungueltiger Raumindex " + to_string(row) + ", " + to_string(col) + "!";
    throw errorMsg;
}
