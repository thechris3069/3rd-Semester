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

void RaumGold::interagieremitSpieler(Player *p) //
{
        char eingabe;
        std::cout << "moechten Sie das Gold mitnehmen? Interaktion mit E, WASD  fuer Weitergehen" << std::endl;
        std::cin >> eingabe;
        std::cin.ignore(INT_MAX, '\n');
        eingabe = toupper(eingabe);
        if  (eingabe == 'E')
        {
            p->veraendereGold(anzahlGold);
            anzahlGold = 0;
        }
        //else Cave Adventure next move
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

void RaumKreatur::interagieremitSpieler(Player *p) //Soll nur einmal ausgefuehrt werden
{
    int lebenKreatur = 30;
    int schaden = 5;
    p->veraendereLeben(schaden);
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


