/*
 * Im RGB-Farbraum wird die Farbwahrnehmung durch additives Mischen der drei Grundfarben
 * rot (R), gruen (G) und blau (B) nachgebildet. In Rechnern werden diese Farbanteile
 * haeufig nicht durch einen reellen Wert zwischen 0 und 1, sondern einen ganzzahligen
 * Wert zwischen 0 und einer Zahl, die den Maximalwert repraesentiert (z.B. 255, 65535),
 * dargestellt.
 * Zudem existieren fuer einige Kombinationen (R, G, B) uebliche Farbbezeichnungen,
 * z.B. schwarz (0, 0, 0), weiss (maxWert, maxWert, maxWert), cyan (0, maxWert, maxWert).
 *
 * Definieren Sie eine C++-Klasse RgbColor, die die RGB-Anteile, den Maximalwert und
 * eine Farbbezeichnung als Datenelemente enthaelt. Nach dem Anlegen eines Objekts
 * soll der Maximalwert nicht mehr veraendert werden können. Sehen Sie Methoden zum
 * Setzen der Farbanteile sowie zum Abfragen der Farbanteile, des Maximalwerts und der
 * Farbbezeichnung vor.
 *
 * Setzen Sie den Qualifier const an allen Stellen ein, an denen er Sinn macht!
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 20.10.2017
 */

// ------------ Includes ------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// ------------ Deklaration der Klasse RgbColour ------------------
class RgbColour
{
private:
    const unsigned int m_maxWert; //< maximaler Wert, alle Farbanteile liegen zwischen 0 und m_maxWert
    unsigned int       m_rot;     //< Farbanteil rot
    unsigned int       m_gruen;   //< Farbanteil gruen
    unsigned int       m_blau;    //< Farbanteil blau
    string             m_farbe;   //< Farbbezeichnung

public:
    // Konstruktor
    RgbColour(unsigned int maxWert);

    // Methode zum Setzen der Farbanteile
    void setRgb(unsigned int r, unsigned int g, unsigned int b);

    // Methoden zum Abfragen der Daten
    // Diese veraendern keine Datenelemente und sind daher const
    int getMaxWert() const { return m_maxWert; }
    int getRot()     const { return m_rot; }
    int getGruen()   const { return m_gruen; }
    int getBlau()    const { return m_blau; }
    string getFarbe()const { return m_farbe; }
};

// ------------ Methoden der Klasse RgbColour ----------------------
RgbColour::RgbColour(unsigned int maxWert)
    : m_maxWert(maxWert) // const Daten koennen nur ueber Initialisierungsliste belegt werden
{
    setRgb(0, 0, 0); // Initialisierung der anderen Datenelemente
}

void RgbColour::setRgb(unsigned int r, unsigned int g, unsigned int b)
{
    // Einhaltung der Wertebereiche sicherstellen
    if ( r > m_maxWert )
        r = m_maxWert;
    if ( g > m_maxWert )
        g = m_maxWert;
    if ( b > m_maxWert )
        b = m_maxWert;

    // Farbanteile zuweisen
    m_rot = r;
    m_gruen = g;
    m_blau = b;

    // Farbe bestimmen (Dies ist keine vorbildliche Implementierung!!)
    if ( r == 0 && g == 0 && b == 0 )
        m_farbe = "schwarz";
    else if ( r == m_maxWert && g == m_maxWert && b == m_maxWert )
        m_farbe = "weiss";
    else if ( r == 0 && g == m_maxWert && b == m_maxWert )
        m_farbe = "cyan";
    else
        m_farbe = "unbekannt";
}


// ------------ Hauptprogramm --------------------------------------
int main()
{
    RgbColour c1(255);
    c1.setRgb(255, 255, 255);
    cout << c1.getFarbe() << ": " << c1.getRot() << ", " << c1.getBlau() << ", " << c1.getGruen() << endl;

    const RgbColour c2(65535);
//    c2.setRgb(1, 2, 3); // nicht-const Methode kann auf const-Objekt nicht aufgerufen werden
    cout << c2.getFarbe() << ": " << c2.getRot() << ", " << c2.getBlau() << ", " << c2.getGruen() << endl;

    return 0;
}

