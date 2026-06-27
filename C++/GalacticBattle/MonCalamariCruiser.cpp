/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#include "MonCalamariCruiser.h"
#include "Player.h"
#include <iostream>

MonCalamariCruiser::MonCalamariCruiser(): Battle_Ship(4, 3, 4, "Mon Calamari Cruiser") {
}

Battle_Ship* MonCalamariCruiser::clone() const {
    return new MonCalamariCruiser(*this);
}

int MonCalamariCruiser::shoot(Player& shooter, Player& opponent) {
    return shooter.fireShots(opponent, laser_bursts);
}

void MonCalamariCruiser::printBattleShip() const {
    std::cout << "Mon Calamari Cruiser" << std::endl;
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
