# Hospital Patient Record Processing Program

## Description

This project is a **hospital patient record processing program** written in **C**.

The program reads patient records from a file named `data.txt`, stores the records dynamically using a structure array, displays all patient information, calculates basic statistics, and separates the records into two output files based on lung cancer status.

---

## Program Behavior

The program performs the following steps:

1. Opens and reads patient records from `data.txt`.
2. Stores each patient record in dynamically allocated memory.
3. Displays all patient records on the screen.
4. Calculates:

   * number of male patients
   * number of female patients
   * number of patients with lung cancer
   * number of patients without lung cancer
5. Creates two output files:

   * `cancer.txt`
   * `noncancer.txt`
6. Writes patients with lung cancer to `cancer.txt`.
7. Writes patients without lung cancer to `noncancer.txt`.
8. Frees dynamically allocated memory before exiting.

---

## Data Structure

Each patient is represented using a structure.

```c
typedef struct {
    int id;
    char *name;
    char *surname;
    char *gender;
    int smoking;
    char *Lung_Cancer;
} Hospital;
```

Each record stores:

| Field         | Description        |
| ------------- | ------------------ |
| `id`          | Patient ID         |
| `name`        | Patient first name |
| `surname`     | Patient surname    |
| `gender`      | Patient gender     |
| `smoking`     | Smoking status     |
| `Lung_Cancer` | Lung cancer status |

---

## Input File Format

The program requires an input file named:

```text
data.txt
```

The file should be placed in the same folder where the program is executed.

Each line should contain one patient record in this format:

```text
ID Name Surname Gender Smoking Lung_Cancer
```

Example:

```text
1 John Smith M 1 Y
2 Alice Brown F 0 N
3 David White M 1 Y
4 Emma Green F 0 N
```

---

## Fields

| Field         | Example    | Meaning                                      |
| ------------- | ---------- | -------------------------------------------- |
| `ID`          | `1`        | Patient ID                                   |
| `Name`        | `John`     | Patient first name                           |
| `Surname`     | `Smith`    | Patient surname                              |
| `Gender`      | `M` or `F` | Male or female                               |
| `Smoking`     | `1` or `0` | Smoker or non-smoker                         |
| `Lung_Cancer` | `Y` or `N` | Has lung cancer or does not have lung cancer |

---

## Generated Output Files

The program creates two output files.

### `cancer.txt`

Contains patients whose lung cancer status is `Y`.

Example:

```text
1 John Smith M 1 Y
3 David White M 1 Y
```

### `noncancer.txt`

Contains patients whose lung cancer status is `N`.

Example:

```text
2 Alice Brown F 0 N
4 Emma Green F 0 N
```

---

## Features

* Reads patient records from `data.txt`
* Stores records using dynamically allocated memory
* Uses a structure to represent each patient
* Displays patient records in table format
* Calculates gender statistics
* Calculates lung cancer statistics
* Separates records into cancer and non-cancer files
* Frees allocated memory before program exit

---

## How to Run

### Compile

```bash
gcc CStruct.c -o patient_records
```

### Run

On Linux/macOS:

```bash
./patient_records
```

On Windows PowerShell:

```bash
.\patient_records.exe
```

---

## Input Requirements

This project requires an external input file.

The input file must be named:

```text
data.txt
```

The file should be in the same directory as the executable.

Example project folder:

```text
PatientRecords/
├── CStruct.c
├── README.md
└── data.txt
```

---

## Example Console Output

```text
Patients:
ID      Name      Surname      Gender      Smoking      Lung_Cancer
1       John      Smith        M           1            Y
2       Alice     Brown        F           0            N
3       David     White        M           1            Y
4       Emma      Green        F           0            N

Statistics:
2 patient with cancer and 2 patient without cancer
2 Male and 2 Female Patients

Two files are created for you: cancer.txt and noncancer.txt!
```

---
