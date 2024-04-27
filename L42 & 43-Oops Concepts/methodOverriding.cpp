// Implementing runtime polymorphism -> method overriding.
// Virtual function concept.

#include <iostream>
using namespace std;

class A
{
public:
    virtual void show()
    {
        cout << "Inside Class A\n";
    }
    void peek()
    {
        cout << "Peeking Class A\n";
    }
};

class B : public A
{
public:
    void show()
    {
        cout << "Inside Class B\n";
    }
    void peek()
    {
        cout << "Peeking Class B\n";
    }
};

int main()
{
    B b1;
    b1.show();
    b1.peek();
    A *a1 = &b1;
    a1->show(); // If assigned show as virtual in class A then it will be overriden else show of A will work.
    a1->peek();

    return 0;
}