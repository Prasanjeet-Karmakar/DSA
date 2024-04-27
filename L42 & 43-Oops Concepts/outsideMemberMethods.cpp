// Implementing member methods outside the class using :: operator.

#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    void func1()
    {
        cout << "Inside Parent Class\n";
    }
};

class Dog : public Animal
{
public:
    void func1()
    {
        cout << "Inside Child Class\n";
    }
    void func2(); // Declaring inside the class while structuring outside using :: operator.
};

void Dog::func2()
{
    cout << "Dog has called function 2.\n";
}

int main()
{

    Dog d1;
    d1.func1(); // func1 of child class will work.
    d1.func2();

    return 0;
}