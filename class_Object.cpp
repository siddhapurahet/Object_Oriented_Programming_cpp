/*

=> Objects : Objects are entities in real world.

=> Class : Class is like a blueprint or can also be called as group of object.
           Whenever making a class, give name of class as the entity for which you are creating class.
           Ex: For creating database of teachers, give class name as Teacher.

=> Access Modifiers:
   => Private : All the Properties and Methods are by default private. It means it cannot be used outside the class. See the syntax in code.
   => Public : All the Properties and Methods are accessed everywhere.
   => Protected : All the Properties and Methods are accesses inside the class but outside the class, it is accessible to only the derives classes of the classes mentioned under protected.

=> Note: We can access the private attributes of class through get and set methods. See example below for better understanding.

*/

#include <bits/stdc++.h>
using namespace std;

class Teacher
{
private:
    double salary;

public:
    // Properties or attributes
    string name;
    string dept;
    string subject;

    // Methods or Member functions
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    void setSalary(double newSalary)
    {
        salary = newSalary;
    }

    double getSalary()
    {
        return salary;
    }
};

int main()
{

    Teacher teacherT1; // Syntax to create object of class (Classname object)
    teacherT1.name = "Het";
    teacherT1.dept = "HOD";
    teacherT1.subject = "History";
    // teacherT1.salary = 50000.00;
    teacherT1.setSalary(60000.00);
    cout << teacherT1.getSalary();
    return 0;
}
