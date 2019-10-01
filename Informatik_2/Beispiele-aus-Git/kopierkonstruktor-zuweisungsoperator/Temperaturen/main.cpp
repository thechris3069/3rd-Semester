#include <iostream>
using namespace std;

enum TemperaturEinheit
{
    TEMP_FAHRENHEIT,
    TEMP_CELSIUS
};

// In der Klasse TemperaturMesswerte koennen m_MaxAnzahl Temperaturen
// in der Einheit TemperaturEinheit hinterlegt werden.
// Zu Beginn wird Speicher fuer m_MaxAnzahl Messwerte reserviert und
// die Startadresse des Speicherbereichs in m_Temperaturen hinterlegt
// Neue Messwerte werden an die Stelle m_NextIdx in das Feld
// m_Temperaturen geschrieben. m_Anzahl zaehlt mit, wie viele gueltige
// Temperaturwerte bereits geschrieben wurden.
// Sollen mehr als m_MaxAnzahl Temperaturwerte hinterlegt werden, so wird
// das Feld wieder von vorne befuellt, d.h. m_NextIdx beginnt wieder bei 0
// waehrend m_Anzahl den Wert m_MaxAnzahl beibehaelt.
// Mit der Methode umrechnen, werden alle Eintraege im Feld m_Temperaturen
// in die uebergebene Ziel-Einheit umgerechnet, falls die Werte nicht schon
// so vorliegen.
// Die Methode mittelwert ermittelt den Mittelwert der Temperaturen im
// Feld m_Temperaturen.
// Die Methode ausgeben gibt die Messwerte und deren Mittelwert mit Einheit
// auf dem Bildschirm aus.
class TemperaturMesswerte
{
private:
    double *          m_Temperaturen = nullptr;
    unsigned int      m_MaxAnzahl    = 0;
    unsigned int      m_Anzahl       = 0;
    unsigned int      m_NextIdx      = 0;
    TemperaturEinheit m_Einheit      = TEMP_CELSIUS;

    // Methode zum Umrechnen des uebergebenen Temperatur-Messwertes
    // von Einheit einheitIst in Einheit einheitSoll
    // Rueckgabe: Wert in der Ziel-Einheit einheitSoll
    double umrechnen(double wert, TemperaturEinheit einheitIst, TemperaturEinheit einheitSoll)
    {
        // Einheiten sind gleich -> keine Umrechnung noetig
        if (einheitIst == einheitSoll) {
            return wert;
        }
        // Fahrenheit -> Celsius
        if (einheitIst == TEMP_FAHRENHEIT && einheitSoll == TEMP_CELSIUS) {
            return (wert - 32.0) * 5.0 / 9.0;
        }
        // Celsius -> Fahrenheit
        if (einheitIst == TEMP_CELSIUS && einheitSoll == TEMP_FAHRENHEIT) {
            return wert * 1.8 + 32.0;
        }
    }

public:
    // Allgemeiner Konstruktor
    // - reserviert Speicher fuer maxAnzahl Messwerte
    TemperaturMesswerte(unsigned int maxAnzahl)
    {
        if (maxAnzahl == 0) {
            cerr << "Fehler: Ungueltige Anzahl! Kein gueltiges Objekt!" << endl;
            return; // besser: Exception!
        }

        // Speicher fuer Messwerte anfordern
        m_Temperaturen = new double[maxAnzahl];
        // Speichergroesse hinterlegen
        if (m_Temperaturen) {
            m_MaxAnzahl = maxAnzahl;
        }
    }

    // Kopierkonstruktor
    // - erstellt eine tiefe Kopie der hinterlegten Daten
    TemperaturMesswerte(const TemperaturMesswerte &other)
    {
        // Speicher fuer Messwerte anfordern
        // Groesse entspricht der Groesse des zu kopierenden
        // Objektes other
        m_Temperaturen = new double[other.m_MaxAnzahl];
        // Speichergroesse hinterlegen
        if (m_Temperaturen) {
            // Unkritische Daten kopieren
            m_MaxAnzahl = other.m_MaxAnzahl;
            m_Anzahl    = other.m_Anzahl;
            m_NextIdx   = other.m_NextIdx;
            m_Einheit   = other.m_Einheit;

            // Feldinhalt umkopieren
            for (unsigned int i = 0; i < m_Anzahl; i++) {
                m_Temperaturen[i] = other.m_Temperaturen[i];
            }
        }
    }

