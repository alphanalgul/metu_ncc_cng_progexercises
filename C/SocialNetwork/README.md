# Social Network Graph Analysis

## Description

This project is a **Social Network Graph Analysis** program written in **C**.

The program models a small social network using a **directed graph**. Each user is represented as a vertex, and each friendship/follow relationship is represented as a directed edge.

The program allows the user to analyze the network using graph-based operations such as:

* searching for a friendship path between two users
* finding the user with the most followers
* finding the user who follows the most users

---

## Program Behavior

The program creates a predefined social network in the source code.

The network includes these users:

* John
* Alice
* Bob
* David
* Eve
* Frank

After creating the users and friendship relationships, the program:

1. Displays all users in the network.
2. Displays all friendship/follow relationships.
3. Shows an interactive menu.
4. Allows the user to:

   * search for a path between two users using DFS
   * find the most followed user
   * find the user who follows the most users
   * exit the program

---

## Graph Model

The program uses a **directed graph**.

Each user is a node/vertex.

Each friendship or follow relationship is a directed edge.

Example:

```text
John -> Alice
```

This means:

```text
John follows Alice
```

The relationship is directed, so `John -> Alice` does not automatically mean `Alice -> John`.

---

## Data Structures Used

The graph is implemented using an **adjacency list**.

Each user stores a linked list of outgoing friendships.

### Graph Arc

```c
struct graphArc {
    struct graphVertex *destination;
    struct graphArc *next;
};
```

Each arc represents a directed connection from one user to another.

### Graph Vertex

```c
struct graphVertex {
    struct graphVertex *next;
    char userName[50];
    int inDegree;
    int outDegree;
    int processed;
    struct graphArc *firstArc;
};
```

Each vertex stores:

| Field       | Description                       |
| ----------- | --------------------------------- |
| `userName`  | Name of the user                  |
| `inDegree`  | Number of followers               |
| `outDegree` | Number of users this user follows |
| `processed` | DFS visited flag                  |
| `firstArc`  | First outgoing friendship edge    |
| `next`      | Next user in the graph            |

### Graph Head

```c
struct graphHead {
    int count;
    struct graphVertex *first;
};
```

The graph head stores the number of users and a pointer to the first user.

---

## Predefined Users

The program creates the following users:

```text
John
Alice
Bob
David
Eve
Frank
```

---

## Predefined Friendships

The social network relationships are created inside the code.

```text
John -> Alice
John -> Bob
John -> Eve
Alice -> John
Alice -> David
Bob -> John
Bob -> Eve
David -> Alice
Eve -> Bob
Eve -> Frank
Frank -> Eve
Frank -> Bob
```

---

## Menu Options

The program displays this menu:

| Option | Description                              |
| ------ | ---------------------------------------- |
| `1`    | Depth-First Search for friendship path   |
| `2`    | Find the user who has the most followers |
| `3`    | Find the user who follows the most users |
| `4`    | Exit                                     |

---

## Depth-First Search

The program uses **Depth-First Search (DFS)** to check whether a path exists between two users.

Example:

```text
John -> Alice -> David
```

If a path is found, the program prints the path in reverse order because of the recursive DFS return process.

Example output:

```text
Path Found! David <- Alice <- John
```

This means a path exists from `John` to `David`.

---

## Most Followed User

The program uses the `inDegree` value to find the user or users with the most followers.

A user's `inDegree` increases when another user follows them.

Example:

```text
John -> Alice
```

In this case, Alice's `inDegree` increases by 1.

---

## Most Following User

The program uses the `outDegree` value to find the user or users who follow the most users.

A user's `outDegree` increases when that user follows another user.

Example:

```text
John -> Alice
John -> Bob
John -> Eve
```

In this case, John's `outDegree` is 3.

---

## Features

* Directed graph representation
* Adjacency list implementation
* Predefined users and relationships
* Displays all users
* Displays all friendships
* DFS path search between two users
* Finds the most followed user using `inDegree`
* Finds the most following user using `outDegree`
* Interactive console menu
* Input validation for menu choices

---

## How to Run

### Compile

```bash
gcc SocialNetwork.c -o social_network
```

### Run

On Linux/macOS:

```bash
./social_network
```

On Windows PowerShell:

```bash
.\social_network.exe
```

---

## Input Requirements

No external input file is required.

The users and friendships are defined directly inside the source code.

The user only enters:

* menu choice
* start username for DFS path search
* target username for DFS path search

Example DFS input:

```text
Enter User 1: John
Enter User 2: David
```

Usernames must match the predefined names exactly.

---

## Example Usage

```text
Welcome to METU NCC Social Network!

Users in the network:
John
Alice
Bob
David
Eve
Frank

Friendship Bonds:
John's friends: Alice Bob Eve
Alice's friends: John David
Bob's friends: John Eve
David's friends: Alice
Eve's friends: Bob Frank
Frank's friends: Eve Bob

========== MENU ==========
1. Depth-First search for friendship
2. Find the user who has the most followers
3. Find the user who follows the most users
4. Exit
=========================
Enter your choice:
```

---

## Example DFS Search

Input:

```text
Enter your choice: 1
Enter User 1: John
Enter User 2: David
```

Possible output:

```text
Path Found! David <- Alice <- John
```

This means there is a connection path from John to David.

---

## Example Analysis Outputs

### Most Followed User

```text
Most followed User(s) (3):
- John
- Bob
```

### Most Following User

```text
Most following User(s) (3):
- John
```

---
