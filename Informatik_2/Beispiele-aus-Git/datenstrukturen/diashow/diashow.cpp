/**
  * Einfach vorwaerts verkettete Liste aus Fotos
  *
  * Vorlesungsbeispiel Informatik 2
  * Claudia Meitinger
  * 17.11.2017
  *
  */

#include "diashow.h"
#include <fstream>
using namespace std;

// Konstruktor
Diashow::Diashow()
{
    m_Anker = nullptr;
}

// Destruktor
Diashow::~Diashow()
{
    clear();
}

// Foto am Anfang einfuegen
void Diashow::pushFront(Foto *pF)
{
    if (!pF)
        return;

    // Das alte erste Element rutscht hinter das einzufuegende
    pF->setNext ( m_Anker );
    // Der Anker zeigt auf das neue erste Element
    m_Anker = pF;
}

// Foto am Ende einfuegen
void Diashow::pushBack(Foto *pF)
{
    if (!pF)
        return;

    // Liste ist leer => Element am Anfang einfuegen
    if (m_Anker == nullptr) {
        pushFront(pF);
    } else { // Liste ist nicht leer
        // Zum letzten Element gehen, beginnend beim ersten Element
        // Dieses ist hier sicher nicht nullptr (Liste nicht leer!) -
        // somit darf im folgenden it->getNext aufgerufen werden.
        Foto *it = m_Anker;
        // Solange das letzte Element nicht erreicht ist...
        while (it->getNext() != nullptr) {
            it = it->getNext(); // ...wird zum naechsten Element gegangen
        }
        // Neues Element an das letzte Element anfuegen
        it->setNext(pF);
        pF->setNext(nullptr);
    }
}

// Anzahl der Fotos in der Diashow ermitteln
unsigned int Diashow::size(void) const
{
    unsigned int nr = 0;
    // Beginnend beim Anker wird so lange zum naechsten Element
    // gezeigt, bis da sEnde der Liste (nullptr) erreicht ist
    for (Foto *it = m_Anker; it != nullptr; it = it->getNext()) {
        nr++;
    }

    return nr;
}

// Informationen ueber Fotos in der Diashow auf dem Bildschirm ausgeben
void Diashow::zeigeInfos(void) const
{
    for (Foto *it = m_Anker; it != nullptr; it = it->getNext()) {
        cout << it->getBeschreibung() << " by " << it->getFotograf() << ": " << it->getDateiname() << endl;
    }
}

// Fotos als Diashow anzeigen
void Diashow::anzeigen(void) const
{
    for (Foto *it = m_Anker; it != nullptr; it = it->getNext()) {
        it->show();
    }
}

// Elemente der Diashow loeschen
// (einschl. Freigeben des durch die einzelnen Knoten
// belegten Speichers)
void Diashow::clear(void)
{
    Foto *it = nullptr;
    while (m_Anker != nullptr) {
        it = m_Anker;
        m_Anker = it->getNext();
        delete it;
    }
}

// Foto an beliebiger Position idx einfuegen
// Index 0 bedeutet Einfuegen am Anfang
// Index 1 bedeutet Einfuegen nach dem ersten Element
// ..
// Index >= Anzahl bedeutet Einfuegen am Ende
void Diashow::insert(Foto *pF, unsigned int idx)
{
    if (!pF)
        return;

    // Index 0 oder Liste leer => Einfuegen am Anfang
    if (idx == 0 || m_Anker == nullptr) {
        pushFront(pF);
    }
    else { // Index != 0
        // Bis zu dem Element gehen, nach dem eingefuegt werden soll:
        // -- Start am Anker (1. Element)
        //    Dieser ist sicher nicht nullptr, da das oben behandelt wurde
        Foto *it = m_Anker;
        unsigned int tmpIdx = 1;
        // -- Solange weitergehen, bis das letzte Element erreicht ist
        //    oder der Index gross genug ist.
        while (it->getNext() != nullptr && tmpIdx < idx) {
            it = it->getNext();
            tmpIdx++;
        }
        // Nach it soll nun eingefuegt werden:
        pF->setNext(it->getNext());
        it->setNext(pF);
    }
}

// Foto an Position idx loeschen
// Index 0 entnimmt das erste Element,
// Index 1 das zweite,...
void Diashow::remove(unsigned int idx)
{
    unsigned int length = size();

    // Liste leer => Fehler
    if (length == 0) {
        cerr << "Fehler: Liste ist leer." << endl;
    } else if (idx >= length) { // Index >= Anzahl Elemente, d.h. zu loeschendes Element nicht vorhanden
        cerr << "Fehler: Element nicht vorhanden!" << endl;
    } else if (idx == 0) { // Index 0: Erstes Element loeschen, d.h. Anker veraendern
        Foto *it = m_Anker;
        m_Anker = it->getNext();
        delete it;
    } else { // Index != 0
        // -- bis zum vorhergehenden Element gehen
        unsigned int tmpIdx = 0;
        Foto *it = m_Anker;
        while (it->getNext() != nullptr && tmpIdx < idx-1) {
            it = it->getNext();
            tmpIdx++;
        }
        // -- Next-Zeiger anpassen
        Foto *tmp = it->getNext();
        it->setNext ( tmp->getNext() );
        // -- Element loeschen
        delete tmp;
    }
}

// Diashow in Datei speichern
void Diashow::speichern(string dateiname) const
{
    fstream diaFile;
    diaFile.open(dateiname.c_str(), ios::out);
    if (diaFile) {
        for (Foto *it = m_Anker; it != nullptr; it = it->getNext()) {
            diaFile << it->getBeschreibung() << ";" << it->getFotograf() << ";" << it->getDateiname() << endl;
        }
        diaFile.close();
    }
}

// Diashow aus Datei laden
void Diashow::einlesen(string dateiname)
{
    fstream diaFile;
    diaFile.open(dateiname.c_str(), ios::in);
    if (diaFile) {
        string line;
        while (!diaFile.eof()) {
            getline(diaFile, line);
            if (!line.empty()) {
                string::size_type posOld = 0, posNew = 0;
                posNew = line.find(';', posOld );
                string beschreibung = line.substr(posOld, posNew);
                posOld = posNew+1;
                posNew = line.find(';', posOld );
                string fotograf = line.substr(posOld, posNew-posOld);
                string dateiname = line.substr(posNew+1);

                Foto *pKnoten = nullptr;
                pKnoten = new Foto ( beschreibung, fotograf, dateiname );
                pushBack ( pKnoten );

                line.clear();
            }
        }
        diaFile.close();
    }
}
