/*

=> Inheritance : When properties and member functions of base class are passed on to the derived class.
               - This is used for code reusability.
               - During inheritance, first the constructor of parent class is called then the constructor of child class is called.
               - Wherein during destructuring, first memory of child class will be destructured, then memory of parent class will be deallocated.

=> Modes of Inheritance:
    ___________________________________________________________________
    |            |  Derived class  |  Derived class  |  Derived class  |
    | Base class |   Private mode  |  Protected mode |   Public mode   |
    | Private    |  Not inherited  |  Not inherited  |  Not inherited  |
    | Protected  |   Private       |    Protected    |    Protected    |
    | Public     |   Private       |   Protected     |     Public      |


=> Types of Inheritance:

Single-level Inheritance    Multi-level Inheritance        Multiple Inheritance         Hierarichal Inheritance      Hybrid Inheritance

     Parent class                Parent class           Parent class  Parent class 2          Parent class              Parent class
         |                             |                       |             |                      |                        |
         |                             |                       |             |                   ___|____                ____|___
      Child class                  Child class 1               |_____________|                   |      |                |       |
                            (parent of child class 2)                 |                          |      |               Child   Child
                                       |                              |                      Child    Child            class 1  class 2
                                       |                          Child class               class 1   class 2                      |
                                    Child class 2                                                                                  |
                                                                                                                                 Child
                                                                                                                                class 3

=> Polymorphism : Ability of objects to take on different forms or behave in different ways depending on the context in which they are used.
   - Types :
     - Compile time polymorphism
       Ex: Constructor overloading (See code of PolymorphismExample class).
           Function overloading (Same as above where in functions have same name but parameters are different and both functions are in same class).

     - Run time polymorphism
       Ex: Function overriding (When parent and child both contain the same function with different implementations, then parent class is said to be overridden).

*/

#include <bits/stdc++.h>
using namespace std;

class Car
{

public:
    Car(int tyres, int seats)
    {
        this->tyres = tyres;
        this->seats = seats;
    }

public:
    int tyres;
    int seats;
};

class Maruti : public Car // Syntax for Inheritance where Car is parent class and Maruti is child class.
{
public:
    string color;
    string model;

    Maruti(string color, string model, int tyres, int seats) : Car(tyres, seats) // Syntax for calling parameterized constructor from parent
    {                                                                            // to child because parameterized constructor is not called by compiler automatically.
        this->color = color;
        this->model = model;
    }

    void getInfo()
    {
        cout << "No of tyres: " << tyres << endl;
        cout << "No of seats: " << seats << endl;
        cout << "Color: " << color << endl;
        cout << "Model: " << model << endl;
    }
};

class PolymorphismExample
{
public:
    int age;
    double newAge;

    PolymorphismExample()
    {
        cout << "Non-parameterized constructor called" << endl;
    }

    PolymorphismExample(int age)
    {
        this->age = age;
        cout << "Parameterized constructor called" << endl;
    }

    void showInfo(int age)
    {
        cout << "age is: " << age;
    }

    void showInfo(double newAge)
    {
        cout << "New age is: " << newAge;
    }
};

int main()
{

    Maruti m1("Black", "KL65", 4, 5);
    // m1.tyres = 4;
    // m1.seats = 5;
    // m1.color = "Black";
    // m1.model = "JH545";
    m1.getInfo();

    // PolymorphismExample p1;            // Example of Polymorphism, same object but different behaviour during compilation because of parameter changes.
    // PolymorphismExample p1(23);

    // p1.showInfo(20);    // Example of Function overloading
    // p1.showInfo(20.0);
}

// --------------------------------------------------------------

class Parent // Function overriding example
{
public:
    void getInfo()
    {
        cout << "Parent class" << endl;
    }
};

class Child : public Parent
{
public:
    void getInfo()
    {
        cout << "Child class" << endl;
    }
};

int main()
{

    Child c1;
    c1.getInfo(); // Outputs Child class
    Parent p1;
    p1.getInfo(); // Outputs Parent class
}
