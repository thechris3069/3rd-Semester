/**
  * Einfach vorwaerts verkettete Liste aus Fotos
  *
  * Vorlesungsbeispiel Informatik 2
  * Claudia Meitinger
  * 17.11.2017
  *
  */

#ifndef DIASHOW_H
#define DIASHOW_H

#include "foto.h"

class Diashow
{
private:
    Foto *m_Anker; ///< Anker der verketteten Liste

public:
    // Konstruktor
    Diashow();

    // Destruktor
    ~Diashow();

    // Foto am Anfang einfuegen
    void pushFront(Foto *pF);

    // Foto am Ende einfuegen
    void pushBack(Foto *pF);

    // Anzahl der Fotos in der Diashow ermitteln
    unsigned int size(void) const;

    // Informationen ueber Fotos in der Diashow auf dem Bildschirm ausgeben
    void zeigeInfos(void) const;

    // Fotos als Diashow anzeigen
    void anzeigen(void) const;

    // Elemente der Diashow loeschen
    void clear(void);

    // Foto an beliebiger Position idx einfuegen
    void insert(Foto *pF, unsigned int idx);

    // Foto an Position idx entnehmen
    void remove(unsigned int idx);

    // Diashow in Datei speichern
    void speichern(std::string dateiname) const;

    // Diashow aus Datei laden
    void einlesen(std::string dateiname);
};

#endif // DIASHOW_H
