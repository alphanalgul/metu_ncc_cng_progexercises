# Abstract Class Polygon Example

## Description

This project is an **abstract class example** written in **C++**.

The program demonstrates how a base class can be used with derived classes through **inheritance** and **polymorphism**.

The project uses a polygon base class and two derived shape classes:

* Rectangle
* Triangle

Each shape calculates its area differently.

---

## Program Behavior

The program creates one rectangle object and one triangle object.

After creating the objects, the program:

1. Displays a message for the triangle
2. Stores the rectangle and triangle using `CPolygon` pointers
3. Sets width and height values for both shapes
4. Displays the area of each shape
5. Prints the number of polygon objects created

---

## Features

* Uses an abstract base class
* Uses inheritance
* Uses virtual functions
* Uses function overriding
* Demonstrates polymorphism with base class pointers
* Calculates rectangle area
* Calculates triangle area
* Uses a static counter to count polygon objects

---

## Class Structure

The project uses a base class named `CPolygon`.

Two classes inherit from it:

```text
CPolygon
├── CRectangle
└── CTriangle
```

`CPolygon` stores the common properties of a polygon, such as width and height.

`CRectangle` and `CTriangle` define their own area calculations.

---

## Area Calculation

### Rectangle

```text
area = width * height
```

### Triangle

```text
area = (width * height) / 2
```

For example, if width and height are both `2`:

* Rectangle area = `4`
* Triangle area = `2`

---

## Project Structure

```text
AbstractClass/
├── CPolygon.h
├── CRectangle.h
├── CTriangle.h
└── main.cpp
```

---

## How to Run

### Compile

```bash
g++ main.cpp -o abstract_class
```

### Run

On Linux/macOS:

```bash
./abstract_class
```

On Windows PowerShell:

```bash
.\abstract_class.exe
```

---

## Example Usage

```text
This is a triangle
CRectangle area: 4
CTriangle area: 2
Number of CPolygon created: 2
```

---


