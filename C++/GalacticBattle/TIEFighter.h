
#ifndef UNTITLED_TIEFIGHTER_H
#define UNTITLED_TIEFIGHTER_H

#include "BattleShip.h"

class TIE_Fighter: public Battle_Ship {
public:
    TIE_Fighter();
    Battle_Ship* clone() const;
    int shoot(Player& shooter, Player& opponent);
    void printBattleShip() const;
};

#endif
