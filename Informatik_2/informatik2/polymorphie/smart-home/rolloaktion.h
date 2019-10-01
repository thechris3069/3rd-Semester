#ifndef ROLLOAKTION_H
#define ROLLOAKTION_H

#include <string>

#include "aktion.h"

class RolloAktion : public Aktion
{
private:
    std::string m_rolloAdresse1; // im Beispiel kann Fantasie walten :-)
    std::string m_rolloAdresse2; // im Beispiel kann Fantasie walten :-)
    bool   m_hoch; // true: hochfahren, false: runterfahren

public:
    // Konstruktor: Zeitstempel, Adressen, Aktion (true: hoch, false: runter)
    RolloAktion(unsigned int zeit, std::string adr1, std::string adr2, bool hoch);

    // Implementierung der virtuellen Methode spezifisch fuer Rollo
    void ausfuehren();
};

#endif // ROLLOAKTION_H
