/*
 * Klasse zur Steuerung eines Bonbonautomaten bestehend aus zwei LEDs (gruen/rot),
 * einem Taster, einem LCD-Display, einer Auswurf-Einheit und einer Sensorik zur
 * Erfassung des Fuellstandes (vgl. https://cloud.hs-augsburg.de/index.php/s/4cQeJpgW2Zit9JA).
 * Auf dem LCD-Display werden Anweisungen zur Bedienung gegeben.
 * Wenn mindestens drei Bonbons vorhanden sind, leuchtet die gruene LED, sonst die rote LED.
 * Wird der Taster gedrückt, so wird die Auswurf-Einheit bewegt.
 *
 * Vorlesungsbeispiel Informatik 2 WS 2017/18
 *
 * Claudia Meitinger
 * 17.10.2017
 */

#ifndef BONBONAUTOMAT_H
#define BONBONAUTOMAT_H

#include "led.h"
#include "taster.h"
#include "lcddisplay.h"
#include "fuellstandserfassung.h"
#include "auswurfeinheit.h"

class Bonbonautomat
{
private:
    Led                  m_ledRot;
    Led                  m_ledGruen;
    Taster               m_taster;
    LcdDisplay           m_lcd;
    Fuellstandserfassung m_fuellstand;
    Auswurfeinheit       m_auswurf;

public:
    Bonbonautomat();

    // zyklische Abarbeitung: Abfrage Fuellstand und Taster,
    // Ansteuerung Leds, LCD und Auswurfeinheit
    void ausfuehren();
};

#endif // BONBONAUTOMAT_H
