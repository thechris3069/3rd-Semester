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
 * Patienten mit Hilfe eines Containers der C++-Standardbibliothek
 * hinterlegt werden. Sehen Sie Funktionalitaeten vor, mit denen neue
 * Patientendaten hinzugefuegt werden koennen und die Informationen
 * ueber den naechsten zu behandelnden Patienten entnommen werden koennen.
 * In einer ersten Variante soll die Dringlichkeit nicht beruecksichtigt
 * werden => Nutzung des Containers "queue" ist moeglich.
 * (Doku z.B. http://en.cppreference.com/w/cpp/container/queue, letzter Zugriff: 7.11.2017)
 *
 * Vorlesungsbeispiel Informatik 2
 * Claudia Meitinger
 * 7.11.2017
 */

#include <iostream>
#include <string>
#include <queue>

// ----- Klasse Patient -----
// (typischerweise in patient.h)
class Patient
{
private:
    std::string       m_name;
    unsigned int m_dringlichkeit; // 1: sehr dringend .. 5: nicht dringend
    std::string       m_behandlungsraum;
public:
    // Konstruktor
    Patient(std::string name, unsigned int dringlichkeit, std::string behandlungsraum);

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

// ----- Hauptprogramm -----
int main()
{
    char aktion = 'x';
    std::queue<Patient> w; // "W"arteschlange

    // Automatischer Test
    // -- Patienten dazufuegen
    w.push(Patient("Alice", 3, "B1.1"));
    w.push(Patient("Bob", 3, "B1.2"));
    w.push(Patient("Chris", 3, "B1.3"));
    // -- einen Patienten behandeln
    if (!w.empty())
    {
        Patient p = w.front(); // Erstes Element kopieren
        w.pop(); // Erstes Element loeschen
        std::cout << "Behandelt wird: ";
        p.anzeigen();
        std::cout << std::endl;
    }
    // -- Patienten dazufuegen
    w.push(Patient("Dennis", 1, "B1.4"));
    w.push(Patient("Emil", 1, "B1.5"));
    w.push(Patient("Franz", 4, "B1.6"));
    w.push(Patient("Gustav", 2, "B1.6"));
    w.push(Patient("Heinz", 5, "B1.6"));
    // -- alle verbleibenden Patienten behandeln
    while (!w.empty())
    {
        Patient p = w.front(); // Erstes Element kopieren
        w.pop(); // Erstes Element loeschen
        std::cout << "Behandelt wird: ";
        p.anzeigen();
        std::cout << std::endl;
    }

    // Interaktive Variante
    // -- Warteschlange leeren
    while(!w.empty())
        w.pop();
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
            w.push(Patient(name, dringlichkeit, zimmer));
        }
            break;
        case '2': // Patient entnehmen
            if (!w.empty())
            {
                Patient p = w.front(); // Erstes Element kopieren
                w.pop(); // Erstes Element loeschen
                std::cout << "An der Reihe ist:" << std::endl;
                p.anzeigen();
                std::cout << std::endl;
            }
            else
            {
                std::cout << "Keine Patienten mehr da! Kaffepause!" << std::endl;
            }
            break;
        }
    } while (aktion != 'x');

    return 0;
}
