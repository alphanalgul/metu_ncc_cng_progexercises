# Instructor Record Manager – Binary Search Tree

## Description

This project is a simple **Instructor Record Manager** written in **C**.

The program stores instructor names and academic titles using a **Binary Search Tree (BST)**. Instructor names are used as the search key, so the tree keeps records in lexicographical order.

---

## Program Behavior

The user interacts with the program through a console menu.

Each instructor record contains:

* Instructor name
* Instructor title

When a new instructor is inserted:

* If the instructor name is alphabetically smaller than the current node, it is inserted into the left subtree.
* If the instructor name is alphabetically greater than the current node, it is inserted into the right subtree.

Because of this structure, an in-order traversal displays instructor records in alphabetical order.

---

## Menu Options

| Command | Description                                                    |
| ------- | -------------------------------------------------------------- |
| `i`     | Initializes the tree and makes it empty                        |
| `n`     | Inserts a new instructor record                                |
| `t`     | Searches for an instructor by full name and displays the title |
| `s`     | Lists instructors whose names start with a given character     |
| `e`     | Exits the program                                              |

---

## Features

* Insert instructor records into a Binary Search Tree
* Search for an instructor by full name
* Search instructors by first character
* Display all instructor records in sorted order
* Interactive console menu
* Dynamic memory allocation for instructor names and titles

---

## Data Structure Used

The main data structure used in this project is a **Binary Search Tree**.

Each tree node stores:

```c
struct TreeNode {
    int val;
    char *instructor;
    char *title;
    struct TreeNode* left;
    struct TreeNode* right;
};
```

The instructor name is used as the key for inserting and searching records.

---

## How to Run

### Compile

```bash
gcc TreeADT.c -o bst
```

### Run

On Linux/macOS:

```bash
./bst
```

On Windows PowerShell:

```bash
.\bst.exe
```

---

## Input Requirements

No external input file is required.

The program takes all input from the console.

Important input note:

* Do not use spaces inside instructor names.
* Do not use spaces inside titles.

For example, use:

```text
JohnSmith
AssistantProfessor
```

instead of:

```text
John Smith
Assistant Professor
```

---

## Example Usage

```text
Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command:
```

### Insert an Instructor

```text
Enter command: n
Enter instructors name: JohnSmith
Enter his/her title: Professor
```

Output:

```text
Tree now:

JohnSmith Professor
```

### Insert Another Instructor

```text
Enter command: n
Enter instructors name: AliceBrown
Enter his/her title: Lecturer
```

Output:

```text
Tree now:

AliceBrown Lecturer
JohnSmith Professor
```

### Search for an Instructor

```text
Enter command: t
Enter instructors name: JohnSmith
```

Output:

```text
Professor
```

### Search by First Character

```text
Enter command: s
Enter a character: A
```

Output:

```text
AliceBrown Lecturer
```


