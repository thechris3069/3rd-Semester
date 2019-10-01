#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

class Zeile
{
private:
    string  m_text;   ///< Text in der Zeile
    Zeile * m_pNext;  ///< Zeiger auf nächste Zeile

public:
    /// Standard-Konstruktor
    Zeile()
    {
        m_pNext = nullptr;
    }

    /// Lesender und schreibender Zugriff auf next-Zeiger
    Zeile *getNext(void) { return m_pNext; }
    void setNext(Zeile *next) { m_pNext = next; }

    /// Lesender und schriebender Zugriff auf Text
    string getText(void) { return m_text; }
    void setText(string text) { m_text = text; }
};

class Textdokument
{
private:
    Zeile * m_anker; ///< Anker der verketteten Liste

public:
    /// Standard-Konstruktor
    Textdokument()
    {
        m_anker = nullptr;
    }

    /// Destruktor
    ~Textdokument()
    {
        loeschen();
    }

    /// Methode zum Ausgeben des aktuellen Dokuments auf dem Bildschirm (inkl. Zeilennummern )
    void ausgeben(void)
    {
        Zeile *iterator = nullptr;
        int nrZeile = 1;

        cout << "\n--- BEGIN DOCUMENT ---\n";
        // Wir gehen mit dem Iterator durch alle Zeilen...
        iterator = m_anker;
        while (iterator != nullptr)
        {
            //... und geben jede Zeile mit Nummer aus.
            cout << nrZeile << ": " << iterator->getText() << endl;

            // nächste Zeile
            nrZeile++;
            iterator = iterator->getNext();
        }
        cout << "--- END DOCUMENT ---\n";
    }

    /// Methode zum Loeschen aller Zeilen im Textdokument
    void loeschen(void)
    {
        Zeile *pElement = nullptr;

        // Wir löschen solange die erste Zeile bis es keine Zeilen mehr gibt.
        while (m_anker != nullptr)
        {
            pElement = m_anker; // Wir merken uns das zu löschende Element
            m_anker = pElement->getNext(); // ... die zweite Zeile ist nun die erste
            // Speicherplatz freigeben = Element löschen
            delete pElement;
        }
    }

    /// Methode zum Einfuegen einer Zeile in das Dokument nach der Zeile mit der Nummer nr
    void zeileEinfuegen(int nr)
    {
        Zeile *pNeueZeile = nullptr;
        Zeile *iterator = nullptr;
        int aktuelleZeile = 0;

        // Speicherplatz für neue Zeile reservieren:
        pNeueZeile = new Zeile;

        if (pNeueZeile) // falls Speicherplatz reserviert werden konnte
        {
            if (nr == 0 || m_anker == nullptr) // Zeile am Anfang einfügen
            {
                pNeueZeile->setNext(m_anker);
                m_anker = pNeueZeile;
            }
            else // bis zur Zeile mit der übergebenen Nummer gehen
            {
                iterator = m_anker;
                aktuelleZeile = 1;
                while (iterator != nullptr && aktuelleZeile < nr)
                {
                    iterator = iterator->getNext();
                    aktuelleZeile++;
                }
                // Wenn nun die Zeilennummer gleich der übergebenen Nummer ist, sind wir an der richtigen Stelle...
                if (aktuelleZeile == nr && iterator != nullptr)
                {
                    pNeueZeile->setNext ( iterator->getNext() );
                    iterator->setNext ( pNeueZeile );
                }
                else // sonst gibt es diese Zeilennummer nicht!
                {
                    cerr << "Zeile mit der Nr. " << nr << " konnte nicht gefunden werden!\n";
                    delete pNeueZeile;
                }
            }
        }
    }

    /// Methode zum Beschreiben einer existieren Zeile mit der Nummer nr
    void zeileBeschreiben(int nr)
    {
        Zeile *iterator = nullptr;
        int aktuelleZeile = 0;

        iterator = m_anker;
        aktuelleZeile = 1;
        while (iterator != nullptr && aktuelleZeile < nr)
        {
            iterator = iterator->getNext();
            aktuelleZeile++;
        }

        // Wenn nun die Zeilennummer gleich der übergebenen Nummer ist, sind wir an der richtigen Stelle...
        if (aktuelleZeile == nr && iterator != nullptr)
        {
            cout << "Neuer Zext fuer Zeile " << nr << ": ";
            string neuerText;
            getline(cin, neuerText);
            cin.clear();
            iterator->setText(neuerText);
        }
        else // sonst gibt es diese Zeilennummer nicht!
        {
            cerr << "Zeile mit der Nr. " << nr << " konnte nicht gefunden werden!\n";
        }

    }

    /// Methode zum Speichern des Dokuments in einer Datei mit dem Namen dateiname
    void speichern(const char *dateiname)
    {
        ofstream dokFile;
        dokFile.open(dateiname, ios::out | ios::trunc);
        if (dokFile)
        {
            Zeile *iterator = m_anker;
            while ( iterator != nullptr )
            {
                dokFile << iterator->getText() << endl;
                iterator = iterator->getNext();
            }
            dokFile.close();
        }
        else
        {
            cerr << "Fehler beim Oeffnen der Datei!" << endl;
        }
    }
};

// --------- HAUPTPROGRAMM -------------
int main ()
{
    Textdokument dokument;
    char naechsteAktion = 'x';
    int nrZeile = 0;
    char dateiname[255];

    do
    {
        dokument.ausgeben();

        // Menü ausgeben
        cout << endl;
        cout << "(a) Dokument loeschen\n";
        cout << "(b) Zeile einfuegen\n";
        cout << "(c) Zeile neu beschreiben\n";
        cout << "(d) Dokument speichern\n";
        cout << "(x) Programm beenden\n";

        // Aktion abfragen
        cout << "Ihre Wahl: ";
        cin >> naechsteAktion;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Aktion ausführen
        switch (naechsteAktion)
        {
        case 'a': dokument.loeschen();
            break;
        case 'b':
            cout << "Nach welcher Zeile soll die neue Zeile eingefuegt werden (0: Anfang)? ";
            cin >> nrZeile;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            dokument.zeileEinfuegen(nrZeile);
            break;
        case 'c':
            cout << "Welche Zeile soll neu beschrieben werden? ";
            cin >> nrZeile;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            dokument.zeileBeschreiben(nrZeile);
            break;
        case 'd':
            cout << "Dateiname zum Speichern: ";
            cin >> dateiname;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            dokument.speichern(dateiname);
            break;
        }

    } while (naechsteAktion != 'x');

    return 0;
}

