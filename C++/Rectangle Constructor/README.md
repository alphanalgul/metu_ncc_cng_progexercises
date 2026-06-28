# Rectangle Constructor

## Description

This project is a simple **Rectangle class example** written in **C++**.

The program demonstrates how to create a class, use a constructor, set private data members, and calculate basic rectangle information.

---

## Program Behavior

The program creates one `Rectangle` object.

The rectangle starts with default values from the constructor.

Then, the program:

1. Sets the rectangle length
2. Sets the rectangle width
3. Prints the rectangle information
4. Calculates and displays the area
5. Calculates and displays the parameter/perimeter value

---

## Features

* Defines a `Rectangle` class
* Stores rectangle length
* Stores rectangle width
* Uses a default constructor
* Allows length and width to be updated
* Validates length and width values
* Calculates rectangle area
* Prints rectangle information
* Separates class declaration and implementation into different files

---

## Project Structure

```text
Rectangle Constructor/
├── rectangle.h
├── rectangle.cpp
└── rectanglemain.cpp
```

---

## Rectangle Class

Each rectangle stores:

* Length
* Width

The class contains these main functions:

```cpp
Rectangle();
void setlength(float length);
void setwidth(float width);
float getlength();
float getwidth();
float area();
float parameter();
void printRectangle();
```

---

## Constructor

The default constructor initializes the rectangle with these values:

```text
length = 1.0
width = 1.0
```

---

## Input Validation

The program only accepts length and width values between `0` and `20`.

If the value is outside this range, the program displays an error message.

```text
Error! Enter values within the parameters
```

---

## Area Calculation

The area is calculated using:

```text
area = length * width
```

Example:

```text
length = 5
width = 10

area = 50
```

---

## How to Run

### Compile

```bash
g++ rectanglemain.cpp rectangle.cpp -o rectangle
```

### Run

On Linux/macOS:

```bash
./rectangle
```

On Windows PowerShell:

```bash
.\rectangle.exe
```

---

## Example Usage

The program sets the rectangle values inside `main()`:

```cpp
Rectangle r;

r.setlength(5.0);
r.setwidth(10.0);

r.printRectangle();

std::cout << "Area: " << r.area() << std::endl;
std::cout << "Parameter: " << r.parameter() << std::endl;
```

---

## Example Output

```text
Length: 5
Width: 10
Area: 50
Parameter: 7.5
```

The exact output may change if the length and width values are changed in `main()`.

---

