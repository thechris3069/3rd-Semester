#ifndef LICHTAKTION_H
#define LICHTAKTION_H

#include <string>

#include "aktion.h"

class LichtAktion : public Aktion
{
private:
    std::string m_lichtAdresse; // im Beispiel kann Fantasie walten :-)
    bool   m_an; // true: anschalten, false: ausschalten

public:
    // Konstruktor: Zeitstempel, Lichtadresse, Aktion (true: an, false: aus)
    LichtAktion(unsigned int zeit, std::string adr, bool an);

    // Implementierung der virtuellen Methode spezifisch fuer Licht
    void ausfuehren();
};

#endif // LICHTAKTION_H
