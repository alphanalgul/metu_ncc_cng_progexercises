# Address Copy Destructor Assignment Constructors

## Description

This project is a simple **Address class example** written in **C++**.

The program demonstrates how dynamic memory can be used inside a class with constructors, a copy constructor, a destructor, and an assignment operator.
---

## Program Behavior

The program creates an address object with default values.

Then, it asks the user to enter address information.

Each address contains:

* Country
* City
* Street
* House number

After receiving the input, the program updates the address object and prints the address information.

---

## Features

* Creates an address with default values
* Stores country, city, and street using dynamic character arrays
* Stores house number
* Allows address information to be updated
* Prints address information
* Uses a copy constructor
* Uses a destructor to free memory
* Uses an overloaded assignment operator
* Separates class declaration and implementation into different files

---

## Project Structure

```text
Adress Copy Destructor Assignment Constructors/
├── address.h
├── address.cpp
└── addressmain.cpp
```

---

## Address Class

The main class used in this project is `Address`.

Each `Address` object stores:

```cpp
char *country;
char *city;
char *street;
int house_number;
```

Since `country`, `city`, and `street` are dynamically allocated, the class also includes:

* Constructor
* Copy constructor
* Destructor
* Assignment operator

---

## Constructors and Destructor

The default constructor initializes the address with default values:

```text
Not Provided
```

The parameterized constructor allows an address to be created with custom values.

The copy constructor creates a new address object by copying another address object.

The destructor releases the dynamically allocated memory when the object is destroyed.

---

## Assignment Operator

The assignment operator allows one `Address` object to be assigned to another.

Example:

```cpp
Address a1;
Address a2;

a2 = a1;
```

This is important because the class uses dynamic memory.

Without a custom assignment operator, two objects could accidentally share the same memory.

---

## How to Run

### Compile

```bash
g++ addressmain.cpp address.cpp -o address
```

### Run

On Linux/macOS:

```bash
./address
```

On Windows PowerShell:

```bash
.\address.exe
```

---

## Example Usage

```text
Country: Not Provided
City: Not Provided
Street: Not Provided
House Number: 0

Enter Country:
Turkey
Enter City:
Ankara
Enter Street:
Ataturk Street
Enter House Number:
15
```

Example output:

```text
Country: Turkey
City: Ankara
Street: Ataturk Street
House Number: 15
```

---
