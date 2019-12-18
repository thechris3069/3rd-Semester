#include <iostream>
#include <vector>
#include <string>
//#include <cstdlib>
#include <limits.h>


using namespace std;

class Zeile
{
public:
    Zeile()
        :m_inhalt("\n"), next_p(nullptr)
    {}
string m_inhalt;
Zeile * next_p;
};

class Texteditor
{
public:
    Texteditor()
        :m_anker(nullptr) // wieso wird nicht der konstruktor von selber aufgerufen?
        {
//        m_anker = new Zeile;
    }

    Zeile * m_anker;
    void zeigeAktDoku();
    void zeigeAktionen();
    Zeile* neueZeile();

private:
    void loscheDoku();
    void getsize();
    void pushFront(Zeile* neueZeile);
    void pushBack(Zeile* neueZeile);
    void zeileEinfuegen();
    void zeileAendern();
    void speicher();
    void zeileAendern(int idx, std::string inhalt);
};

Zeile* Texteditor::neueZeile()
{
    Zeile *neueZeile = new Zeile;
        cout << "Geben Sie ihre Zeile ein" << endl;

            getline(cin, neueZeile->m_inhalt);
//        cin >> neueZeile->m_inhalt;
//        cin.ignore(INT_MAX, '\n');
//        Zeile * pZeile = neueZeile;
        return neueZeile;
}

void Texteditor::pushFront(Zeile* neueZeile)
{

        if(m_anker != nullptr)
        {
//            Zeile *temp = m_anker;
            neueZeile->next_p = m_anker;
            m_anker = neueZeile;
        }
        else
        m_anker = neueZeile;
}

void Texteditor::pushBack(Zeile* neueZeile)
{
        if(m_anker != nullptr)
        {
            Zeile *temp = m_anker;
            while(temp->next_p != nullptr)
            {
                temp = temp->next_p;
//            temp = temp->next_p;
            }

           temp->next_p = neueZeile;
//           temp->next_p = nullptr;
//           m_anker->next_p = temp;
//           delete temp;

        }
        else
        pushFront(neueZeile);
}



void Texteditor::getsize()
{
    Zeile* temppointer;
    temppointer = m_anker;
    int zeile = 0;
    while (temppointer != nullptr)
    {
        ++zeile;
        temppointer = temppointer->next_p;
    }
    cout << zeile << "Zeilen hat das Dokument" << endl;
}


void Texteditor::zeigeAktDoku()
{
   int zeile = 0;
   Zeile* temppointer;
   temppointer = m_anker;

   while (temppointer != nullptr)
   {
       ++zeile;
        cout << zeile <<" : Zeileninhalt: " << temppointer->m_inhalt << endl;
        temppointer = temppointer->next_p;
   }
}


//    int zeile = 0;
//    for(vector<string>::iterator it = m_inhalt.begin();
//        it != m_inhalt.end(); ++it, ++zeile)
//    {
//        cout << "Zeile: " << zeile+1 << " " << *it << endl;
//    }

    //    for (int i = 0; i < m_inhalt.size(); ++i)
    //        cout << "Zeile: " << m_inhalt[i] << endl;

    //    for (int i = 0; i < m_inhalt.size(); ++i)
    //        cout << "Zeile: " << m_inhalt.at(i) << endl;

    //    for (auto z: m_inhalt)
    //        cout << "Zeile: " << z << endl;
//}

void Texteditor::loscheDoku()
{
    Zeile * temppointer;
    temppointer = m_anker;
    while(temppointer != nullptr)
    {
        m_anker = m_anker->next_p;
        delete temppointer;
        temppointer = m_anker;
    }
        cout << "Dokument wurde geloescht" << endl;
}

void Texteditor::zeileAendern()
{

    cout << "Welche Zeile soll veraendert werden?" << endl;
    int zeile;
    cin >> zeile;
    cin.ignore(INT_MAX, '\n');
        Zeile *pZeile = neueZeile();
//    string zeileninhalt;
//    getline(cin, zeileninhalt);
    if(m_anker != nullptr)
    {
        Zeile* it = m_anker;
        int zeilenit = 0;
        do
        {
            it = it->next_p;
           ++zeilenit;
        }
        while(it != nullptr && zeilenit < zeile);


            Zeile *temp = it->next_p;
            pZeile->next_p = temp;
            it->next_p = pZeile;


//    zeileAendern(zeile-1, zeileninhalt);
}
}

void Texteditor::zeileAendern(int idx, string inhalt)
{
//    m_inhalt.at(idx) = inhalt;
}

void Texteditor::zeileEinfuegen()
{
//    cout << "Geben Sie ihre Zeile ein" << endl;
//    string eingabe;
//    getline(cin, eingabe);
////    cin >> eingabe;
//    m_inhalt.push_back(eingabe);
////       cin.ignore(INT_MAX, '\n');

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
    cout << "5: Hinten Zeile anhaengen" <<endl;
    cout << "6: Vorne Zeile anhaengen" <<endl;
    cout << "7: Groesse von Dokument anzeigen" <<endl;

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
    case 5: pushBack(neueZeile()); break;
    case 6: pushFront(neueZeile()); break;
    case 7: getsize(); break;
    default:
        cout << "Falsche Eingabe" << endl; break;
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
