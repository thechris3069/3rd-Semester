#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "wuerfel.h"

void initWuerfel(struct Wuerfel *pW, const char *farbe, int maxAugen)
{
    if (!pW)
        return;

    // Sicherstellen, dass max. Augenzahl >= 1 ist
    if(maxAugen <= 0)
        maxAugen = 1;
    pW->m_maxAugen = maxAugen;

    // Farbe kopieren
    strncpy(pW->m_farbe, farbe, LAENGE_FARBE);

    // initialen Wuerfelwert bestimmen
    wuerfeln(pW);
}

void wuerfeln(struct Wuerfel *pW)
{
    if (!pW)
        return;

    pW->m_aktAugen = rand() % pW->m_maxAugen + 1;
}

void anzeigen(struct Wuerfel w)
{
    printf("Wuerfel mit der Farbe %s zeigt %d an!\n", w.m_farbe, w.m_aktAugen);
}
