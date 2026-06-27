/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#ifndef UNTITLED_X_WING_H
#define UNTITLED_X_WING_H

#include "BattleShip.h"

class X_Wing: public Battle_Ship {
public:
    X_Wing();
    Battle_Ship* clone() const;
    int shoot(Player& shooter, Player& opponent);
    void printBattleShip() const;
};

#endif
