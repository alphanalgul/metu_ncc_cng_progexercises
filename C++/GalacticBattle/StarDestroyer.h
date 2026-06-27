/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
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
