# Football Team Data Analyzer

## Description

This project is a **Football Team Data Analyzer** written in **C**.

The program reads football team data from a text file, stores the records in a dynamically allocated array of structures, displays the loaded data, and calculates basic statistics about the teams.

---

## Program Behavior

The program takes one command-line argument:

1. Input filename

After running, the program:

1. Opens the input file.
2. Reads football team records from the file.
3. Counts how many valid team records exist.
4. Dynamically allocates memory for the team records.
5. Loads the data into an array of structures.
6. Displays all team records in table format.
7. Calculates the average points of all teams.
8. Counts how many teams played 33 matches.
9. Counts how many teams played 34 matches.
10. Displays teams that have three consecutive wins in their recent form.

---

## Data Structure Used

Each team is represented using a structure:

```c
struct teams {
    int played;
    int points;
    char name[20];
    char form[6];
};
```

Each record stores:

| Field    | Description                          |
| -------- | ------------------------------------ |
| `played` | Number of matches played by the team |
| `points` | Current points of the team           |
| `name`   | Team name                            |
| `form`   | Recent match form, such as `WWLDW`   |

---

## Input File Format

The input file should contain one team record per line.

Each line should follow this format:

```text
Played Points Team_Name Form
```

Example:

```text
34 75 Arsenal WWWDW
33 70 Liverpool WLWWW
34 65 Chelsea LWWDW
33 60 Tottenham WWWLL
```

The values should be separated by spaces.

---

## Fields

| Field       | Example   | Meaning                  |
| ----------- | --------- | ------------------------ |
| `Played`    | `34`      | Number of matches played |
| `Points`    | `75`      | Team points              |
| `Team_Name` | `Arsenal` | Team name                |
| `Form`      | `WWWDW`   | Recent match results     |


| Character | Meaning |
| --------- | ------- |
| `W`       | Win     |
| `D`       | Draw    |
| `L`       | Loss    |

---

## Features

* Reads team data from a text file
* Stores team records using a structure array
* Dynamically allocates memory based on the number of records
* Displays the loaded team data
* Calculates average points
* Counts teams that played 33 matches
* Counts teams that played 34 matches
* Finds teams with three consecutive wins
* Uses command-line arguments
* Handles file opening errors
* Handles empty or invalid files

---

## How to Run

### Compile

```bash
gcc footballteam.c -o football_team
```

### Run

The program requires one command-line argument: the input filename.

On Linux/macOS:

```bash
./football_team teams.txt
```

On Windows PowerShell:

```bash
.\football_team.exe teams.txt
```

---

## Input Requirements

This project requires an external input file.

The input file should:

* be in the same folder as the executable, or be given with its full path
* contain one team record per line
* use spaces between values
* follow this format:

```text
Played Points Team_Name Form
```

Example project folder:

```text
TeamForm/
├── footballteam.c
├── README.md
└── teams.txt
```

Example `teams.txt`:

```text
34 75 Arsenal WWWDW
33 70 Liverpool WLWWW
34 65 Chelsea LWWDW
33 60 Tottenham WWWLL
```

---

## Example Console Output

```text
Your data is successfully processed and looks as follows:
Team    Played  Points  Form
Arsenal 34      75      WWWDW
Liverpool       33      70      WLWWW
Chelsea 34      65      LWWDW
Tottenham       33      60      WWWLL

Average points: 67.50
2 teams played 33 games and 2 teams played 34 games
These teams have three consecutive wins:
Arsenal
Liverpool
Tottenham
```

---
