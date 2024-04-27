// Same function name but different functionalities.
// Feature of compile time polymorphism.

#include <bits/stdc++.h>
using namespace std;

class Class1
{
public:
    int a, b;
    // Parameterised Constructor.
    // Constructors are created public so that they can be accessed outside the class. Otherwise creation of object is not possible.
    Class1(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void func1()
    {
        cout << this->a + this->b << endl;
    }
    void func1(int a, int b)
    {
        cout << a + b << endl;
    }
    int func1(int a)
    {
        cout << this->a + a << endl;
    }
    void func1(string name)
    {
        cout << "Name: " << name << "\n";
    }
};

int main()
{

    Class1 c1(5, 10);
    cout << c1.a << " " << c1.b << "\n";
    c1.func1();
    c1.func1("Connor");
    c1.func1(10, 15);
    c1.func1(100);

    return 0;
}