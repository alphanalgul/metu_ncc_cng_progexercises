
#ifndef UNTITLED_STARDESTROYER_H
#define UNTITLED_STARDESTROYER_H

#include "BattleShip.h"

class StarDestroyer: public Battle_Ship {
public:
    StarDestroyer();
    Battle_Ship* clone() const;
    int shoot(Player& shooter, Player& opponent);
    void printBattleShip() const;
};

#endif
