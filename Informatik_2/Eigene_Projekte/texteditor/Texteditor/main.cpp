#include <iostream>
#include <vector>
#include <string>
//#include <cstdlib>
#include <limits.h>


using namespace std;

class Texteditor
{
public:
    Texteditor()
        :m_inhalt(NULL)
    {}
    vector <string> m_inhalt;
    void zeigeAktDoku();
    void zeigeAktionen();

private:
    void loscheDoku();
    void zeileEinfuegen();
    void zeileAendern();
    void speicher();
    void zeileAendern(int idx, std::string inhalt);

};

void Texteditor::zeigeAktDoku()
{
    int zeile = 0;
    for(vector<string>::iterator it = m_inhalt.begin();
        it != m_inhalt.end(); ++it, ++zeile)
    {
        cout << "Zeile: " << zeile+1 << " " << *it << endl;
    }

    //    for (int i = 0; i < m_inhalt.size(); ++i)
    //        cout << "Zeile: " << m_inhalt[i] << endl;

    //    for (int i = 0; i < m_inhalt.size(); ++i)
    //        cout << "Zeile: " << m_inhalt.at(i) << endl;

    //    for (auto z: m_inhalt)
    //        cout << "Zeile: " << z << endl;
}

void Texteditor::loscheDoku()
{
    m_inhalt.clear();
    cout << "Dokument wurde geloescht" << endl;
}

void Texteditor::zeileAendern()
{
    cout << "Welche Zeile soll veraendert werden?" << endl;
    int zeile;
    cin >> zeile;
    cin.ignore(INT_MAX, '\n');
    string zeileninhalt;
    getline(cin, zeileninhalt);
    if(zeile -1 <= m_inhalt.size())
    zeileAendern(zeile-1, zeileninhalt);

}

void Texteditor::zeileAendern(int idx, string inhalt)
{
    m_inhalt.at(idx) = inhalt;
}

void Texteditor::zeileEinfuegen()
{
    cout << "Geben Sie ihre Zeile ein" << endl;
    string eingabe;
    getline(cin, eingabe);
//    cin >> eingabe;
    m_inhalt.push_back(eingabe);
//       cin.ignore(INT_MAX, '\n');

}

void Texteditor::speicher()
{
    cout << "Dokument wurde gespeichert" << endl;
}

void Texteditor::zeigeAktionen()
{
    cout << "1: Dokument loeschen?" << endl;
    cout << "2: Zeile einfuegen?" << endl;
    cout << "3: Zeile aendern?" <<endl;
    cout <<  "4: speichern?" << endl;

    int eingabe;
    cin >> eingabe;
    cin.ignore(INT_MAX, '\n');
    switch (eingabe)
    {
    case 1:         loscheDoku();
        break;
    case 2: zeileEinfuegen();
        break;
    case 3: zeileAendern(); break;
    case 4: speicher(); break;
    }
}

int main()
{
    Texteditor tex;
    char eingabe;
    do{
        tex.zeigeAktDoku();
        cout << "Moechten Sie das Programm schliessen? (y/n)" << endl;
        cin >> eingabe;
        cin.ignore(INT_MAX, '\n');
        if(eingabe == 'y')
        {
            //Schliesse Das Programm
            cout << "Programm wird geschlossen" << endl;
            return 0;
        }
        else if (eingabe == 'n')
        {
            tex.zeigeAktDoku();
            tex.zeigeAktionen();
        }
        else
        {
            cout << "Falsche Eingabe. Geben sie erneut ein" << endl;
        }
    }while(eingabe != 'y');

    return 0;
}
