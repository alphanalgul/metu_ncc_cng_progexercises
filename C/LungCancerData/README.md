# Lung Cancer Patient Data Processor

## Description

This project is a **patient data processing program** written in **C**.

The program reads lung cancer patient records from a text file, stores them in an array of structures, displays the records, calculates basic statistics, and separates the patients into two output files based on lung cancer status.

---

## Program Behavior

The program takes two command-line arguments:

1. Input filename
2. Maximum number of patient records to store

After running, the program:

1. Opens the input file.
2. Reads patient records into an array of structures.
3. Displays all patient records in the terminal.
4. Counts:

   * male patients
   * female patients
   * patients with lung cancer
   * patients without lung cancer
5. Creates two output files:

   * `cancer.txt`
   * `non_cancer.txt`
6. Writes patients with lung cancer to `cancer.txt`.
7. Writes patients without lung cancer to `non_cancer.txt`.

---

## Data Structure Used

Each patient is represented using the following structure:

```c
typedef struct Data {
    int id;
    char name[50];
    char surname[50];
    char gender[50];
    int smoking;
    char cancer[50];
} Data;
```

---

## Patient Record Fields

| Field     | Description                                                   |
| --------- | ------------------------------------------------------------- |
| `id`      | Patient ID                                                    |
| `name`    | Patient first name                                            |
| `surname` | Patient surname                                               |
| `gender`  | Patient gender, usually `M` or `F`                            |
| `smoking` | Smoking status, usually `1` for smoker and `0` for non-smoker |
| `cancer`  | Lung cancer status, usually `Y` or `N`                        |

---

## Input File Format

The input file should contain one patient record per line.

Each line should follow this format:

```text
id name surname gender smoking cancer
```

Example:

```text
1 John Smith M 1 Y
2 Alice Brown F 0 N
3 Mark Taylor M 1 N
4 Lisa Johnson F 0 Y
```

The values should be separated by spaces.

---

## Generated Output Files

The program creates two files automatically.

### `cancer.txt`

Contains patients whose cancer field is `Y`.

Example:

```text
1 John Smith M 1 Y
4 Lisa Johnson F 0 Y
```

### `non_cancer.txt`

Contains patients whose cancer field is `N`.

Example:

```text
2 Alice Brown F 0 N
3 Mark Taylor M 1 N
```

---

## Features

* Reads patient records from a text file
* Stores records in a dynamically allocated array
* Displays all records in table-like format
* Counts male and female patients
* Counts patients with and without lung cancer
* Splits the dataset into cancer and non-cancer files
* Uses command-line arguments
* Uses file input and output

---

## How to Run

### Compile

```bash
gcc LungCancerData.c -o lung_cancer_data
```

### Run

The program requires two command-line arguments:

```bash
./lung_cancer_data input_file.txt max_records
```

Example on Linux/macOS:

```bash
./lung_cancer_data patients.txt 100
```

Example on Windows PowerShell:

```bash
.\lung_cancer_data.exe patients.txt 100
```

---

## Input Requirements

This project requires an external input file.

The input file should:

* be in the same folder as the executable, or be given with its full path
* contain one patient per line
* use spaces between values
* follow this format:

```text
id name surname gender smoking cancer
```

Example:

```text
1 John Smith M 1 Y
2 Alice Brown F 0 N
3 Mark Taylor M 1 N
4 Lisa Johnson F 0 Y
```

The second command-line argument should be the maximum number of records to allocate.

Example:

```bash
./lung_cancer_data patients.txt 100
```

Here, `100` means the program allocates space for up to 100 patient records.

---

## Example Console Output

```text
ID Name Surname Gender Smoking Lung_Cancer
1 John Smith M 1 Y
2 Alice Brown F 0 N
3 Mark Taylor M 1 N
4 Lisa Johnson F 0 Y

2 patients with cancer and 2 patients without cancer
2 Male patients and 2 Female patients
Two files are created for you: cancer.txt and non_cancer.txt!
```

---
