
#include "BattleShip.h"
#include <cstring>

Battle_Ship::Battle_Ship() {
    size = 0;
    hits_to_destroy = 0;
    laser_bursts = 0;
    hit_taken = 0;
    sunk = false;
    symbol = '0';
    std::strcpy(ship_name, "Unknown");
    for (int i = 0; i < 5; ++i) {
        locations[i].row = -1;
        locations[i].column = -1;
    }
}

Battle_Ship::Battle_Ship(int s, int hit_destroy, int laser, const char name_value[]) {
    size = s;
    hits_to_destroy = hit_destroy;
    laser_bursts = laser;
    hit_taken = 0;
    sunk = false;
    symbol = char('0' + s);
    std::strncpy(ship_name, name_value, 39);
    ship_name[39] = '\0';
    for (int i = 0; i < 5; ++i) {
        locations[i].row = -1;
        locations[i].column = -1;
    }
}

Battle_Ship::Battle_Ship(const Battle_Ship& b) {
    size = b.size;
    hits_to_destroy = b.hits_to_destroy;
    laser_bursts = b.laser_bursts;
    hit_taken = b.hit_taken;
    sunk = b.sunk;
    symbol = b.symbol;
    std::strcpy(ship_name, b.ship_name);
    for (int i = 0; i < 5; ++i) {
        locations[i] = b.locations[i];
    }
}

Battle_Ship::~Battle_Ship() {
}

Battle_Ship& Battle_Ship::operator=(const Battle_Ship& b) {
    if (this == &b) {
        return *this;
    }

    size = b.size;
    hits_to_destroy = b.hits_to_destroy;
    laser_bursts = b.laser_bursts;
    hit_taken = b.hit_taken;
    sunk = b.sunk;
    symbol = b.symbol;
    std::strcpy(ship_name, b.ship_name);
    for (int i = 0; i < 5; ++i) {
        locations[i] = b.locations[i];
    }

    return *this;
}

void Battle_Ship::setLocation(int index, int r, int c) {
    if (index >= 0 && index < 5) {
        locations[index].row = r;
        locations[index].column = c;
    }
}

Position Battle_Ship::getLocation(int index) const {
    if (index >= 0 && index < 5) {
        return locations[index];
    }
    Position invalid;
    invalid.row = -1;
    invalid.column = -1;
    return invalid;
}

void Battle_Ship::getHit() {
    if (!sunk) {
        hit_taken++;
        if (hit_taken >= hits_to_destroy) {
            sunk = true;
        }
    }
}

bool Battle_Ship::isSunk() const {
    return sunk;
}

int Battle_Ship::getSize() const {
    return size;
}

int Battle_Ship::getHitsToDestroy() const {
    return hits_to_destroy;
}

int Battle_Ship::getLaserBursts() const {
    return laser_bursts;
}

int Battle_Ship::getHitTaken() const {
    return hit_taken;
}

char Battle_Ship::getSymbol() const {
    return symbol;
}

const char* Battle_Ship::getName() const {
    return ship_name;
}
