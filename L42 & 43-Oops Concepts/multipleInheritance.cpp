// Understanding the concept of multiple inheritance in c++.
// Ambiguity occurs in multiple inheritance.

#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    string type;

public:
    void sound()
    {
        cout << "Making Sound" << endl;
    }
    // Occurs Ambiguity
    void func()
    {
        cout << "Inside Animal\n";
    }
};

class Mammal
{
public:
    string animal;

public:
    void bark()
    {
        cout << "Barking" << endl;
    }
    // Occurs Ambiguity
    void func()
    {
        cout << "Inside Mammal\n";
    }
};

class Dog : public Animal, public Mammal
{
public:
    int age;
    string name;

public:
    void setAge(int age)
    {
        this->age = age;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int getAge()
    {
        return this->age;
    }
    string getName()
    {
        return this->name;
    }
};

int main()
{

    Dog d1;
    d1.setAge(4);
    d1.setName("Tiger");

    d1.sound();
    d1.bark();
    cout << d1.getAge() << " " << d1.getName() << endl;

    // Wants to access func from d1 which will cause ambiguity to compiler.
    // Can be resolved using :: scope resolution operator

    // Causes error :
    // d1.func();
    d1.Animal::func();
    d1.Mammal::func();

    return 0;
}