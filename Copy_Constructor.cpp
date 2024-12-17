/*

=> Copy Constructor : It copies the properties of one object to another.
                      There are two types (Syntax differs, check for it below) :
                       - default
                       - custom

=> Shallow copy : A shallow copy of an object copies all of the member values from one object to another.
                  Ex: The copy constructor
Note: Shallow copy creates a problem during dynamic allocation of memory.

=> The default constructor only constructs shallow copy, for deep copy user has to create the constructor for that.

=> Deep copy : It copies the member values and also make copies of dynamically allocated memory that attribute points to.

*/

#include <bits/stdc++.h>
using namespace std;

class Teacher
{

public:
    Teacher(string name, string subject)
    {
        this->name = name;
        dept = "Science";
        this->subject = subject;
    }

    Teacher(Teacher &copyConstobj) // Custom copy constructor syntax
    {
        cout << "Inside Custom copy constructor" << endl;
        this->name = copyConstobj.name;
        this->dept = copyConstobj.dept;
        this->subject = copyConstobj.subject;
    }

private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Department : " << dept << endl;
        cout << "Subject: " << subject << endl;
    }
};

// ----------------------------------------------------

class Student // This Student class highlights the problem of shallow copy where in first s1 object values are created and copied into s2 object, then cgpa value of s2 object is changed and s1 object is printed but surprisingly the cgpa of s1 object is also changed which should not because we changed cgpa value for s2 and not s1. The reason is shallow copy because the memory allocated to cgpa for both object were different but the address was not so both were pointing to the same memory address. To understand better, try running the code.
{

public:
    Student(string name, double cgpaPtr)
    {
        this->name = name;
        cgpa = new double;
        *cgpa = cgpaPtr;
    }

    Student(Student &copyConstobj)
    {
        cout << "Inside Custom copy constructor" << endl;
        this->name = copyConstobj.name;
        this->cgpa = copyConstobj.cgpa;
    }

public:
    string name;
    double *cgpa;

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA : " << *cgpa << endl;
    }
};

// -----------------------------------------------------

class StudentDeepCopyExample // Deep copy example
{

public:
    StudentDeepCopyExample(string name, double cgpaPtr)
    {
        this->name = name;
        cgpa = new double;
        *cgpa = cgpaPtr;
        cout << "Value of cgpaPtr in constructor" << cgpaPtr << endl;
        cout << "Value of cgpa in constructor" << cgpa << endl;
        cout << "Value of cgpa in constructor" << *cgpa;
    }

    StudentDeepCopyExample(Student &copyConstobj)
    {
        cout << "Inside Custom copy constructor" << endl;
        this->name = copyConstobj.name;
        cgpa = new double;
        *cgpa = *copyConstobj.cgpa;
        cout << "Value of cgpa in copy constructor" << copyConstobj.cgpa << endl;
        cout << "Value of cgpa in copy constructor" << cgpa << endl;
        cout << "Value of *cgpa in copy constructor" << *cgpa << endl;
    }

public:
    string name;
    double *cgpa;

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA : " << *cgpa << endl;
    }
};

int main()
{

    StudentDeepCopyExample s1("Het", 9.0);
    cout << "Getting object s1 info: " << endl;
    s1.getInfo();
    cout << endl;

    StudentDeepCopyExample s2(s1);
    s2.name = "Harsh";
    *(s2.cgpa) = 10.0;

    cout << "Getting object s2 info: " << endl;
    s2.getInfo();

    // --------- Above is the code for shallow copy concept -------------
    // --------- Below is the code for shallow copy concept -------------

    Student st1("Het", 9.0);
    st1.getInfo();

    Student s2(st1);
    s2.name = "Harsh";
    *(s2.cgpa) = 10.0;

    st1.getInfo();

    return 0;
}