    // Zuweisungsoperator
    TemperaturMesswerte &operator=(const TemperaturMesswerte &other)
    {
        // Bei Selbstzuweisung nichts tun
        if (this != &other) {
            // Alten Speicher freigeben
            delete[] m_Temperaturen;

            // Speicher fuer Messwerte anfordern
            // Groesse entspricht der Groesse des zu kopierenden
            // Objektes other
            m_Temperaturen = new double[other.m_MaxAnzahl];
            // Speichergroesse hinterlegen
            if (m_Temperaturen) {
                // Unkritische Daten kopieren
                m_MaxAnzahl = other.m_MaxAnzahl;
                m_Anzahl    = other.m_Anzahl;
                m_NextIdx   = other.m_NextIdx;
                m_Einheit   = other.m_Einheit;

                // Feldinhalt umkopieren
                for (unsigned int i = 0; i < m_Anzahl; i++) {
                    m_Temperaturen[i] = other.m_Temperaturen[i];
                }
            }
        }

        // Kettenzuweisung ermoeglichen
        return *this;
    }

    // Destruktor
    // - gibt Speicher, der im Konstruktor reserviert wurde, frei
    ~TemperaturMesswerte()
    {
        delete[] m_Temperaturen;
    }

    // Fuegt Messwert zum Feld hinzu und nimmt u.U. Umrechnung vor.
    // Sind bereits m_MaxAnzahl Messwerte vorhanden, so werden
    // die aeltesten Messwerte ueberschrieben.
    void hinzufuegen(double wert, TemperaturEinheit einheit)
    {
        m_Temperaturen[m_NextIdx] = umrechnen(wert, einheit, m_Einheit);
        m_NextIdx++;
        m_Anzahl++;
        if (m_NextIdx >= m_MaxAnzahl)
            m_NextIdx = 0;
        if (m_Anzahl > m_MaxAnzahl)
            m_Anzahl = m_MaxAnzahl;
    }

    // Rechnet alle hinterlegten Messwerte in die angegebene
    // Einheit einheitSoll um
    void umrechnen(TemperaturEinheit einheitSoll)
    {
        if (einheitSoll != m_Einheit) {
            for (unsigned int i = 0; i < m_Anzahl; i++) {
                m_Temperaturen[i] = umrechnen(m_Temperaturen[i], m_Einheit, einheitSoll);
            }
            m_Einheit = einheitSoll;
        }
    }

    // Bestimmt den Mittelwert der hinterlegten Temperaturen
    // und gibt diesen zurueck
    double getMittelwert()
    {
        double summe = 0.0;
        for (unsigned int i = 0; i < m_Anzahl; i++) {
            summe += m_Temperaturen[i];
        }
        return summe / m_Anzahl;
    }

    // Informationen zu den Messwerten auf dem Bildschirm ausgeben
    void anzeigen()
    {
        cout << "Temperatur-Messwerte in ";
        switch (m_Einheit)
        {
        case TEMP_CELSIUS:
            cout << "Celsius";
            break;
        case TEMP_FAHRENHEIT:
            cout << "Fahrenheit";
            break;
        }
        cout << endl;
        for (unsigned int i = 0; i < m_Anzahl; i++) {
            cout << "   " << m_Temperaturen[i] << endl;
        }
        cout << "Mittelwert: " << getMittelwert() << endl;
    }
};

int main()
{
    TemperaturMesswerte mw(5);

    mw.hinzufuegen(25.3, TEMP_CELSIUS);
    mw.hinzufuegen(21.7, TEMP_CELSIUS);
    mw.hinzufuegen(100.0, TEMP_FAHRENHEIT);
    mw.hinzufuegen(20.9, TEMP_CELSIUS);

    cout << "---- Original ----" << endl;
    mw.anzeigen();

    TemperaturMesswerte mwKopie(mw);
    cout << "---- Kopie ----" << endl;
    mwKopie.anzeigen();

    cout << endl << "Kopie wird in Fahrenheit umgerechnet..." << endl << endl;
    mwKopie.umrechnen(TEMP_FAHRENHEIT);

    cout << "---- Original ----" << endl;
    mw.anzeigen();
    cout << "---- Kopie ----" << endl;
    mwKopie.anzeigen();

    TemperaturMesswerte mw2(10);
    mw2.hinzufuegen(-2.3, TEMP_CELSIUS);
    mw2.hinzufuegen(0.0, TEMP_FAHRENHEIT);
    mw2.hinzufuegen(-4.3, TEMP_CELSIUS);

    cout << "---- FELD 1 ----" << endl;
    mw.anzeigen();

    cout << "---- FELD 2 ----" << endl;
    mw2.anzeigen();

    cout << endl << "Feld 1 wird in Feld 2 kopiert..." << endl;
    mw2 = mw;
    cout << "Feld 2 wird in Fahrenheit umgerechnet..." << endl << endl;
    mw2.umrechnen(TEMP_FAHRENHEIT);

    cout << "---- FELD 1 ----" << endl;
    mw.anzeigen();

    cout << "---- FELD 2 ----" << endl;
    mw2.anzeigen();

    return 0;
}
