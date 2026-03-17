#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char* name;
public:
    Person() {
        name = new char[20];
        strcpy(name, "Not provided");
        cout << "Person()" << endl;
    }

    Person(char* str) {
        name = new char[20];
        strcpy(name, str);
        cout << "Person(char* str)" << endl;
    }

    ~Person() {
        delete[] name;
        cout << "Person destructor" << endl;
    }
};

class Student : virtual public Person {
protected:
    int id;
public:
    Student() {
        id = 0;
        cout << "Student()" << endl;
    }

    Student(char* str, int i) : Person(str) {
        id = i;
        cout << "Student(char* str, int i)" << endl;
    }

    ~Student() {
        cout << "Student destructor" << endl;
    }
};

class Academic : virtual public Person {
protected:
    int SSN;
public:
    Academic() {
        SSN = 0;
        cout << "Academic()" << endl;
    }

    Academic(char* str, int i) : Person(str) {
        SSN = i;
        cout << "Academic(char* str, int i)" << endl;
    }

    ~Academic() {
        cout << "Academic destructor" << endl;
    }
};

class StudentAcademic : public Student, public Academic {
public:
    StudentAcademic(char* str, int i, int j)
        : Person(str), Student(str, i), Academic(str, j) {
        cout << "StudentAcademic()" << endl;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "SSN: " << SSN << endl;
    }

    ~StudentAcademic() {
        cout << "StudentAcademic destructor" << endl;
    }
};

int main() {
    cout << "CONSTRUCTORS CALLED TO A STUDENTACADEMIC OBJECT:" << endl;
    StudentAcademic* S = new StudentAcademic("Zekican Budin", 8252192, 894161);

    cout << endl << "THE STUDENTACADEMIC OBJECT:" << endl;
    S->show();

    cout << endl << "DESTRUCTORS CALLED DESTROY THE OBJECT:" << endl;
    delete S;

    return 0;
}
