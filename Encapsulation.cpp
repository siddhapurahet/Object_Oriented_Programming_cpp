/*

=> Encapsulation : It is wrapping up of data and member functions in a single unit called class.
                   It helps in data hiding as we can make that data private.
                   Ex: The example of Teacher class in class_Object file is encapsulation only because the methods
                       and attributes are within the class in which they are used and the salary is private which
                       explains the data hiding.

=> Constructor : It is special method invoked automatically at the time of object creation.
                 Basically when class is created, at that time memory is not allocated but when objects are created
                 at that time the memory is initialized by constructor
                 Ex: teachert1.name, so constructor will create memory for name variable

=> Properties of Constructor :
   - Constructor name should be same as class name.
   - It doesnt have any return type.
   - It is only called automatically once when object is created, if user creates the constructor then it is not called
     automatically.
   - Memory allocation happens when constructor is called.
   - Constructor is always made public because it has to call the main function.
   - They are of two types:
      - Parameterized (this is not called automatically, user has to call it).
      - Non-parameterized (this is called automatically by compiler).
   - One class can have more than one constructor but should have different parameters. And this is called Constructor Overloading.

*/

#include <bits/stdc++.h>
using namespace std;

class Teacher
{

public:
    Teacher()
    {                     // Constructor of class Teacher (Non-parameterized)
        dept = "Science"; // With all the objects created for class Teacher, the dept value will be automatically assigned as Science.
    }

private:
    double salary;

public:
    string name;
    string dept;
    string subject;
};

// --------------------------------------------------------------

class Children
{

public:
    Children(string n, int std, string sub)
    {
        name = n;
        standard = std;
        subject = sub;
    }

    Children(string name, string subject) // Example of constructor overloading and this pointer. It is used to access
    {                                     // the properties of object, basically passing just (n, std, sub) is not proper
        this->name = name;                // so we are passing the actual names but they are conflicting wth the attributes of object, hence we use this pointer for that.
        this->subject = subject;
    }

public:
    string name;
    int standard;
    string subject;

    void getInfo()
    {
        cout << "Name is: " << name << endl;
        cout << "Standard is: " << standard << endl;
    }

    void getInfo2()
    {
        cout << "Name is: " << name << endl;
        cout << "Subject is: " << subject << endl;
    }
};

int main()
{

    Children child1("Het", 10, "Hindi"); // Parameterized constructor.
    // child1.getInfo();
    Children child2("Harsh", "English"); // Parameterized constructor.
    child2.getInfo2();
    return 0;
}
