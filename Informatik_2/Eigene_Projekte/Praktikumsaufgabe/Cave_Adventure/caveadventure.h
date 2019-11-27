#ifndef CAVEADVENTURE_H
#define CAVEADVENTURE_H
#include "player.h"
#include "world.h"


class CaveAdventure
{
public:
    CaveAdventure(std::string spielername, unsigned int groesseSpielfeld = 15);
    ~CaveAdventure();
    World m_world;
    void nextMove();

    Player m_player;

protected:
    void goldraum();
    void kreatur();
private:
};

#endif // CAVEADVENTURE_H
