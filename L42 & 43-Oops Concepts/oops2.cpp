#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string surname; // cannot be accessible in child class/
public:
    int age;
    string name;

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

// Basic Inheritance
class Student : private Person // public -> private and can be only accessed within the class i.e. by member functions.
{
public:
    int id;

    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return this->age;
    }
};

int main()
{
    Student obj1;
    obj1.setAge(20);
    // obj1.setName("Prasanjeet");
    obj1.setId(2051);

    cout << " " << obj1.getAge() << " " << obj1.getId() << endl;
    return 0;
}