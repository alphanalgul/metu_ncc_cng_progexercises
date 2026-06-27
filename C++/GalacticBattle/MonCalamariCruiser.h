
#ifndef UNTITLED_MONCALAMARICRUISER_H
#define UNTITLED_MONCALAMARICRUISER_H

#include "BattleShip.h"

class MonCalamariCruiser: public Battle_Ship {
public:
   MonCalamariCruiser();
   Battle_Ship* clone() const;
   int shoot(Player& shooter, Player& opponent);
   void printBattleShip() const;
};

#endif
