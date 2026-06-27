# Drop Dead Dice Game

## Description

This project is a console-based **Drop Dead dice game** written in **C**.

The game is played between the user and the computer. Each player rolls five dice and tries to collect points. However, if any die shows `2` or `5`, that die is removed from future rolls and the score for that roll becomes `0`.

A player's turn continues until all five dice are removed. This situation is called **Drop Dead**.

The player with the highest total score after all rounds wins.

This project was written as a C programming exercise to practice:

* Functions
* Loops
* Conditional statements
* Random number generation
* Score tracking
* Turn-based game logic
* Console-based user interaction

---

## Game Rules

1. The user enters the number of rounds.
2. The computer and the user each roll one die to decide who starts first.
3. In each round, both players take one full turn.
4. At the start of a turn, the player rolls five dice.
5. If none of the dice are `2` or `5`:

   * The sum of the dice is added to the player's score.
6. If any die is `2` or `5`:

   * Those dice are excluded from future rolls.
   * The score for that roll becomes `0`.
7. The player continues rolling with the remaining dice.
8. When all five dice are excluded, the player is **Drop Dead**.
9. After all rounds are completed, the total scores are compared.
10. The player with the higher score wins.

---

## Scoring Logic

| Situation                        | Result                            |
| -------------------------------- | --------------------------------- |
| No dice show `2` or `5`          | Sum of dice is added to the score |
| One or more dice show `2` or `5` | Score for that roll is `0`        |
| All dice are excluded            | Player becomes **Drop Dead**      |

Example:

```text
Dice: 1 3 4 6 6
Score: 20
```

Since there is no `2` or `5`, the sum is added.

Example:

```text
Dice: 1 2 4 5 6
Score: 0
```

Since there is a `2` and a `5`, the score for this roll is `0`, and those dice are excluded.

---

## Features

* User-defined number of rounds
* Computer vs player gameplay
* Random dice rolling
* Automatic detection of dice showing `2` or `5`
* Automatic dice exclusion
* Score calculation for each roll
* Total score tracking
* Round-by-round score display
* Final winner announcement

---


---

## How to Run

### Compile

```bash
gcc CDropDeadGame.c -o drop_dead_game
```

### Run

On Linux/macOS:

```bash
./drop_dead_game
```

On Windows PowerShell:

```bash
.\drop_dead_game.exe
```

---

## Input Requirements

No external input file is required.

The program takes input from the console.

The user only needs to enter the number of rounds.

Example:

```text
How many rounds would you like to play? 3
```

---

## Example Usage

```text
Welcome to the Drop Dead game.
Let's get started!
How many rounds would you like to play? 2

Round 1 -- My Turn:
I got:
[Dice 1]: 1
[Dice 2]: 2    Dice 2 is excluded
[Dice 3]: 4
[Dice 4]: 5    Dice 4 is excluded
[Dice 5]: 6
My score: 0
Total score: 0

Round 1 -- Your Turn:
Are you ready to play!
I rolled and you got:
[Dice 1]: 1
[Dice 2]: 3
[Dice 3]: 4
[Dice 4]: 6
[Dice 5]: 6
Your score: 20
Total score: 20
```

---
