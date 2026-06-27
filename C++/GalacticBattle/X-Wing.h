
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
