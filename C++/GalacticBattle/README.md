# Galactic Battle

## Description

This project is a **Galactic Battle game** written in **C++**.

The program is a console-based battleship-style game with a space battle theme. Two players deploy their fleets on a grid and take turns shooting at each other.

---

## Program Behavior

The program starts by asking the user to select a battle mode.

The available battle modes are:

1. The Swiftstrike
2. The Starlight Clash
3. Wrath of Titans

Then, the program asks for the names of Player 1 and Player 2.

Each player secretly deploys their fleet on their own grid.

After both fleets are deployed, the game randomly chooses which player starts.

Players then take turns shooting at each other until one player's entire fleet is destroyed.

---

## Features

* Two-player console game
* Three different battle modes
* Different grid sizes depending on battle mode
* Multiple spaceship types
* Manual ship deployment
* Turn-based shooting system
* Hit and miss tracking
* Ship sinking system
* Player statistics
* Random starting player
* Gift system after multiple successful hits
* Uses inheritance and polymorphism for ship behavior

---

## Battle Modes

The program includes three battle modes:

| Mode | Name                | Grid Size |
| ---- | ------------------- | --------- |
| `1`  | The Swiftstrike     | `5 x 8`   |
| `2`  | The Starlight Clash | `8 x 10`  |
| `3`  | Wrath of Titans     | `10 x 12` |

The selected mode determines the grid size and the number of ships each player receives.

---

## Ship Types

The game includes these spaceship types:

* Star Destroyer
* Mon Calamari Cruiser
* X-Wing Squadron
* TIE Fighter

Each ship has different properties such as:

* Size
* Hits required to destroy it
* Laser burst capacity
* Symbol on the grid

---

## Class Structure

The main base class is `Battle_Ship`.

Derived ship classes include:

```text
Battle_Ship
├── StarDestroyer
├── MonCalamariCruiser
├── X_Wing
└── TIE_Fighter
```

The `Player` class manages:

* Player name
* Fleet
* Own grid
* Enemy attack grid
* Incoming attack grid
* Shooting statistics
* Ship deployment
* Turn handling

---

## Project Structure

```text
GalacticBattle/
├── BattleShip.h
├── BattleShip.cpp
├── Player.h
├── Player.cpp
├── StarDestroyer.h
├── StarDestroyer.cpp
├── MonCalamariCruiser.h
├── MonCalamariCruiser.cpp
├── X-Wing.h
├── X-Wing.cpp
├── TIEFighter.h
├── TIEFighter.cpp
├── main.cpp
└── README.md
```

---

## How to Run

### Compile

Compile all `.cpp` files together:

```bash
g++ main.cpp BattleShip.cpp Player.cpp StarDestroyer.cpp MonCalamariCruiser.cpp TIEFighter.cpp X-Wing.cpp -o galactic_battle
```

### Run

On Linux/macOS:

```bash
./galactic_battle
```

On Windows PowerShell:

```bash
.\galactic_battle.exe
```

---

## Example Usage

```text
Select battle type:
1. The Swiftstrike (5x8)
2. The Starlight Clash (8x10)
3. Wrath of Titans (10x12)

Enter the battle type name or number:
```

Example input:

```text
1
```

Then the program asks for player names:

```text
Enter the name of Player 1:
Enter the name of Player 2:
```

After that, each player deploys their ships secretly.

---

## Coordinate Format

Coordinates use row letters and column numbers.

Example:

```text
a1
c4
d8
```

For ships with size greater than 1, the player enters two endpoints.

Example:

```text
a1 a5
```

This places a ship from `a1` to `a5`.

Ships can be placed:

* Horizontally
* Vertically
* Diagonally

---

## Game Rules

* Each player deploys their own fleet.
* Players take turns shooting at the opponent.
* A shot can either hit or miss.
* A ship sinks when it takes enough hits.
* The game ends when all ships of one player are sunk.
* The other player becomes the winner.

---

## Gift System

If a player gets more than one hit in a turn, the program may activate a gift.

Possible gift effects include:

* Adding a new ship
* Shooting one more time
* Reducing the opponent's shooting capacity
* Forcing the opponent to shoot only once next round
* Giving the player another round of shooting

---

## Example Output

```text
Deciding who starts by generating a random number: 1
Player1 starts!

Player Player1's turn.
Maximum shooting capacity: 3
Shot 1:
```

At the end of the game:

```text
Game over!
Winner: Player1
```

---

