
#include "X-Wing.h"
#include "Player.h"
#include <iostream>

X_Wing::X_Wing(): Battle_Ship(3, 2, 2, "X-Wing Squadron") {
}

Battle_Ship* X_Wing::clone() const {
    return new X_Wing(*this);
}

int X_Wing::shoot(Player& shooter, Player& opponent) {
    return shooter.fireShots(opponent, laser_bursts);
}

void X_Wing::printBattleShip() const {
    std::cout << "X-Wing Squadron" << std::endl;
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
