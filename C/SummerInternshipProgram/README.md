# Internship Data Processor

## Description

This project is an **Internship Data Processing System** written in **C**.

The program reads student internship records from a text file, stores them in memory, automatically assigns letter grades based on internship scores, and allows the user to interact with the records using a console menu.

---

## Program Behavior

The program takes one command-line argument:

1. Input filename

After running, the program:

1. Opens the input file.
2. Skips the first line as a header line.
3. Reads internship records from the file.
4. Stores the records in a dynamically allocated array.
5. Automatically calculates each student's letter grade:

   * `S` for successful
   * `U` for unsuccessful
6. Displays all internship records.
7. Shows a menu where the user can:

   * search for a student
   * sort records
   * display statistics
   * exit the program

---

## Data Structure Used

Each internship record is represented using a structure:

```c
typedef struct {
    char name[NAME_LEN];
    char surname[SURNAME_LEN];
    int departmentCode;
    int semester;
    float score;
    char letterGrade;
} InternshipRecord;
```

Each record stores:

| Field            | Description                  |
| ---------------- | ---------------------------- |
| `name`           | Student first name           |
| `surname`        | Student surname              |
| `departmentCode` | Department code              |
| `semester`       | Student semester             |
| `score`          | Internship score             |
| `letterGrade`    | Automatically assigned grade |

---

## Letter Grade Rules

The program assigns letter grades using the internship score.

|   Score | Letter Grade | Meaning               |
| ------: | ------------ | --------------------- |
| `>= 70` | `S`          | Successful / Passed   |
|  `< 70` | `U`          | Unsuccessful / Failed |

---

## Department Codes

The statistics section uses the following department codes:

| Department Code | Department                             |
| --------------: | -------------------------------------- |
|           `355` | Computer Engineering                   |
|           `356` | Electrical and Electronics Engineering |
|           `365` | Mechanical Engineering                 |
|           `384` | Aerospace Engineering                  |

---

## Menu Options

After the records are loaded, the program displays this menu:

| Option | Description                  |
| ------ | ---------------------------- |
| `1`    | Search for a student         |
| `2`    | Sort records                 |
| `3`    | Display pass/fail statistics |
| `4`    | Exit the program             |

---

## Search Feature

The program supports searching by:

* first name
* full name

Example first-name search:

```text
John
```

Example full-name search:

```text
John Smith
```

If a matching student is found, the program displays:

* name
* surname
* department code
* semester
* score
* letter grade

---

## Sort Feature

The program can sort records by:

| Option | Sort By      |
| ------ | ------------ |
| `1`    | Score        |
| `2`    | Letter grade |

After sorting, the updated table is displayed.

---

## Statistics Feature

The statistics option displays:

* total number of successful students
* total number of unsuccessful students
* pass/fail counts for department `355`
* pass/fail counts for department `356`
* pass/fail counts for department `365`
* pass/fail counts for department `384`

---

## Input File Format

The input file should contain a header line followed by student records.

Format:

```text
name surname departmentCode semester score
```

Example input file:

```text
name surname departmentCode semester score
John Smith 355 6 85
Alice Brown 356 5 72
Mark White 365 7 64
Emily Stone 384 6 91
```

The first line is treated as a header and skipped by the program.

---

## Features

* Reads internship records from a text file
* Uses command-line arguments
* Skips the header line of the input file
* Stores records in a dynamically allocated array
* Automatically computes letter grades
* Displays loaded student records
* Searches by first name or full name
* Sorts records by score
* Sorts records by letter grade
* Displays overall pass/fail statistics
* Displays department-wise pass/fail statistics
* Interactive console menu

---

## How to Run

### Compile

```bash
gcc SummerInternshipProgram.c -o internship_program
```

### Run

The program requires one command-line argument: the input filename.

On Linux/macOS:

```bash
./internship_program internships.txt
```

On Windows PowerShell:

```bash
.\internship_program.exe internships.txt
```

---

## Input Requirements

This project requires an external input file.

The input file should:

* be passed as a command-line argument
* contain a header line
* contain one student internship record per line
* use spaces between values
* follow this format:

```text
name surname departmentCode semester score
```

Example project folder:

```text
SummerInternshipProgram/
├── SummerInternshipProgram.c
├── README.md
└── internships.txt
```

---

## Example Usage

```text
The student records file (internships.txt) has been successfully loaded!
name surname departmentCode semester score letterGrade
John Smith 355 6 85.0 S
Alice Brown 356 5 72.0 S
Mark White 365 7 64.0 U
Emily Stone 384 6 91.0 S

What would you like to do?
1 - search
2 - sort
3 - statistics
4 - exit
Enter your choice:
```

---

## Example Search

```text
Enter your choice: 1
Please enter the name of the student: John Smith
```

Example output:

```text
name: John
surname: Smith
department code: 355
semester: 6
score: 85.0
grade: S
```

---

## Example Statistics Output

```text
Overall: 3 student(s) passed and 1 student(s) failed!
Department: 355, 1 student(s) passed and 0 student(s) failed!
Department: 356, 1 student(s) passed and 0 student(s) failed!
Department: 365, 0 student(s) passed and 1 student(s) failed!
Department: 384, 1 student(s) passed and 0 student(s) failed!
```

---

