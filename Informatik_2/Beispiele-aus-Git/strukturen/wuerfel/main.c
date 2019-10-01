#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "wuerfel.h"

#define ANZAHL_WUERFEL 3

int main()
{
    struct Wuerfel w[ANZAHL_WUERFEL];

    initWuerfel(&w[0], "gruen", 20);
    initWuerfel(&w[1], "gelb", 6);
    initWuerfel(&w[2], "rot", 10);

     // Pseudo-Zufallszahlengenerator initialisieren
    srand(time(0));

    // 10x wuerfeln
    for (unsigned int i = 0; i < 10; i++)
    {
        // und zwar jeden Wuerfel
        for (unsigned int j = 0; j < ANZAHL_WUERFEL; j++)
        {
            wuerfeln(&w[j]);
            anzeigen(w[j]);
        }
        printf("----------------------\n");
    }

    return 0;
}
