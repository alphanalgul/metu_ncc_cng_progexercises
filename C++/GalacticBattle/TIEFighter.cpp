/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#include "TIEFighter.h"
#include "Player.h"
#include <iostream>

TIE_Fighter::TIE_Fighter(): Battle_Ship(1, 1, 1, "TIE Fighter") {
}

Battle_Ship* TIE_Fighter::clone() const {
    return new TIE_Fighter(*this);
}

int TIE_Fighter::shoot(Player& shooter, Player& opponent) {
    return shooter.fireShots(opponent, laser_bursts);
}

void TIE_Fighter::printBattleShip() const {
    std::cout << "TIE Fighter" << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Hits to Destroy: " << hits_to_destroy << std::endl;
    std::cout << "Hits taken: " << hit_taken << std::endl;
    std::cout << "Laser Bursts: " << laser_bursts << std::endl;
    if (sunk) {
        std::cout << "Status: Sunk" << std::endl;
    } else {
        std::cout << "Status: Operational" << std::endl;
    }
}
