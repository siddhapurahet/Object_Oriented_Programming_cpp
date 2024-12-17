/*

=> Destructor : It is special function which compiler creates and destructor deallocates the memory allocated by constructor.
                The compiler automatically deallocates the memory once main function is over.
                Destructor only erases the static allocated memory.

*/

#include <bits/stdc++.h>
using namespace std;

class Teacher
{

public:
    Teacher(string name, string sub)
    {
        this->name = name;
        dept = "Science";
        subject = new string;
        *subject = sub;
    }

    ~Teacher() // Syntax of Destructor
    {
        cout << "Destructor called..." << endl;
        delete subject;
    }

private:
    double salary;

public:
    string name;
    string dept;
    string *subject;

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Department : " << dept << endl;
        cout << "Subject: " << *subject << endl;
    }
};

int main()
{

    Teacher t1("Het", "Science");
    t1.getInfo();

    return 0;
}