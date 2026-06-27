

#include "Player.h"
#include "MonCalamariCruiser.h"
#include "StarDestroyer.h"
#include "TIEFighter.h"
#include "X-Wing.h"
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>

int absValue(int value) {
    if (value < 0) {
        return -value;
    }
    return value;
}

int signValue(int value) {
    if (value < 0) {
        return -1;
    }
    if (value > 0) {
        return 1;
    }
    return 0;
}

Player::Player() {
    std::strcpy(name, "Not Provided");
    ship_count = 0;
    rows = 0;
    columns = 0;
    total_shots = 0;
    hit_count = 0;
    miss_count = 0;
    lost_cells = 0;
    lost_star_destroyers = 0;
    lost_mon_calamari = 0;
    lost_x_wings = 0;
    lost_tie_fighters = 0;
    next_round_penalty = 0;
    force_one_shot = false;
    active_shot_limit = 0;
    resetArrays();
}

Player::Player(char player_name[50], char gamemode[50]) {
    std::strncpy(name, player_name, 49);
    name[49] = '\0';
    ship_count = 0;
    rows = 0;
    columns = 0;
    total_shots = 0;
    hit_count = 0;
    miss_count = 0;
    lost_cells = 0;
    lost_star_destroyers = 0;
    lost_mon_calamari = 0;
    lost_x_wings = 0;
    lost_tie_fighters = 0;
    next_round_penalty = 0;
    force_one_shot = false;
    active_shot_limit = 0;
    resetArrays();
    setBattleMode(gamemode);
}

Player::~Player() {
    clearFleet();
}

Player::Player(const Player& p) {
    copyFrom(p);
}

Player& Player::operator=(const Player& p) {
    if (this == &p) {
        return *this;
    }
    clearFleet();
    copyFrom(p);
    return *this;
}

void Player::clearFleet() {
    for (int i = 0; i < int(fleet.size()); ++i) {
        delete fleet[i];
    }
    fleet.clear();
    ship_count = 0;
}

void Player::copyFrom(const Player& p) {
    std::strcpy(name, p.name);
    ship_count = 0;
    rows = p.rows;
    columns = p.columns;
    total_shots = p.total_shots;
    hit_count = p.hit_count;
    miss_count = p.miss_count;
    lost_cells = p.lost_cells;
    lost_star_destroyers = p.lost_star_destroyers;
    lost_mon_calamari = p.lost_mon_calamari;
    lost_x_wings = p.lost_x_wings;
    lost_tie_fighters = p.lost_tie_fighters;
    next_round_penalty = p.next_round_penalty;
    force_one_shot = p.force_one_shot;
    active_shot_limit = p.active_shot_limit;
    resetArrays();

    for (int r = 0; r < MAX_ROWS; ++r) {
        for (int c = 0; c < MAX_COLUMNS; ++c) {
            own_grid[r][c] = p.own_grid[r][c];
            incoming_grid[r][c] = p.incoming_grid[r][c];
            enemy_grid[r][c] = p.enemy_grid[r][c];
        }
    }

    for (int i = 0; i < int(p.fleet.size()); ++i) {
        Battle_Ship* copied_ship = p.fleet[i]->clone();
        fleet.push_back(copied_ship);
        ship_count++;
        for (int j = 0; j < copied_ship->getSize(); ++j) {
            Position location = copied_ship->getLocation(j);
            if (location.row >= 0 && location.column >= 0) {
                ship_grid[location.row][location.column] = copied_ship;
            }
        }
    }
}

void Player::resetArrays() {
    for (int r = 0; r < MAX_ROWS; ++r) {
        for (int c = 0; c < MAX_COLUMNS; ++c) {
            own_grid[r][c] = '.';
            incoming_grid[r][c] = '*';
            enemy_grid[r][c] = '*';
            ship_grid[r][c] = 0;
        }
    }
}

bool Player::setBattleMode(char gamemode[50]) {
    if (std::strcmp(gamemode, "1") == 0 ||
        std::strcmp(gamemode, "Swiftstrike") == 0 ||
        std::strcmp(gamemode, "The Swiftstrike") == 0) {
        setupMode(1);
        return true;
    }
    if (std::strcmp(gamemode, "2") == 0 ||
        std::strcmp(gamemode, "Starlight Clash") == 0 ||
        std::strcmp(gamemode, "The Starlight Clash") == 0) {
        setupMode(2);
        return true;
    }
    if (std::strcmp(gamemode, "3") == 0 ||
        std::strcmp(gamemode, "Wrath of Titans") == 0) {
        setupMode(3);
        return true;
    }
    return false;
}

