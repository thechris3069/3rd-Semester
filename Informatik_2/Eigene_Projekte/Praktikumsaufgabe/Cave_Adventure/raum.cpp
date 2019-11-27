#include "raum.h"

Raum::Raum()
{
    ausgabetext = "NICHT ZUGEWIESENER RAUM";
//    getEntryText();
}

Raum::~Raum()
{

}

RaumEINGANG::RaumEINGANG()
{
    ausgabetext = "Willkommen im Eingangsraum";
//        getEntryText();
}

RaumGold::RaumGold()
{
    ausgabetext = "GOLD";
    anzahlGold = (rand() % 10);
//        getEntryText();
}

RaumHaendler::RaumHaendler()
{
    ausgabetext = "Ich verkaufe ";
//        getEntryText();
}

RaumKreatur::RaumKreatur()
{
    ausgabetext = "Kreatur in diesem Raum";
//        getEntryText();
}

RaumEXIT::RaumEXIT()
{
    ausgabetext = "Ausgang, endlich geschafft";
//        getEntryText();
}

RaumLEER::RaumLEER()
{
    ausgabetext = "Leerer Ram";
//        getEntryText();
}

void Raum::getEntryText()
{
 std::cout << ausgabetext << std::endl;

}


