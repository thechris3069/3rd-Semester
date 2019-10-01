#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
using namespace std;

// --------- HAUPTPROGRAMM -------------
int main ()
{
    vector<string> dokument;
    char naechsteAktion = 'x';
    int nrZeile = 0;
    char dateiname[255];

    do
    {
        // Dokument ausgeben
        cout << "----------------" << endl;
        for (unsigned int i = 0; i < dokument.size(); i++)
            cout << i+1 << ": " << dokument[i] << endl;
        cout << "----------------" << endl;

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
        switch ( naechsteAktion )
        {
        case 'a': dokument.clear();
            break;
        case 'b':
        {
            cout << "Nach welcher Zeile soll die neue Zeile eingefuegt werden (0: Anfang)? ";
            cin >> nrZeile;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Neuer Zext fuer Zeile " << nrZeile << ": ";
            string neuerText;
            getline(cin, neuerText);
            cin.clear();
            vector<string>::iterator it;
            unsigned int i;
            for (i = 0, it = dokument.begin(); it != dokument.end() && i < nrZeile; it++, i++)
                ;
            dokument.insert(it, 1, neuerText);
            break;
        }
        case 'c':
            cout << "Welche Zeile soll neu beschrieben werden? ";
            cin >> nrZeile;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (nrZeile > 0 && nrZeile <= dokument.size())
            {
                cout << "Neuer Zext fuer Zeile " << nrZeile << ": ";
                string neuerText;
                getline(cin, neuerText);
                cin.clear();
                dokument[nrZeile-1] = neuerText;
            }
            break;
        case 'd':
        {
            cout << "Dateiname zum Speichern: ";
            cin >> dateiname;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            ofstream dokFile;
            dokFile.open(dateiname, ios::out | ios::trunc);
            if (dokFile)
            {
                for(unsigned int i = 0; i < dokument.size(); i++)
                    dokFile << dokument[i] << endl;
                dokFile.close();
            }
            else
            {
                cerr << "Fehler beim Oeffnen der Datei!" << endl;
            }
        }
            break;
        }

    } while (naechsteAktion != 'x');

    return 0;
}


