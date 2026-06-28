# Diamond Inheritance Example

## Description

This project is a simple **diamond inheritance example** written in **C++**.

The program demonstrates how multiple inheritance can create a diamond-shaped class structure and how **virtual inheritance** can be used to avoid duplicate base class objects.

---

## Program Behavior

The project defines a class hierarchy based on people, students, artists, and art students.

The base class is `Person`.

Two classes inherit from `Person`:

* `Student`
* `Artist`

Then, `ArtStudent` inherits from both `Student` and `Artist`.

This creates a diamond inheritance structure.

---

## Class Structure

```text
Person
├── Student
└── Artist
    └── ArtStudent
```

More accurately, `ArtStudent` inherits from both `Student` and `Artist`:

```text
      Person
      /    \
 Student  Artist
      \    /
    ArtStudent
```

---

## Features

* Defines a base `Person` class
* Defines a `Student` class derived from `Person`
* Defines an `Artist` class derived from `Person`
* Defines an `ArtStudent` class derived from both `Student` and `Artist`
* Uses virtual inheritance to prevent duplicate `Person` objects
* Stores student course information
* Stores artist type information
* Displays art student information

---

## Project Structure

```text
DiamondInheritance1/
├── Person.h
├── Student.h
├── Artist.h
├── ArtStudent.h
└── DiamondInheritance1.cpp
```

---

## Classes

### `Person`

The `Person` class stores common information:

* Name
* ID

It is the base class of the hierarchy.

---

### `Student`

The `Student` class inherits from `Person`.

It stores:

* Course codes
* Number of courses

It includes a function to add courses.

---

### `Artist`

The `Artist` class inherits from `Person`.

It stores the artist type.

Possible artist types include:

* Unknown
* Painter
* Music
* Sculptor
* Actor

---

### `ArtStudent`

The `ArtStudent` class inherits from both `Student` and `Artist`.

It represents a person who is both a student and an artist.

It can store:

* Name
* ID
* Artist type
* Course list

---

## Virtual Inheritance

The project uses virtual inheritance:

```cpp
class Student: virtual public Person
```

```cpp
class Artist: virtual public Person
```

This prevents `ArtStudent` from having two separate copies of the `Person` class.

Without virtual inheritance, `ArtStudent` would inherit one `Person` object from `Student` and another `Person` object from `Artist`.

---




