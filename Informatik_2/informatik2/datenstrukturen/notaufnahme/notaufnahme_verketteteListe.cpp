/*
 * In einer Notaufnahme werden die eingehenden Patienten von eigens
 * geschultem Pflegepersonal hinsichtlich der Dringlichkeit der
 * Behandlung eingestuft (1: sehr dringend .. 5: nicht dringend,
 * vgl. ESI „Emergency Severity Index“) und die Patientendaten
 * (Name, Dringlichkeit, Behandlungsraum) im elektronischen Wartesystem
 * hinterlegt. Sobald ein Arzt Zeit fuer den naechsten Patienten hat,
 * entnimmt er den ersten Patienten aus dem elektronischen Wartesystem
 * und behandelt ihn.
 * Implementieren Sie ein Programm, in dem die Daten der Notfall-
 * Patienten als einfach verkettete Liste hinterlegt werden!
 * Sehen Sie Funktionalitaeten vor, mit denen neue Patientendaten
 * hinzugefuegt werden koennen und die Informationen ueber den naechsten
 * zu behandelnden Patienten entnommen werden koennen. Falls mehrere
 * Patienten mit der gleichen Dringlichkeit warten, soll zuerst
 * derjenige behandelt werden, der schon laenger wartet. Darueber
 * hinaus soll es moeglich sein, abzufragen, wie viele Patienten aktuell
 * auf eine Behandlung warten.
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 * 7.11.2017
 */

#include <iostream>
#include <string>

// ----- Klasse Patient -----
// (typischerweise in patient.h)
class Patient
{
private:
    std::string       m_name;
    unsigned int      m_dringlichkeit; // 1: sehr dringend .. 5: nicht dringend
    std::string       m_behandlungsraum;
    Patient *m_pNext = nullptr; // Zeiger auf naechsten Eintrag der verketteten Liste; nullptr fuer letztes Element

public:
    // Konstruktor
    Patient(std::string name, unsigned int dringlichkeit, std::string behandlungsraum);

    // Zugriff auf next-Zeiger
    Patient *getNext() const { return m_pNext; }
    void setNext(Patient *next) { m_pNext = next; }

    // Zugriff auf Dringlichkeit
    unsigned int getDringlichkeit() const { return m_dringlichkeit; }

    // Methode zum Anzeigen der Patientendaten
    void anzeigen() const;
};

// ----- Methoden der Klasse Patient ----
// (typischerweise in patient.cpp)
Patient::Patient(std::string name, unsigned int dringlichkeit, std::string behandlungsraum)
    : m_name(name),
      m_dringlichkeit(dringlichkeit),
      m_behandlungsraum(behandlungsraum)
{
}

void Patient::anzeigen() const
{
    std::cout << m_dringlichkeit << ": " << m_name << " (" << m_behandlungsraum << ")" << std::endl;
}

// ----- Klasse Warteschlange -----
// (typischerweise in warteschlange.h)
class Warteschlange
{
private:
    Patient *m_anker = nullptr; // Anker der verketteten Liste; Liste ist zu Beginn leer

public:
    // Destruktor: gibt Speicher aller noch vorhandenen Listeneintraege frei
    ~Warteschlange();

    // Patient einfuegen: sehr dringende Patienten zuerst, nicht dringende zuletzt
    // Sind bereits Patienten mit der gleichen Dringlichkeit vorhanden, werden diese
    // am Ende der gleichen Dringlichkeitsstufe eingefuegt.
    // Damit wird sichergestellt, dass bei gleich dringenden Patienten
    // derjenige zuerst an der Reihe ist, der laenger wartet.
    void insert(Patient *p);

    // Patient entnehmen: ersten Patienten aus der Warteschlange (am Anfang) entnehmen
    // Rueckgabe: nullptr, wenn Liste leer
    Patient *popFront();

    // Abfrage der Anzahl der Eintraege in der Warteschlange
    unsigned int size() const;

    // Alle Eintraege der verketteten Liste loeschen
    // (einschliesslich Freigabe des Speicherplatzes der Knoten)
    void clear();

    // Informationen ueber Warteschlange anzeigen lassen
    void anzeigen() const;
};

// ----- Methoden der Klasse Warteschlange -----
// (typischerweise in warteschlange.cpp)
Warteschlange::~Warteschlange()
{
    clear();
}

