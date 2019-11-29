Praktikum Digitaltechnik
========================

Ziel des Praktikums Digitaltechnik ist die Vertiefung der in der gleichnamigen Vorlesung gewonnenen Kenntnisse und Fertigkeiten zum Entwurf digitaler Schaltungen.

Dabei wird im Labor der Fokus auf die Prototypenentwicklung von Hardware in moderne integrierte Schaltungen gelegt.


Projekt Schrittmotorsteuerung
-----------------------------

Am Ende von fünf Versuchsterminen sollen die Teilnehmer in der Lage sein, ein digitales System in Form einer Schrittmotorsteuerung zu entwerfen. Dazu werden in jedem Praktikumsversuch verschiedene  Komponenten fuer die Steuerung vorgestellt, z.B.

  * Multiplexer
  * Binaer-zu-7-Segment Konverter
  * Addierer
  * Zaehler
  * Flankenerkennung
  * Zustandsautomat zur Auswertung eines Drehgebers
  * Kodierer für Schrittmotor


Entwurfsmethodik
----------------

Die Entwurfsmethodik integrierter Schaltungenen basiert im Wesentlichen auf Hardwarebeschreibungssprachen. Diese erlauben die Modellerung auf hohem Abstraktionsniveau. Im Praktikum werden die in der Vorlesung vorgestellten Kontrukte der international genormten Beschreibungssprache VHDL verwendet.

  
Entwicklungswerkzeuge
---------------------

Für die Realiserung von Prototypen kommen programmierbare Logikbausteine in Form von FPGAs (engl. Field Programmable Gate Arrays) der Fa. Altera zum Einsatz. Die dazu notwendigen CAE-Werkzeuge sind im wesentlichen:

  * Erstellen von VHDL-Modellen: Editor (integriert oder eigenständig)
  * Simulation von VHDL-Modellen: ModelSim (Fa. Mentor Graphics)
  * Synthese, Physikalischer Entwurf, Fertigung: Quartus (Fa. Altera)


Datenstruktur des Entwurfsverzeichnisses für Projekte
-----------------------------------------------------

Bei der Entwicklung digitaler Systeme fallen viele Daten an. Ob Quellcodedateien und Steuerdateien erstellt werden müssen oder CAE-Werkzeuge Daten erzeugen, eine klare und einheitliche Verzeichnistruktur ist unerläßlich.

```
  Verzeichnis       | Beschreibung
  --------------------------------
  ReadMe.md         | Ziele, Entwurfsmethodik, Entwicklungswerkzeuge, Datenstruktur des Entwurfsverzeichnisses
  src               | Hier befinden sich alle VHDL-Quellcodes
  pnr               | Darin werden alle Dateien von Quartusprojekten in weiteren Unterverzeichnissen abgelegt
  sim               | Darin werden alle Dateien von Simulationsprojekten in weiteren Unterverzeichnissen abgelegt
  scripts           | Dateien zur Pinbelegung, Automatisierung des Entwurfsablaufs, Initialisierung, etc.
  doc               | Verzeichnis für die Dokumentation eines Moduls, Entwurfs, Datenblätter, Oszilloskopscreenshots, etc.
  doc/ReadMe_makefile.md | Kurze Erläuterung der Verwendung von makefiles
```

Für das Praktikum Digitaltechnik kommt die nachfolgende Verzeichnisstruktur zum Einsatz:

```
  DigitaltechnikPraktikum
  |
  +---src
  |       and2gate_equation.vhd
  |       invgate_equation.vhd
  |       mux2to1_structure.vhd
  |       or2gate_equation.vhd
  |       t_mux2to1.vhd
  |       de1_mux2to1_structure.vhd
  |       binto7segment_truthtable.vhd
  |       t_binto7segment.vhd
  |       de1_binto7segment_structure.vhd
  |
  +---sim
  |   |   makefile
  |   |
  |   +---mux2to1
  |   |       makefile
  |   |       makefile.sources
  |   |
  |   \---binto7segment
  |           makefile
  |           makefile.sources
  |
  +---pnr
  |   |   makefile
  |   |
  |   +---de1_mux2to1
  |   |       de1_mux2to1_pins.tcl
  |   |       makefile
  |   |
  |   \---de1_binto7segment
  |           de1_binto7segment_pins.tcl
  |           makefile
  |
  +---scripts
  |       de1_pin_assignments_minimumio.csv
  |       de1_pin_assignments_minimumio.tcl
  |       modelsim.ini
  |       create_quartus_project_settings.tcl
  |       quartus_project_settings.tcl
  |
  \---doc
          ReadMe_makefiles.md
```
