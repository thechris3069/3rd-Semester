/**
  * Klasse Foto als Knoten einer einfach vorwaerts verketteten Liste
  *
  * Vorlesungsbeispiel Informatik 2
  * Claudia Meitinger
  * 17.11.2017
  *
  */

#ifndef FOTO_H
#define FOTO_H

#include <string>
#include <iostream>

class Foto
{
private:
    std::string  m_Beschreibung;  ///< Beschreibung des Foto-Inhalts
    std::string  m_Fotograf;      ///< Name des Fotografs
    std::string  m_Dateiname;     ///< Datei, die Foto enthaelt
    Foto *       m_pNext;         ///< next-Zeiger fuer Verkettung
public:
    // Konstruktor
    Foto(std::string beschreibung, std::string fotograf, std::string dateiname)
    {
        m_Beschreibung = beschreibung;
        m_Fotograf = fotograf;
        m_Dateiname = dateiname;
        m_pNext = nullptr;
    }

    // Zugriff auf next-Zeiger
    void setNext(Foto *next)
    {
        m_pNext = next;
    }

    Foto *getNext(void) const
    {
        return m_pNext;
    }

    // Anzeige des Fotos mit dem Bildbetrachter eog
    void show(void)
    {
        std::cout << "Angezeigt wird ein Foto von " << m_Fotograf << ":" << std::endl;
        std::cout << "'" << m_Beschreibung << "'" << std::endl;
        // TODO: Foto tatsaechlich anzeigen
    }

    // Getter-Methoden
    std::string getBeschreibung() { return m_Beschreibung; }
    std::string getDateiname()    { return m_Dateiname;    }
    std::string getFotograf()     { return m_Fotograf;     }
};

#endif // FOTO_H
