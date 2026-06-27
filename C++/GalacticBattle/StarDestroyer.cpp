/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#include "StarDestroyer.h"
#include "Player.h"
#include <iostream>

StarDestroyer::StarDestroyer(): Battle_Ship(5, 4, 3, "Star Destroyer") {
}

Battle_Ship* StarDestroyer::clone() const {
    return new StarDestroyer(*this);
}

int StarDestroyer::shoot(Player& shooter, Player& opponent) {
    return shooter.fireShots(opponent, laser_bursts);
}

void StarDestroyer::printBattleShip() const {
    std::cout << "Star Destroyer" << std::endl;
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
