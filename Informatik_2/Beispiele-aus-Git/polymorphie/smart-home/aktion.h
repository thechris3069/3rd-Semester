#ifndef AKTION_H
#define AKTION_H

class Aktion
{
private:
    // Zeit in s seit 1.1.1970 zu dem Aktion ausgefuehrt werden soll
    unsigned int m_zeitstempel;

public:
    // Konstruktor
    Aktion(unsigned int zeitstempel)
        : m_zeitstempel(zeitstempel)
    {}

    // Virtueller Destruktur
    virtual ~Aktion() {}

    // getter
    unsigned int getZeitstempel() { return m_zeitstempel; }

    // Jede Aktion kann ausgefuehrt werden, allerdings ist jede
    // Aktion unterschiedlich. Allgemeine Aktionen kann man nicht
    // ausfuehren -> rein virtuelle Methode, kein Objekt kann von
    // dieser Klasse angelegt werden
    virtual void ausfuehren() = 0;
};

#endif // AKTION_H
