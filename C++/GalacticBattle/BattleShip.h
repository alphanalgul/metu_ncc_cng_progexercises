/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#ifndef UNTITLED_BATTLESHIP_H
#define UNTITLED_BATTLESHIP_H

class Player;

struct Position {
    int row;
    int column;
};

class Battle_Ship {
protected:
    int size;
    int hits_to_destroy;
    int laser_bursts;
    int hit_taken;
    bool sunk;
    char symbol;
    char ship_name[40];
    Position locations[5];

public:
    Battle_Ship();
    Battle_Ship(int s, int hit_destroy, int laser, const char name_value[]);
    Battle_Ship(const Battle_Ship& b);
    virtual ~Battle_Ship();
    Battle_Ship& operator=(const Battle_Ship& b);

    void setLocation(int index, int r, int c);
    Position getLocation(int index) const;
    void getHit();
    bool isSunk() const;
    int getSize() const;
    int getHitsToDestroy() const;
    int getLaserBursts() const;
    int getHitTaken() const;
    char getSymbol() const;
    const char* getName() const;

    virtual Battle_Ship* clone() const = 0;
    virtual int shoot(Player& shooter, Player& opponent) = 0;
    virtual void printBattleShip() const = 0;
};

#endif
