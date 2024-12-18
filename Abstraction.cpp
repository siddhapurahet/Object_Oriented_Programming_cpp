/*

=> Abstraction : Hiding all unnecessary details and showing only the important parts.
                 Ex: Access modifiers are a way to implement abstraction as public keyword shows all the required details and private hide it.

=> Abstraction can also be done through Abstract class
   - Abstract class basically can be used as a blueprint to create other classes. They are used to provide a base class from which other classes can be derived.
   - Abstract class cannot be initialized means we cannot make objects of that class.
   - Abstract class has at least one pure virtual function

=> Static keyword:
   - Static variable : Variables declared as static are created and initialized once for the lifetime of the program. They are shared by
                       all the objects of the class. Till the main function in code is entirely compiled and run after that the memory of
                       static keyword will be released.

*/

#include <bits/stdc++.h>
using namespace std;

class Shape // This is abstract class because it is a blueprint for all classes that will be derived from class Shape and every class will have draw() method.
{
    virtual void draw() = 0; // Here, we mentioned virtual because it is just a concept of function and the derived classes will have their
}; // own logic inside the function. If we have all methods as virtual inside a class then no need to mention abstract
   // word before the class keyword during class creation because it has automatically become abstract class.
class Square : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Square" << endl;
    }
};

int main()
{
    Square s1;
    s1.draw();
}
