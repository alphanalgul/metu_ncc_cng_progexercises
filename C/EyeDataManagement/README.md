# Eye Data Management System

## Description

This project is an **Eye Data Management System** written in **C**.

The program reads eye-tracking records from a file and groups the records by username. Each user can have multiple eye measurement records. The data is stored using linked lists.

This project was written as a C data structures exercise to practice:

* Linked lists
* Structs
* Pointers
* Dynamic memory allocation
* File reading
* Data validation
* Case-insensitive search
* Menu-driven programs

---

## Program Behavior

The program first asks the user to enter an input filename.

After the file is loaded, the program checks the eye data records. If a record contains a zero value, the user can either:

* delete the invalid record
* replace it with new values

After validation, the user can display statistics for a selected user.

The statistics include:

* number of eye data records for that user
* estimated age group based on the average dilation ratio

---

## Features

* Reads eye-tracking data from a file
* Stores users in a linked list
* Stores each user's eye measurements in a separate linked list
* Groups multiple records under the same username
* Detects invalid zero values
* Allows invalid records to be deleted
* Allows invalid records to be replaced with new values
* Performs case-insensitive username search
* Displays user statistics
* Estimates age group based on eye data
* Frees dynamically allocated memory before program exit

---

## Data Structures Used

### User Linked List

Each user is represented as a node in a linked list.

Each user node stores:

* username
* pointer to that user's eye data list
* pointer to the next user

Example structure:

```c
struct User {
    char UserName[50];
    struct EyeData *eyeList;
    struct User *next;
};
```

---

### Eye Data Linked List

Each eye data node stores one measurement record.

Each eye data node contains:

| Field    | Description                         |
| -------- | ----------------------------------- |
| `PupilX` | X coordinate of the pupil center    |
| `PupilY` | Y coordinate of the pupil center    |
| `IrisX`  | X coordinate of the iris center     |
| `IrisY`  | Y coordinate of the iris center     |
| `IrisR`  | Iris radius                         |
| `PupilR` | Pupil radius                        |
| `next`   | Pointer to the next eye data record |

---

## Input File Format

The program expects a comma-separated input file.

Each line should follow this format:

```text
UserName,PupilX,PupilY,IrisX,IrisY,IrisR,PupilR
```

Example input file:

```text
Alice,12,25,12,25,10,4
Alice,14,26,14,26,9,3
Bob,20,18,20,18,11,4
Charlie,30,22,30,22,13,5
```

Each row represents one eye measurement record.

If the same username appears multiple times, the program stores all of that user's measurements under the same user node.

---

## Invalid Data Handling

If a record contains a zero value, the program asks the user what to do.

Example:

```text
Alice has eye data with zero value(s). Would you like to delete (d) or add new value (a)?
```

Options:

| Input | Action                                      |
| ----- | ------------------------------------------- |
| `d`   | Deletes the invalid eye data record         |
| `a`   | Replaces the invalid values with new values |

When choosing `a`, the user enters the new values in this format:

```text
PupilX PupilY IrisX IrisY IrisR PupilR
```

Example:

```text
12 25 12 25 10 4
```

---

## Age Group Estimation

The program estimates age group using the average dilation ratio:

```text
IrisR / PupilR
```

The average ratio is calculated across all eye data records of the selected user.

| Average Ratio | Age Group |
| ------------: | --------- |
|       `< 1.6` | Young     |
|   `1.6 - 4.6` | Adult     |
|       `> 4.6` | Elderly   |

---

## Menu Options

After loading and validating the file, the program displays this menu:

| Option | Description                            |
| ------ | -------------------------------------- |
| `1`    | Display statistics for a selected user |
| `0`    | Exit the program                       |

---

## How to Run

### Compile

```bash
gcc EyeLinkedList.c -o eye_data
```

### Run

On Linux/macOS:

```bash
./eye_data
```

On Windows PowerShell:

```bash
.\eye_data.exe
```

The program will ask for the input filename after it starts.

Example:

```text
Enter file name: eyeData.txt
```

---

## Example Usage

```text
Enter file name: eyeData.txt
The eye data is successfully loaded.

----------------------------------------------
(1) Display the statistics
(0) Exit
Enter your choice: 1

Enter a user name: Alice
Alice has 2 eye data and The age group for the eye data is: Adult
```

---

## Input Requirements

This project requires an external input file.

The input file should:

* be in the same folder as the executable, or be given with its full path
* contain one eye data record per line
* use commas between fields
* follow this format:

```text
UserName,PupilX,PupilY,IrisX,IrisY,IrisR,PupilR
```

---

