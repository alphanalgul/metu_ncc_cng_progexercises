# Crag Dice Game

## Description

This project is a console-based **Crag dice game** written in **C**.

The game is played between the user and the computer. In each round, both sides roll three dice and receive points based on Crag scoring rules. The player can choose to re-roll one die by keeping two dice. The computer also has a simple re-roll strategy.

The player with the highest total score after all rounds wins.

---

## Game Rules

1. The user enters the number of rounds.
2. The player and computer each roll one die to decide who starts.
3. If both roll the same value, the dice are rolled again.
4. In each round:

   * The player rolls three dice.
   * The player can choose whether to re-roll.
   * If the player re-rolls, they keep two dice and re-roll the remaining die.
   * The computer rolls three dice.
   * The computer may re-roll one die if it is close to getting a high straight.
5. Scores are calculated according to the Crag scoring table.
6. The total score is updated after every round.
7. After the final round, the program announces the winner.

---

## Scoring Categories

Scores are checked from highest priority to lowest priority.

| Category        | Description                        |       Score | Example      |
| --------------- | ---------------------------------- | ----------: | ------------ |
| Crag            | A pair with a total sum of 13      |          50 | `6 6 1`      |
| Thirteen        | Total dice sum is exactly 13       |          26 | `3 4 6`      |
| Three of a Kind | All three dice have the same value |          25 | `4 4 4`      |
| Low Straight    | Dice are `1 2 3`                   |          20 | `1 2 3`      |
| High Straight   | Dice are `4 5 6`                   |          20 | `4 5 6`      |
| Odd Straight    | Dice are `1 3 5`                   |          20 | `1 3 5`      |
| Even Straight   | Dice are `2 4 6`                   |          20 | `2 4 6`      |
| Sum             | Any other dice combination         | Sum of dice | `2 3 5 = 10` |

---

## Player Re-Roll Logic

After rolling three dice, the player is asked:

```text
Shall I roll for you(Y/N)?
```

If the player enters `Y`, they choose two dice to keep.

Example:

```text
Which ones do you want to keep? 1 3
```

This means dice 1 and dice 3 are kept, and dice 2 is re-rolled.

The player can re-roll only once per turn.

---

## Computer Re-Roll Logic

The computer uses a simple strategy.

It only re-rolls when it is close to getting a **High Straight**:

```text
4 5 6
```

For example:

* If the computer has `4 5 X`, it re-rolls the third die.
* If the computer has `4 X 6`, it re-rolls the second die.
* If the computer has `X 5 6`, it re-rolls the first die.

---

## Features

* User-defined number of rounds
* Dice rolling using random number generation
* Player re-roll choice
* Simple computer re-roll strategy
* Crag score calculation
* Round-by-round score display
* Final winner announcement
* Console-based interactive gameplay

## How to Run

### Compile

```bash
gcc CCragGame.c -o crag_game
```

### Run

On Linux/macOS:

```bash
./crag_game
```

On Windows PowerShell:

```bash
.\crag_game.exe
```

---



## Example Usage

```text
Welcome to Crag game
Let's get started!
How many rounds would you like to play: 3

I have rolled the dice and got 2!
I have rolled the dice for you and you got 5!

Round 1 -- Your Turn:
=============================
You got--->[Dice 1]: 1 [Dice 2]: 2 [Dice 3]: 2
Shall I roll for you(Y/N)?: Y
Which ones do you want to keep? 2 3
You got--->[Dice 1]: 5 [Dice 2]: 2 [Dice 3]: 2
Your score: 9 Total score: 9

Round 1 -- My Turn:
=============================
I rolled the dice and I got:
---> [Dice 1]: 4 [Dice 2]: 5 [Dice 3]: 1
Rolled dice 3
[Dice 1]: 4 [Dice 2]: 5 [Dice 3]: 6
My score: 20 Total score: 20
```
