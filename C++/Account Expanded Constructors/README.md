# Account Expanded Constructors

## Description

This project is a simple **bank account management program** written in **C++**.

The program uses an `Account` class to store account information and perform basic banking operations.

---

## Program Behavior

The program creates an account object and displays an interactive menu.

The user can:

1. Change the account number and account balance
2. Display the current account information
3. Deposit money
4. Withdraw money
5. Calculate future balance using interest
6. Exit the program

---

## Features

* Stores account number
* Stores account balance
* Allows balance updates
* Allows deposit operations
* Allows withdrawal operations
* Prevents invalid deposit and withdrawal amounts
* Calculates future balance with compound interest
* Uses an interactive console menu

---

## Class Structure

The main class used in this project is `Account`.

The `Account` class stores:

* Account number
* Account balance

The class includes functions for:

* Setting account information
* Getting account information
* Printing account details
* Depositing money
* Withdrawing money
* Processing transactions
* Calculating future balance

---

## Project Structure

```text
Account Expanded Constructors/
├── account.h
├── account.cpp
└── accountmain.cpp
```

---

## Account Class

The account information is stored using private data members:

```cpp
int accountNumber;
float accountBalance;
```

The program uses getter and setter functions to access and update these values.

Example:

```cpp
void setaccountNumber(int accountNumber);
void setaccountBalance(float accountBalance);

int getaccountNumber(void);
float getaccountBalance(void);
```

---

## Menu Options

The program displays a menu similar to this:

```text
1. Change the account balance
2. Get the current balance
3. Deposit
4. Withdrawal
5. Plan your future balance
6. Mortgage Plan
7. Exit
```

---

## Future Balance Calculation

The program calculates the future balance using compound interest.

Formula:

```text
future balance = current balance * (1 + interest) ^ years
```

Example:

```text
Current balance = 1000
Interest rate = 0.10
Years = 2

Future balance = 1210
```

---

## How to Run

### Compile

Since the project has multiple `.cpp` files, compile both source files together:

```bash
g++ accountmain.cpp account.cpp -o account
```

### Run

On Linux/macOS:

```bash
./account
```

On Windows PowerShell:

```bash
.\account.exe
```

---

## Example Usage

```text
1. Change the account balance
2. Get the current balance
3. Deposit
4. Withdrawal
5. Plan your future balance
6. Mortgage Plan
7. Exit

Enter your selection:
```

Example deposit:

```text
Enter an amount to deposit:
500
```

Example withdrawal:

```text
Enter an amount to withdraw:
200
```

---

