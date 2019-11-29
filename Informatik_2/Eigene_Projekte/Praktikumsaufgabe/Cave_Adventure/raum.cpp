#include "raum.h"

Raum::Raum()
{
    ausgabetext = "NICHT ZUGEWIESENER RAUM";
//    getEntryText();
}

Raum::~Raum()
{

}

void Raum::interagieremitSpieler(Player *p)
{

}

RaumEINGANG::RaumEINGANG()
{
    ausgabetext = "Willkommen im Eingangsraum";
//        getEntryText();
}

RaumEINGANG::~RaumEINGANG()
{

}

// void RaumEINGANG::interagieremitSpieler(Player *p)
//{
//    std::cout << "Interaktion des Eingangs" << std::endl;
//}

RaumGold::RaumGold()
{
    ausgabetext = "GOLD";
    anzahlGold = (rand() % 10);
//        getEntryText();
}

void RaumGold::interagieremitSpieler(Player *p)
{
   std::cout << "Interaktion des Eingangs" << std::endl;
}

RaumGold::~RaumGold()
{

}

RaumHaendler::RaumHaendler()
{
    ausgabetext = "Ich verkaufe ";
//        getEntryText();
}

RaumHaendler::~RaumHaendler()
{

}

RaumKreatur::RaumKreatur()
{
    ausgabetext = "Kreatur in diesem Raum";
//        getEntryText();
}

RaumKreatur::~RaumKreatur()
{

}



RaumEXIT::RaumEXIT()
{
    ausgabetext = "Ausgang, endlich geschafft";
//        getEntryText();
}

RaumEXIT::~RaumEXIT()
{

}

RaumLEER::RaumLEER()
{
    ausgabetext = "Leerer Ram";
//        getEntryText();
}
RaumLEER::~RaumLEER()
{

}

void Raum::getEntryText()
{
 std::cout << ausgabetext << std::endl;

}


