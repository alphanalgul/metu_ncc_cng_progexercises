# Flight Booking & Investment Simulator

## Description

This project is a simple **Flight Booking Simulation System** written in **C**.

The program simulates an airline booking process with two seat classes:

- Economy Class
- Business Class

The user enters the total number of seats, and the program divides them equally between economy and business class. Users can continue booking seats until all seats are filled or until they choose to stop.

After the booking process is completed, the program calculates the total revenue from ticket sales. Then, it asks the user for the number of years to invest the revenue and calculates the future investment value using a fixed **25% annual return**.

Based on the final investment value, the program also gives a simple recommendation about future flight planning.

---

## Program Behavior

1. The user enters an even number of seats.
2. The seats are divided equally:
   - First half → Economy Class
   - Second half → Business Class
3. The user is repeatedly asked whether they want to make a booking.
4. If the user chooses to book a seat:
   - `1` is used for Economy Class
   - `2` is used for Business Class
5. If the selected class is full, the program asks the user to try the other class.
6. When the booking process ends, the program calculates the total revenue.
7. The user enters the number of years for investment.
8. The program calculates the future value of the revenue using recursion.
9. A recommendation is displayed based on the investment result.

---

## Seat Pricing

| Class | Price |
|---|---:|
| Economy Class | $100 |
| Business Class | $200 |

---

## Data Representation

The program uses an integer array to represent the seats:

```c
int array[n];
```

Each index of the array represents one seat.

The array is divided into two parts:

- First half: Economy Class seats
- Second half: Business Class seats

The values inside the array are used to represent whether a seat is empty or booked.

---

## Features

- Console-based flight booking simulation
- Economy and business class seat allocation
- Automatic class capacity checking
- Revenue calculation from ticket sales
- Recursive investment value calculation
- Simple recommendation system based on financial performance
- Interactive user input through the terminal

---

## How to Run

### Compile

```bash
gcc PlaneTicketProgram.c -o plane_ticket_program
```

### Run

On Linux/macOS:

```bash
./plane_ticket_program
```

On Windows PowerShell:

```bash
.\plane_ticket_program.exe
```

---

## Input Requirements

No external input file is required.

The program takes all input from the console.

The user should enter:

1. Total number of seats  
2. Booking choices  
3. Seat class choices  
4. Number of years for investment  

---

## Example Usage

```text
Enter the number of seats: 10

Do you want to book a seat? 1 for yes, 0 for no: 1
Enter 1 for Economy Class or 2 for Business Class: 1

Do you want to book a seat? 1 for yes, 0 for no: 1
Enter 1 for Economy Class or 2 for Business Class: 2

Do you want to book a seat? 1 for yes, 0 for no: 0

Total revenue: 300
Enter the number of years to invest: 2
Future investment value: 468.75
```

---

## Notes

- The total number of seats should be an even number.
- The program assumes that economy and business class have equal seat capacity.
- The investment calculation uses a fixed annual return rate of 25%.

---

