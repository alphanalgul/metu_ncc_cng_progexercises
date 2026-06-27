# Fishdom AVL Tree Analysis

## Description

This project is a **Fishdom data analysis program** written in **C**.

The program reads fish records from a CSV file and stores them in an **AVL tree**. The tree is ordered by fish weight, so the records can be displayed in sorted order efficiently.

---

## Program Behavior

The program reads fish data from an input file and builds an AVL tree.

Each fish record contains:

- Fish name
- Weight
- Length
- Date
- City

After loading the file, the program displays an interactive menu.

The user can:

1. Display the full fish index in ascending order of weight
2. Display the heaviest fish/fishes
3. Display the longest fish/fishes
4. Exit the program

---

## Features

- Reads fish records from a CSV file
- Stores fish data inside an AVL tree
- Orders fish records by weight
- Handles multiple fish with the same weight in the same AVL node
- Displays all fish records in sorted order
- Finds the heaviest fish
- Finds the longest fish
- Uses an interactive console menu

---

## Data Structure Used

The main data structure used in this project is an **AVL tree**.

An AVL tree is a self-balancing binary search tree. In this program, fish records are inserted based on their weight.

If a fish has:

- Smaller weight → inserted into the left subtree
- Greater weight → inserted into the right subtree
- Same weight → stored in the same node with the existing fish records

The AVL tree keeps itself balanced using rotations.

The project uses these AVL operations:

- Left rotation
- Right rotation
- Balance factor calculation
- Height update after insertion

---

## Fish Record Structure

Each fish is represented using a struct similar to this:

```c
typedef struct Fishdom {
    char name[50];
    int weight;
    float length;
    char date[20];
    char city[50];
} Fishdom;
```

Each AVL tree node stores fish data and links to left and right child nodes.

---

## Input File Format

The program expects a CSV-style input file.

Each line should follow this format:

```text
name,weight,length,date,city
```

Example:

```text
Salmon,12,45.5,2024-01-15,Trabzon
Tuna,20,60.2,2024-02-10,Izmir
Carp,12,40.0,2024-03-05,Ankara
```

The weight value is used for ordering records inside the AVL tree.

---

## How to Run

### Compile

Make sure `AVLFishdomAnalysis.c` and `avltree.h` are in the same folder.

```bash
gcc AVLFishdomAnalysis.c -o fishdom
```

### Run

The program expects the input filename as a command-line argument.

On Linux/macOS:

```bash
./fishdom fishdata.csv
```

On Windows PowerShell:

```bash
.\fishdom.exe fishdata.csv
```

---

## Example Usage

```text
********Welcome to Fishdom Analysis********
*******************************************
Menu
1. Display the full index of Fishdom
2. Display the heaviest fishes
3. Display the longest fishes
4. Exit
*******************************************
Enter your option:
```

Example option:

```text
Enter your option: 1
```

This displays all fish records in ascending order of weight.

---

## Input Requirements

This project requires an external input file.

The input file should:

- Be passed as a command-line argument
- Contain one fish record per line
- Use commas between fields
- Follow the format:

```text
name,weight,length,date,city
```

Example run:

```bash
./fishdom fishdata.csv
```

---

