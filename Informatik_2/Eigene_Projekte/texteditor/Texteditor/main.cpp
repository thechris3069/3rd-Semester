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
};

void Texteditor::zeigeAktDoku()
{
    for(vector<string>::iterator it = m_inhalt.begin();
        it != m_inhalt.end(); ++it)
    {
        cout << "Zeile: " << " " << *it << endl;
    }

}

void Texteditor::loscheDoku()
{

}

void Texteditor::zeileAendern()
{

}

void Texteditor::zeileEinfuegen()
{

}

void Texteditor::speicher()
{

}

void Texteditor::zeigeAktionen()
{
    char eingabe;
    cout << "Dokument loeschen?" << endl;
    cin >> eingabe;
    cin.ignore(INT_MAX, '\n');
    if(eingabe == 'y')
    {
        loscheDoku();
        return;
    }
    cout << "Zeile einfuegen?" << endl;
    cin >> eingabe;
    cin.ignore(INT_MAX, '\n');
    if(eingabe == 'y')
    {
        zeileEinfuegen();
        return;
    }

    cout << "Zeile aendern?" <<endl;
    cin >> eingabe;
    cin.ignore(INT_MAX, '\n');
    if(eingabe == 'y')
    {
        zeileAendern();
        return;
    }

    cout <<  "speichern?" << endl;
    cin >> eingabe;
    cin.ignore(INT_MAX, '\n');
    if(eingabe == 'y')
    {
        speicher();
    }
}



int main()
{
    Texteditor tex;
    char eingabe;
    do{
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
