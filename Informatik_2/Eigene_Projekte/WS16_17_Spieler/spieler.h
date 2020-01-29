#ifndef SPIELER_H
#define SPIELER_H
#include <iostream>

class Spieler
{
protected:
//private:
//public:
    int m_punkte;
public:
    Spieler(int punkte = 10)
        :m_punkte(punkte) {}
   virtual void func()
   {
       m_punkte = 500;
   }

};

class ComputerSpieler : public Spieler
{
public:
    ComputerSpieler()
        :Spieler(0) // So geht das nicht m_punkte(4), da die Klasse keine Variable m_punkte hat, nur Überklasse
    {

    }
    void ausgeben()
    {
        std::cout << "Punktzahl:" << m_punkte << std::endl;
    }
//    void func()
//    {
//        m_punkte = 500;
//    }
};

#endif // SPIELER_H