void Player::setupMode(int mode) {
    clearFleet();
    resetArrays();

    if (mode == 1) {
        rows = 5;
        columns = 8;
        addShipByType(5);
        addShipByType(4);
        addShipByType(3);
        addShipByType(1);
        addShipByType(1);
    } else if (mode == 2) {
        rows = 8;
        columns = 10;
        addShipByType(5);
        addShipByType(5);
        addShipByType(4);
        addShipByType(4);
        addShipByType(3);
        addShipByType(3);
        addShipByType(1);
        addShipByType(1);
        addShipByType(1);
        addShipByType(1);
    } else {
        rows = 10;
        columns = 12;
        addShipByType(5);
        addShipByType(5);
        addShipByType(5);
        addShipByType(5);
        addShipByType(4);
        addShipByType(4);
        addShipByType(4);
        addShipByType(3);
        addShipByType(3);
        addShipByType(1);
        addShipByType(1);
        addShipByType(1);
        addShipByType(1);
    }
}

void Player::addShipByType(int type) {
    Battle_Ship* ship = createShipByType(type);
    if (ship != 0) {
        fleet.push_back(ship);
        ship_count++;
    }
}

Battle_Ship* Player::createShipByType(int type) const {
    if (type == 5) {
        return new StarDestroyer();
    }
    if (type == 4) {
        return new MonCalamariCruiser();
    }
    if (type == 3) {
        return new X_Wing();
    }
    if (type == 1) {
        return new TIE_Fighter();
    }
    return 0;
}

bool Player::parseCoordinate(const std::string& text, Position& position) const {
    if (text.length() < 2) {
        return false;
    }

    char row_letter = char(std::tolower(text[0]));
    if (row_letter < 'a' || row_letter >= char('a' + rows)) {
        return false;
    }

    int column_number = 0;
    for (int i = 1; i < int(text.length()); ++i) {
        if (!std::isdigit(text[i])) {
            return false;
        }
        column_number = column_number * 10 + (text[i] - '0');
    }

    if (column_number < 1 || column_number > columns) {
        return false;
    }

    position.row = row_letter - 'a';
    position.column = column_number - 1;
    return true;
}

bool Player::parseDeploymentLine(const std::string& line, Position& start, Position& end,
                                 bool& pass_requested, bool allow_pass) const {
    std::stringstream stream(line);
    std::string first;
    std::string second;
    std::string extra;
    pass_requested = false;

    if (!(stream >> first)) {
        return false;
    }

    if ((first == "pass" || first == "PASS" || first == "Pass") && allow_pass) {
        pass_requested = true;
        return true;
    }

    if (!(stream >> second)) {
        second = first;
    }

    if (stream >> extra) {
        return false;
    }

    return parseCoordinate(first, start) && parseCoordinate(second, end);
}

bool Player::buildPath(Position start, Position end, int size, Position path[]) const {
    int row_difference = end.row - start.row;
    int column_difference = end.column - start.column;
    int row_step = signValue(row_difference);
    int column_step = signValue(column_difference);
    int row_distance = absValue(row_difference);
    int column_distance = absValue(column_difference);
    int number_of_cells = 0;

    if (size == 1) {
        if (start.row != end.row || start.column != end.column) {
            return false;
        }
        path[0] = start;
        return true;
    }

    if (row_difference == 0) {
        number_of_cells = column_distance + 1;
    } else if (column_difference == 0) {
        number_of_cells = row_distance + 1;
    } else if (row_distance == column_distance) {
        number_of_cells = row_distance + 1;
    } else {
        return false;
    }

    if (number_of_cells != size) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        path[i].row = start.row + i * row_step;
        path[i].column = start.column + i * column_step;
    }

    return true;
}

bool Player::canPlaceShip(Battle_Ship* ship, Position path[], bool gift_ship) const {
    for (int i = 0; i < ship->getSize(); ++i) {
        int r = path[i].row;
        int c = path[i].column;
        if (r < 0 || r >= rows || c < 0 || c >= columns) {
            return false;
        }
        if (ship_grid[r][c] != 0) {
            return false;
        }
        if (gift_ship && incoming_grid[r][c] != '*') {
            return false;
        }
    }
    return true;
}

void Player::placeShip(Battle_Ship* ship, Position path[]) {
    for (int i = 0; i < ship->getSize(); ++i) {
        int r = path[i].row;
        int c = path[i].column;
        ship->setLocation(i, r, c);
        ship_grid[r][c] = ship;
        own_grid[r][c] = ship->getSymbol();
    }
}

