/* Alphan Algul 2584639
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

void printModeMenu() {
    std::cout << "Select battle type:" << std::endl;
    std::cout << "1. The Swiftstrike (5x8)" << std::endl;
    std::cout << "2. The Starlight Clash (8x10)" << std::endl;
    std::cout << "3. Wrath of Titans (10x12)" << std::endl;
}

void waitForReady(const char message[]) {
    std::cout << message << std::endl;
    std::string line;
    std::getline(std::cin, line);
    for (int i = 0; i < 25; ++i) {
        std::cout << std::endl;
    }
}

int main() {
    std::srand(int(std::time(0)));

    char gamemode[50];
    char name1[50];
    char name2[50];

    while (true) {
        printModeMenu();
        std::cout << "Enter the battle type name or number: ";
        std::cin.getline(gamemode, 50);

        Player validator;
        if (validator.setBattleMode(gamemode)) {
            break;
        }

        std::cout << "Invalid battle type. Please choose 1, 2, 3, Swiftstrike, Starlight Clash, or Wrath of Titans." << std::endl;
    }

    std::cout << "Enter the name of Player 1: ";
    std::cin.getline(name1, 50);
    std::cout << "Enter the name of Player 2: ";
    std::cin.getline(name2, 50);

    Player player1(name1, gamemode);
    Player player2(name2, gamemode);

    waitForReady("Player 1, press Enter when Player 2 is not looking.");
    player1.deployPlayer();
    waitForReady("Player 2, press Enter when you are ready to deploy.");
    player2.deployPlayer();
    waitForReady("Both fleets are deployed. Press Enter to start the battle.");

    int start_roll = std::rand() % 2 + 1;
    Player* current_player = &player1;
    Player* opponent = &player2;

    std::cout << "Deciding who starts by generating a random number: " << start_roll << std::endl;
    if (start_roll == 2) {
        current_player = &player2;
        opponent = &player1;
    }
    std::cout << current_player->getName() << " starts!" << std::endl;

    while (!player1.allShipsSunk() && !player2.allShipsSunk()) {
        current_player->takeTurn(*opponent);

        if (opponent->allShipsSunk()) {
            break;
        }

        Player* temporary = current_player;
        current_player = opponent;
        opponent = temporary;
    }

    std::cout << std::endl << "Game over!" << std::endl;
    if (player1.allShipsSunk()) {
        std::cout << "Winner: " << player2.getName() << std::endl;
    } else {
        std::cout << "Winner: " << player1.getName() << std::endl;
    }

    std::cout << std::endl << "Initial deployments:" << std::endl;
    player1.displayOwnDeployment();
    player2.displayOwnDeployment();

    return 0;
}
