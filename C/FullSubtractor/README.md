# Full Subtractor

## Description

This project is a **Full Subtractor simulator** written in **C**.

A full subtractor is a combinational logic circuit that performs subtraction using three binary inputs:

* `A` → minuend
* `B` → subtrahend
* `Bin` → borrow-in

The program calculates two outputs:

* `D` → difference
* `Bout` → borrow-out

The user can enter the input either as:

* a 3-bit binary number
* a 1-digit hexadecimal number that can be represented with 3 bits


---

## What is a Full Subtractor?

A full subtractor subtracts two binary bits and a borrow-in value.

The operation is:

```text
A - B - Bin
```

The outputs are:

| Output | Meaning        |
| ------ | -------------- |
| `D`    | Difference bit |
| `Bout` | Borrow-out bit |

---

## Logic Formulas

The program uses the following full subtractor formulas:

```text
D = (A XOR B) XOR Bin
```

```text
Bout = (NOT A AND Bin) OR (NOT A AND B) OR (B AND Bin)
```

The program calculates these expressions manually using logical operators instead of C bitwise operators.

---

## Program Behavior

1. The program displays a menu.
2. The user chooses whether to compute outputs or quit.
3. If the user chooses to compute:

   * The program asks for the input base.
   * The user enters either base 2 or base 16.
4. For base 2:

   * The user enters a 3-bit binary input.
   * Example: `101`
5. For base 16:

   * The user enters one hexadecimal digit.
   * Only values from `0` to `7` are accepted because they can be represented using 3 bits.
6. The program calculates and displays:

   * `D`
   * `Bout`

---

## Input Format

### Base 2 Input

For base 2, the input must contain exactly 3 bits.

Format:

```text
ABC
```

Where:

* First bit → `A`
* Second bit → `B`
* Third bit → `Bin`

Example:

```text
101
```

This means:

```text
A = 1
B = 0
Bin = 1
```

---

### Base 16 Input

For base 16, the input must be a single hexadecimal digit between `0` and `7`.

Accepted values:

```text
0 1 2 3 4 5 6 7
```

These values are accepted because they can be converted into 3-bit binary values.

Examples:

| Hex Input | Binary Equivalent |
| --------- | ----------------- |
| `0`       | `000`             |
| `1`       | `001`             |
| `2`       | `010`             |
| `3`       | `011`             |
| `4`       | `100`             |
| `5`       | `101`             |
| `6`       | `110`             |
| `7`       | `111`             |

Values such as `8`, `9`, `A`, `B`, `C`, `D`, `E`, and `F` are valid hexadecimal digits, but they cannot be represented using only 3 bits, so the program rejects them.

---

## Features

* Menu-driven interface
* Supports base 2 input
* Supports base 16 input
* Validates binary input length
* Validates invalid binary digits
* Converts hexadecimal input to 3-bit binary representation
* Calculates full subtractor outputs
* Does not use C bitwise operators
* Handles invalid input cases

---

## How to Run

### Compile

```bash
gcc FullSubtractor.c -o full_subtractor
```

### Run

On Linux/macOS:

```bash
./full_subtractor
```

On Windows PowerShell:

```bash
.\full_subtractor.exe
```

---

## Input Requirements

No external input file is required.

The program takes input from the console.

The user should enter:

1. Menu option
2. Input base
3. Binary or hexadecimal input

---

## Example Usage

```text
Welcome to Full Subtractor
(1)Compute and Display the outputs
(2)Quit
You choose: 1

You have chosen option 1
Which base will you use to enter input(base 2 or base 16)? 2
Please enter your input: 101

D is 0 Bout is 0
```

---

## Example with Hexadecimal Input

```text
Welcome to Full Subtractor
(1)Compute and Display the outputs
(2)Quit
You choose: 1

You have chosen option 1
Which base will you use to enter input(base 2 or base 16)? 16
Please enter your input: 5

D is 0 Bout is 0
```

Explanation:

```text
Hex 5 = Binary 101
A = 1
B = 0
Bin = 1
```

---
