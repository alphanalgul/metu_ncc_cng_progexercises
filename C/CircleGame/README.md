# Circle Game

## Description

This project is a console-based **Circle Game** written in **C**.

The game is played between the user and the computer on a **10×10 board**. Only the outer perimeter of the board is used as the movement path. Both the player and the computer roll dice, move around the board edges, and try to complete a full loop before the other side.

The game also includes trap locations. If a player lands on a trap, they move backward according to the trap value.

---

## Game Rules

1. The game uses a 10×10 board.
2. Only the outer border of the board is used as the path.
3. The player starts at position `(0, 0)`.
4. The computer starts at position `(9, 9)`.
5. At the beginning, both sides roll dice to decide who starts first.
6. The player chooses a trap location on the board perimeter.
7. The computer trap is generated randomly.
8. Trap values are generated randomly between 1 and 5.
9. In each round:

   * The player rolls a dice.
   * The computer rolls a dice.
   * Both move along the board perimeter.
10. If a side lands on its trap, it moves backward.
11. The first side to complete the loop wins.
12. After the game ends, the user can choose to play again.

---

## Board Representation

The program uses two separate 10×10 boards:

* One board for the player
* One board for the computer

The board is dynamically allocated using pointers.

Only the perimeter cells are active game positions. The inner cells are empty spaces.

---

## Board Symbols

| Symbol      | Meaning                 |
| ----------- | ----------------------- |
| `P`         | Player position         |
| `C`         | Computer position       |
| `*`         | Trap location           |
| `-`         | Empty perimeter cell    |
| Empty space | Inner unused board area |

---

## Features

* Console-based board game
* 10×10 board representation
* Movement along the perimeter of the board
* Random dice rolls
* Random computer trap placement
* User-selected player trap placement
* Random trap values
* Trap logic that moves players backward
* Turn-based gameplay
* Winner detection
* Replayable game loop
* Dynamic memory allocation and memory cleanup

---

## Important Constants

The program uses the following constants:

```c
#define BOARD_SIZE 10
#define PATH_LENGTH 36
```

`BOARD_SIZE` represents the size of the board.

`PATH_LENGTH` represents the number of perimeter movement positions around the 10×10 board.

---

## How to Run

### Compile

```bash
gcc CircleGame.c -o circle_game
```

### Run

On Linux/macOS:

```bash
./circle_game
```

On Windows PowerShell:

```bash
.\circle_game.exe
```

---

## Input Requirements

No external input file is required.

The program takes input from the console.

The user only needs to enter:

* Trap row
* Trap column
* Whether they want to play again

Trap input should be entered in this format:

```text
row column
```

Example:

```text
0 5
```

The trap must be placed on the outer perimeter of the board. It cannot be placed inside the board.

---

## Example Usage

```text
Welcome to the Circle Game! :)
Let's get started!

I have rolled the dice for you and you got 4!
I have rolled the dice and got 2!

----Player----
Enter trap index (row col): 0 5
Generated trap value: 3

----Computer----
Generated trap index (row col): 9 3
Generated trap value: 2
```

After that, the game displays the player and computer boards and continues round by round.

---


