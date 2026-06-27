/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#define MAX_ROWS 12
#define MAX_COLUMNS 12

#include "BattleShip.h"
#include <string>
#include <vector>

class Player {
private:
    char name[50];
    std::vector<Battle_Ship*> fleet;
    int ship_count;
    int rows;
    int columns;
    char own_grid[MAX_ROWS][MAX_COLUMNS];
    char incoming_grid[MAX_ROWS][MAX_COLUMNS];
    char enemy_grid[MAX_ROWS][MAX_COLUMNS];
    Battle_Ship* ship_grid[MAX_ROWS][MAX_COLUMNS];
    int total_shots;
    int hit_count;
    int miss_count;
    int lost_cells;
    int lost_star_destroyers;
    int lost_mon_calamari;
    int lost_x_wings;
    int lost_tie_fighters;
    int next_round_penalty;
    bool force_one_shot;
    int active_shot_limit;

    void clearFleet();
    void copyFrom(const Player& p);
    void resetArrays();
    void setupMode(int mode);
    void addShipByType(int type);
    Battle_Ship* createShipByType(int type) const;
    bool parseCoordinate(const std::string& text, Position& position) const;
    bool parseDeploymentLine(const std::string& line, Position& start, Position& end,
                             bool& pass_requested, bool allow_pass) const;
    bool buildPath(Position start, Position end, int size, Position path[]) const;
    bool canPlaceShip(Battle_Ship* ship, Position path[], bool gift_ship) const;
    void placeShip(Battle_Ship* ship, Position path[]);
    bool hasSpaceForShip(int size, bool gift_ship) const;
    void displayGrid(const char grid[MAX_ROWS][MAX_COLUMNS]) const;
    void displayShipLosses() const;
    void revealSunkShipOnBoards(Battle_Ship* ship, Player& shooter);
    Battle_Ship* strongestOperativeShip() const;
    int baseShootingCapacity() const;

public:
    Player();
    Player(char player_name[50], char gamemode[50]);
    ~Player();
    Player(const Player& p);
    Player& operator=(const Player& p);

    bool setBattleMode(char gamemode[50]);
    void deployPlayer();
    bool deploySingleShip(Battle_Ship* ship, bool gift_ship);
    void displayFleet() const;
    void displayOwnDeployment() const;
    void displayPublicBoardsWith(const Player& opponent) const;
    void displayStatistics() const;
    int ShootingCapacity() const;
    void applyShootingPenalty(int p);
    void forceOneShotNextRound();
    int fireShots(Player& opponent, int requested_shots);
    int takeTurn(Player& opponent);
    void openGift(Player& opponent);
    char receiveShot(Position target, Player& shooter, bool& hit, bool& sunk_now);
    bool allShipsSunk() const;
    const char* getName() const;
};

#endif
