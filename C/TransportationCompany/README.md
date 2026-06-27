# Warehouse Transportation Network

## Description

This project is a **Warehouse Transportation Network** program written in **C**.

The program models transportation routes between warehouses using a **directed weighted graph**. Each warehouse is represented as a vertex, and each delivery route is represented as a directed edge with a distance value.

The program reads warehouse and route information from input files, builds the graph, and performs several analyses on the transportation network.

---

## Program Behavior

The program performs the following steps:

1. Reads warehouse names from `WarehouseLocations.txt`.
2. Adds each warehouse as a vertex in the graph.
3. Reads delivery routes from `WarehouseRoutes.txt`.
4. Adds each route as a directed weighted edge.
5. Prints all warehouse locations.
6. Prints all transportation routes.
7. Finds the warehouse or warehouses receiving deliveries from the most locations.
8. Finds the warehouse or warehouses sending deliveries to the most locations.
9. Finds the route or routes with the highest distance.
10. Finds the route or routes with the lowest distance.
11. Optionally searches for a path between two warehouses using Depth-First Search.

---

## Data Structure Used

The main data structure used in this project is a **directed weighted graph**.

The graph is implemented using an **adjacency list**.

Each warehouse is a vertex.

Each route is an edge.

Example:

```text
Ankara -200-> Istanbul
```

This means there is a directed delivery route from `Ankara` to `Istanbul` with distance `200`.

---

## Graph Structures

The program uses three main structures:

```c
struct graphArc {
    int weight;
    struct graphVertex *destination;
    struct graphArc *next;
};
```

```c
struct graphVertex {
    struct graphVertex *next;
    char warehouseName[50];
    int inDegree;
    int outDegree;
    int processed;
    struct graphArc *firstArc;
};
```

```c
struct graphHead {
    int count;
    struct graphVertex *first;
};
```

---

## Input Files

This project requires two input files:

```text
WarehouseLocations.txt
WarehouseRoutes.txt
```

Both files should be in the same folder where the program is executed.

---

## WarehouseLocations.txt Format

`WarehouseLocations.txt` contains the warehouse names.

Each line should contain one warehouse name.

Example:

```text
Ankara
Istanbul
Izmir
Adana
Bursa
```

---

## WarehouseRoutes.txt Format

`WarehouseRoutes.txt` contains the delivery routes and distances.

Each line starts with a source warehouse. After that, destination warehouses and distances are written using semicolons.

Format:

```text
SourceWarehouse;Distance;DestinationWarehouse;Distance;DestinationWarehouse
```

Example:

```text
Ankara;200;Istanbul;300;Izmir
Istanbul;150;Bursa;450;Adana
Izmir;250;Adana
```

Meaning:

```text
Ankara -> Istanbul with distance 200
Ankara -> Izmir with distance 300
Istanbul -> Bursa with distance 150
Istanbul -> Adana with distance 450
Izmir -> Adana with distance 250
```

---

## Features

* Reads warehouse names from a file
* Reads transportation routes from a file
* Builds a directed weighted graph
* Stores routes using adjacency lists
* Prints all warehouse locations
* Prints all warehouse routes
* Calculates incoming delivery counts
* Calculates outgoing delivery counts
* Finds warehouses with the most incoming routes
* Finds warehouses with the most outgoing routes
* Finds the route with the highest distance
* Finds the route with the lowest distance
* Searches for a path between two warehouses using DFS
* Calculates total distance of the found path

---

## How to Run

### Compile

```bash
gcc TransportationCompany.c -o transportation_company
```

### Run Basic Analysis

On Linux/macOS:

```bash
./transportation_company
```

On Windows PowerShell:

```bash
.\transportation_company.exe
```

This runs the main graph analysis using:

```text
WarehouseLocations.txt
WarehouseRoutes.txt
```

---

## Optional Route Search

The program can also search for a path between two warehouses.

### Linux/macOS

```bash
./transportation_company Ankara Izmir
```

### Windows PowerShell

```bash
.\transportation_company.exe Ankara Izmir
```

This searches for a route from `Ankara` to `Izmir` using Depth-First Search.

If a path is found, the program displays the route and total distance.

---

## Example Output

```text
Warehouse and route data read successfully.

Read warehouse locations:

Ankara
Istanbul
Izmir
Adana
Bursa

Read routes:

Ankara | -200-> Istanbul | -300-> Izmir |
Istanbul | -150-> Bursa | -450-> Adana |
Izmir | -250-> Adana |

Warehouses that receives deliveries from the most different locations (2):
- Adana

Warehouses that sends deliveries to most different locations (2):
- Ankara
- Istanbul

Routes with the highest distance (450):
Istanbul -450-> Adana

Routes with the lowest distance (150):
Istanbul -150-> Bursa
```

---

## Example Route Search Output

Command:

```bash
./transportation_company Ankara Adana
```

Example output:

```text
Searching for a route from Ankara to Adana...
Adana <-250- Izmir <-300- Ankara
Total Distance: 550
```

---

## Input Requirements

The program requires these two files:

```text
WarehouseLocations.txt
WarehouseRoutes.txt
```

Example project folder:

```text
TransportationCompany/
├── TransportationCompany.c
├── README.md
├── WarehouseLocations.txt
└── WarehouseRoutes.txt
```

Important notes:

* Warehouse names in `WarehouseRoutes.txt` must also exist in `WarehouseLocations.txt`.
* Route distances should be integer values.
* The route file should use semicolons.
* Warehouse names should not contain spaces.
* The graph is directed, so `Ankara -> Istanbul` does not automatically mean `Istanbul -> Ankara`.

---