void Warteschlange::insert(Patient *p)
{
    // nullptr wird nicht weiter behandelt
    if (!p)
        return;

    // Liste ist leer
    if (!m_anker) {
        // p am Anfang einfuegen
        p->setNext(m_anker);
        m_anker = p;
    } else if (m_anker->getDringlichkeit() > p->getDringlichkeit()) { // bisheriger erster Patient hat niedrigere Dringlichkeit als p
        // p am Anfang einfuegen
        p->setNext(m_anker);
        m_anker = p;
    } else {
        // soweit durch Liste gehen, bis der naechste Patient eine niedrigere
        // Dringlichkeit hat, oder die Liste zu Ende ist
        Patient *it = m_anker;
        while (it->getNext() != nullptr &&
               it->getNext()->getDringlichkeit() <= p->getDringlichkeit() ) {
            it = it->getNext();
        }
        // Patienten an der gefundenen Stelle einsortieren
        p->setNext(it->getNext());
        it->setNext(p);
    }
}

Patient *Warteschlange::popFront()
{
    Patient *first = m_anker;

    // Es sind noch Patienten da: ehemals zweiter Patient ist nun erster
    if (m_anker) {
        m_anker = m_anker->getNext();
    }

    // Vorherigen ersten Patienten (oder nullptr, falls Liste leer) zurueckgeben
    return first;
}

unsigned int Warteschlange::size() const
{
    unsigned int anzahl = 0;
    for (Patient *it = m_anker; it != nullptr; it = it->getNext())
        anzahl++;
    return anzahl;
}

void Warteschlange::clear()
{
    while(m_anker) {
        Patient *tmp = m_anker;
        m_anker = m_anker->getNext();
        delete tmp;
    }
}

void Warteschlange::anzeigen() const
{
    std::cout << "Die Warteschlange enthaelt " << size() << " Eintraege: " << std::endl;
    for (Patient *it = m_anker; it != nullptr; it = it->getNext())
        it->anzeigen();
}

// ----- Hauptprogramm -----
int main()
{
    char aktion = 'x';
    Warteschlange w;

    // Automatischer Test
    // -- Patienten dazufuegen
    w.insert(new Patient("Alice", 3, "B1.1"));
    w.anzeigen();
    w.insert(new Patient("Bob", 3, "B1.2"));
    w.anzeigen();
    w.insert(new Patient("Chris", 3, "B1.3"));
    w.anzeigen();
    // -- einen Patienten behandeln
    Patient *p = w.popFront();
    if (p != nullptr)
    {
        std::cout << "Behandelt wird: ";
        p->anzeigen();
        std::cout << std::endl;
        delete p;
    }
    w.anzeigen();
    // -- Patienten dazufuegen
    w.insert(new Patient("Dennis", 1, "B1.4"));
    w.anzeigen();
    w.insert(new Patient("Emil", 1, "B1.5"));
    w.anzeigen();
    w.insert(new Patient("Franz", 4, "B1.6"));
    w.anzeigen();
    w.insert(new Patient("Gustav", 2, "B1.6"));
    w.anzeigen();
    w.insert(new Patient("Heinz", 5, "B1.6"));
    w.anzeigen();
    // -- alle verbleibenden Patienten behandeln
    while(1)
    {
        p = w.popFront();
        if (p == nullptr)
            break;
        std::cout << "Behandelt wird: ";
        p->anzeigen();
        std::cout << std::endl;
        delete p;
    }

    // Interaktive Variante
    w.clear();
    do
    {
        std::cout << "Was wollen Sie tun (1: Patient hinzufuegen, 2: Patient entnehmen, x: Ende)? " << std::endl;
        std::cin >> aktion;
        while(getchar() != '\n');
        std::cin.clear();

        switch(aktion)
        {
        case '1': // Patient hinzufuegen
            {
                std::string name, zimmer;
                unsigned int dringlichkeit;
                std::cout << "Name: ";
                std::cin >> name;
                while(getchar() != '\n');
                std::cin.clear();
                std::cout << "Dringlichkeit: ";
                std::cin >> dringlichkeit;
                while(getchar() != '\n');
                std::cin.clear();
                std::cout << "Zimmer: ";
                std::cin >> zimmer;
                while(getchar() != '\n');
                std::cin.clear();
                w.insert(new Patient(name, dringlichkeit, zimmer));
            }
            break;
        case '2': // Patient entnehmen
            {
                Patient *p = w.popFront();
                if (p)
                {
                    std::cout << "An der Reihe ist:" << std::endl;
                    p->anzeigen();
                    std::cout << std::endl;
                    delete p;
                }
                else
                {
                    std::cout << "Keine Patienten mehr da! Kaffepause!" << std::endl;
                }
            }
            break;
        }
        w.anzeigen();
    } while (aktion != 'x');

    return 0;
}