bool Player::hasSpaceForShip(int size, bool gift_ship) const {
    Position path[5];
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            for (int row_step = -1; row_step <= 1; ++row_step) {
                for (int column_step = -1; column_step <= 1; ++column_step) {
                    if (row_step != 0 || column_step != 0 || size == 1) {
                        bool valid = true;
                        for (int i = 0; i < size; ++i) {
                            path[i].row = r + i * row_step;
                            path[i].column = c + i * column_step;
                            if (path[i].row < 0 || path[i].row >= rows ||
                                path[i].column < 0 || path[i].column >= columns) {
                                valid = false;
                            }
                        }
                        if (valid) {
                            Battle_Ship* test_ship = createShipByType(size);
                            bool can_place = false;
                            if (test_ship != 0) {
                                can_place = canPlaceShip(test_ship, path, gift_ship);
                                delete test_ship;
                            }
                            if (can_place) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Player::deployPlayer() {
    std::cout << std::endl << name << ", deploy your fleet secretly." << std::endl;
    std::cout << "Coordinates use row letters and column numbers, for example a1 or c4." << std::endl;
    std::cout << "Enter endpoints for each ship. Diagonal, vertical, and horizontal placements are allowed." << std::endl;

    for (int i = 0; i < int(fleet.size()); ++i) {
        deploySingleShip(fleet[i], false);
        displayOwnDeployment();
    }
}

bool Player::deploySingleShip(Battle_Ship* ship, bool gift_ship) {
    if (gift_ship && !hasSpaceForShip(ship->getSize(), true)) {
        std::cout << "There is no valid unattacked space for this ship. Passing is allowed." << std::endl;
        return false;
    }

    while (true) {
        std::cout << "Place " << ship->getName() << " (size " << ship->getSize() << ")";
        if (gift_ship) {
            std::cout << " or type pass";
        }
        std::cout << ": ";

        std::string line;
        std::getline(std::cin, line);

        Position start;
        Position end;
        bool pass_requested = false;
        if (!parseDeploymentLine(line, start, end, pass_requested, gift_ship)) {
            std::cout << "Invalid input. Use one coordinate for size 1 or two endpoints such as a1 a5." << std::endl;
            continue;
        }

        if (pass_requested) {
            return false;
        }

        Position path[5];
        if (!buildPath(start, end, ship->getSize(), path)) {
            std::cout << "Invalid placement. The endpoints must match the ship size in a straight line." << std::endl;
            continue;
        }

        if (!canPlaceShip(ship, path, gift_ship)) {
            std::cout << "Invalid placement. Ships cannot overlap";
            if (gift_ship) {
                std::cout << " and gift ships must use unattacked cells";
            }
            std::cout << "." << std::endl;
            continue;
        }

        placeShip(ship, path);
        std::cout << "Your ship is placed." << std::endl;
        return true;
    }
}

void Player::displayGrid(const char grid[MAX_ROWS][MAX_COLUMNS]) const {
    std::cout << "   ";
    for (int c = 1; c <= columns; ++c) {
        std::cout << std::setw(2) << c;
    }
    std::cout << std::endl;

    for (int r = 0; r < rows; ++r) {
        std::cout << char('a' + r) << "  ";
        for (int c = 0; c < columns; ++c) {
            std::cout << std::setw(2) << grid[r][c];
        }
        std::cout << std::endl;
    }
}

void Player::displayFleet() const {
    std::cout << "Fleet of " << name << ":" << std::endl;
    for (int i = 0; i < int(fleet.size()); ++i) {
        std::cout << std::endl << "Ship " << i + 1 << ": " << std::endl;
        fleet[i]->printBattleShip();
    }
}

void Player::displayOwnDeployment() const {
    std::cout << std::endl << "Deployment grid for " << name << ":" << std::endl;
    displayGrid(own_grid);
}

void Player::displayPublicBoardsWith(const Player& opponent) const {
    std::cout << std::endl;
    std::cout << name << " attack record";
    for (int i = 0; i < 12; ++i) {
        std::cout << " ";
    }
    std::cout << opponent.name << " attack record" << std::endl;

    std::cout << "   ";
    for (int c = 1; c <= columns; ++c) {
        std::cout << std::setw(2) << c;
    }
    std::cout << "       ";
    std::cout << "   ";
    for (int c = 1; c <= opponent.columns; ++c) {
        std::cout << std::setw(2) << c;
    }
    std::cout << std::endl;

    int max_rows = rows;
    if (opponent.rows > max_rows) {
        max_rows = opponent.rows;
    }

    for (int r = 0; r < max_rows; ++r) {
        if (r < rows) {
            std::cout << char('a' + r) << "  ";
            for (int c = 0; c < columns; ++c) {
                std::cout << std::setw(2) << enemy_grid[r][c];
            }
        } else {
            for (int c = 0; c < columns + 2; ++c) {
                std::cout << "  ";
            }
        }

        std::cout << "       ";

        if (r < opponent.rows) {
            std::cout << char('a' + r) << "  ";
            for (int c = 0; c < opponent.columns; ++c) {
                std::cout << std::setw(2) << opponent.enemy_grid[r][c];
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    displayStatistics();
    opponent.displayStatistics();
}

void Player::displayShipLosses() const {
    std::cout << "Lost Star Destroyer: " << lost_star_destroyers << std::endl;
    std::cout << "Lost Mon Calamari Cruiser: " << lost_mon_calamari << std::endl;
    std::cout << "Lost X-Wing Squadron: " << lost_x_wings << std::endl;
    std::cout << "Lost TIE Fighter: " << lost_tie_fighters << std::endl;
}

void Player::displayStatistics() const {
    std::cout << "Player: " << name << std::endl;
    std::cout << "Total Shoots: " << total_shots << std::endl;
    std::cout << "Hits: " << hit_count << std::endl;
    std::cout << "Misses: " << miss_count << std::endl;
    std::cout << "Lost: " << lost_cells << " cells" << std::endl;
    displayShipLosses();
    std::cout << std::endl;
}

Battle_Ship* Player::strongestOperativeShip() const {
    Battle_Ship* selected = 0;
    int best_burst = 0;
    for (int i = 0; i < int(fleet.size()); ++i) {
        if (!fleet[i]->isSunk() && fleet[i]->getLaserBursts() > best_burst) {
            selected = fleet[i];
            best_burst = fleet[i]->getLaserBursts();
        }
    }
    return selected;
}

int Player::baseShootingCapacity() const {
    Battle_Ship* ship = strongestOperativeShip();
    if (ship == 0) {
        return 0;
    }
    return ship->getLaserBursts();
}

int Player::ShootingCapacity() const {
    int capacity = baseShootingCapacity();
    if (capacity == 0) {
        return 0;
    }

    if (force_one_shot) {
        capacity = 1;
    } else {
        capacity = capacity - next_round_penalty;
        if (capacity < 1) {
            capacity = 1;
        }
    }

    return capacity;
}

void Player::applyShootingPenalty(int p) {
    next_round_penalty = next_round_penalty + p;
}

void Player::forceOneShotNextRound() {
    force_one_shot = true;
}

void Player::revealSunkShipOnBoards(Battle_Ship* ship, Player& shooter) {
    for (int i = 0; i < ship->getSize(); ++i) {
        Position location = ship->getLocation(i);
        if (location.row >= 0 && location.column >= 0) {
            incoming_grid[location.row][location.column] = ship->getSymbol();
            shooter.enemy_grid[location.row][location.column] = ship->getSymbol();
        }
    }
}

char Player::receiveShot(Position target, Player& shooter, bool& hit, bool& sunk_now) {
    hit = false;
    sunk_now = false;

    Battle_Ship* ship = ship_grid[target.row][target.column];
    if (ship == 0) {
        incoming_grid[target.row][target.column] = '0';
        return '0';
    }

    hit = true;
    incoming_grid[target.row][target.column] = ship->getSymbol();
    ship->getHit();
    lost_cells++;

    if (ship->isSunk() && ship->getHitTaken() == ship->getHitsToDestroy()) {
        sunk_now = true;
        if (ship->getSize() == 5) {
            lost_star_destroyers++;
        } else if (ship->getSize() == 4) {
            lost_mon_calamari++;
        } else if (ship->getSize() == 3) {
            lost_x_wings++;
        } else {
            lost_tie_fighters++;
        }
        revealSunkShipOnBoards(ship, shooter);
    }

    return ship->getSymbol();
}

int Player::fireShots(Player& opponent, int requested_shots) {
    int allowed_shots = requested_shots;
    if (active_shot_limit > 0 && active_shot_limit < allowed_shots) {
        allowed_shots = active_shot_limit;
    }

    int hits_this_action = 0;
    std::cout << std::endl << name << " shoots now (can shoot " << allowed_shots << ")." << std::endl;
    std::cout << "Type stop to finish early." << std::endl;

    for (int shot = 1; shot <= allowed_shots; ++shot) {
        while (true) {
            std::cout << "Shot " << shot << ": ";
            std::string text;
            std::getline(std::cin, text);

            if (text == "stop" || text == "STOP" || text == "Stop") {
                return hits_this_action;
            }

            Position target;
            if (!opponent.parseCoordinate(text, target)) {
                std::cout << "Invalid coordinate. Try again." << std::endl;
                continue;
            }

            if (enemy_grid[target.row][target.column] != '*') {
                std::cout << "You already shot that coordinate. Try again." << std::endl;
                continue;
            }

            bool hit = false;
            bool sunk_now = false;
            char result = opponent.receiveShot(target, *this, hit, sunk_now);
            enemy_grid[target.row][target.column] = result;
            total_shots++;

            if (hit) {
                hit_count++;
                hits_this_action++;
                std::cout << "Hit!" << std::endl;
                if (sunk_now) {
                    std::cout << "You sunk a " << opponent.ship_grid[target.row][target.column]->getName() << "!" << std::endl;
                }
            } else {
                miss_count++;
                std::cout << "Miss." << std::endl;
            }

            if (opponent.allShipsSunk()) {
                return hits_this_action;
            }
            break;
        }
    }

    return hits_this_action;
}

int Player::takeTurn(Player& opponent) {
    Battle_Ship* ship = strongestOperativeShip();
    if (ship == 0) {
        return 0;
    }

    int turn_capacity = ShootingCapacity();
    std::cout << std::endl << "Player " << name << "'s turn." << std::endl;
    std::cout << "Maximum shooting capacity: " << turn_capacity << std::endl;

    int hits_before = hit_count;
    active_shot_limit = turn_capacity;
    ship->shoot(*this, opponent);
    active_shot_limit = 0;
    int hits_this_turn = hit_count - hits_before;

    next_round_penalty = 0;
    force_one_shot = false;

    displayPublicBoardsWith(opponent);

    if (hits_this_turn > 1 && !opponent.allShipsSunk()) {
        std::cout << "Player " << name << " had " << hits_this_turn << " hits. Time to open the gift." << std::endl;
        openGift(opponent);
    }

    return hits_this_turn;
}

void Player::openGift(Player& opponent) {
    int gift_dice = std::rand() % 100 + 1;

    if (gift_dice <= 10) {
        std::cout << "Lucky! Gift number 1 is awarded." << std::endl;
        int ship_dice = std::rand() % 100 + 1;
        int ship_type = 1;
        if (ship_dice <= 10) {
            ship_type = 5;
        } else if (ship_dice <= 30) {
            ship_type = 4;
        } else if (ship_dice <= 60) {
            ship_type = 3;
        }

        Battle_Ship* new_ship = createShipByType(ship_type);
        if (new_ship == 0) {
            return;
        }

        std::cout << "You are awarded a " << new_ship->getName() << "." << std::endl;
        if (deploySingleShip(new_ship, true)) {
            fleet.push_back(new_ship);
            ship_count++;
        } else {
            delete new_ship;
            std::cout << "No ship was added." << std::endl;
        }
    } else if (gift_dice <= 40) {
        std::cout << "Lucky! Gift number 2 is awarded. Shoot one more time." << std::endl;
        fireShots(opponent, 1);
    } else if (gift_dice <= 60) {
        std::cout << "Lucky! Gift number 3 is awarded. Enemy shooting capacity is reduced by one next round." << std::endl;
        opponent.applyShootingPenalty(1);
    } else if (gift_dice <= 80) {
        std::cout << "Lucky! Gift number 4 is awarded. Enemy can only shoot once next round." << std::endl;
        opponent.forceOneShotNextRound();
    } else {
        std::cout << "Lucky! Gift number 5 is awarded. Go for one more round of shooting." << std::endl;
        Battle_Ship* ship = strongestOperativeShip();
        if (ship != 0) {
            active_shot_limit = ShootingCapacity();
            ship->shoot(*this, opponent);
            active_shot_limit = 0;
        }
    }
}

bool Player::allShipsSunk() const {
    if (fleet.size() == 0) {
        return true;
    }
    for (int i = 0; i < int(fleet.size()); ++i) {
        if (!fleet[i]->isSunk()) {
            return false;
        }
    }
    return true;
}

const char* Player::getName() const {
    return name;
}
