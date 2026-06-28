# Address Constructors

## Description

This project is a simple **Address class example** written in **C++**.

The program demonstrates how to create a class, use a constructor, store address information, and print object data.

---

## Program Behavior

The program creates two `Address` objects.

The first address uses the default constructor, so its values are initialized automatically.

The second address is created and then updated using the `createAddress()` function.

After creating the addresses, the program prints their information to the screen.

---

## Features

* Defines an `Address` class
* Stores house number
* Stores street name
* Stores city name
* Uses a default constructor
* Uses a function to create/update address information
* Prints address information
* Separates class declaration and implementation into different files

---

## Project Structure

```text
Address Constructors/
├── Address.h
├── address.cpp
└── addressmain.cpp
```

---

## Address Class

Each address stores:

* House number
* Street name
* City name

The class contains these main functions:

```cpp
Address();
void createAddress(int house_number, const char *street_name, const char *city);
void printAddress();
```

---

## How the Program Works

The program first creates a default address:

```cpp
Address a1;
a1.printAddress();
```

Then it creates another address and assigns custom values:

```cpp
Address a2;
a2.createAddress(158, "Gazi Caddesi", "Samsun");
a2.printAddress();
```

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

## Example Output

```text
House Number: 0
Street Name: Not provided
City: Not provided

House Number: 158
Street Name: Gazi Caddesi
City: Samsun
```

---

