# Operator Overloading

## Description

This project is a simple **operator overloading example** written in **C++**.

The program demonstrates how operators can be redefined for user-defined classes.

The project uses two classes:

* `X`
* `Y`

Both classes overload several operators to show different ways operator overloading can be implemented.

---

## Program Behavior

The program creates objects from the `X` and `Y` classes.

Then, it tests overloaded operators such as:

1. Prefix increment
2. Postfix increment
3. Logical NOT operator
4. Addition operator
5. Assignment operator
6. Function call operator

The program prints object values after different operator operations.

---

## Features

* Demonstrates operator overloading
* Uses member operator functions
* Uses friend operator functions
* Tests prefix increment
* Tests postfix increment
* Tests addition of objects
* Tests assignment between objects
* Tests function call operator overloading
* Separates class declaration and implementation into different files

---

## Project Structure

```text
OperatorOverloading/
├── OperatorHeader.h
├── OperatorSource.cpp
└── Operatormain.cpp
```

---

## Classes

The project contains two classes:

```text
X
Y
```

### Class `X`

Class `X` overloads operators using member functions.

It contains an integer value named:

```cpp
int Xval;
```

The overloaded operators include:

* `!`
* `++`
* `++(int)`
* `+`
* `=`
* `()`

---

### Class `Y`

Class `Y` overloads some operators using friend functions.

It contains an integer value named:

```cpp
int Yval;
```

The overloaded operators include:

* `!`
* `++`
* `++(int)`
* `+`
* `=`

---

## Operators Used

| Operator | Purpose                                             |
| -------- | --------------------------------------------------- |
| `!`      | Prints the object value                             |
| `++obj`  | Prefix increment                                    |
| `obj++`  | Postfix increment                                   |
| `+`      | Adds two objects                                    |
| `=`      | Assigns one object value to another                 |
| `()`     | Changes the value of an object like a function call |

---

## Function Call Operator

Class `X` also overloads the function call operator.

This allows an object to be used like a function.

Example:

```cpp
X x4(0);

x4();
x4(1);
x4(1, 2);
x4(1, 2, 3);
x4(3.14);
```

These calls update the value stored inside the object.

---

## How to Run

### Compile

```bash
g++ Operatormain.cpp OperatorSource.cpp -o operator_overloading
```

### Run

On Linux/macOS:

```bash
./operator_overloading
```

On Windows PowerShell:

```bash
.\operator_overloading.exe
```

---

## Important Note

In `Operatormain.cpp`, make sure the header include matches the actual file name.

Use:

```cpp
#include "OperatorHeader.h"
```

not:

```cpp
#include "Header.h"
```

Otherwise, the program will not compile unless a file named `Header.h` also exists.

---

## Example Usage

The program performs operations such as:

```cpp
X x1(2);
Y y1(12);

++x1;
++y1;

x1++;
y1++;

!x1;
!y1;
```

It also tests object addition:

```cpp
!(x1 + x1);
!(y1 + y1);
```

And assignment:

```cpp
x3 = x1 + x2;
y3 = y1 + y2;
```

---
