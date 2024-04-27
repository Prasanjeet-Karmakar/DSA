// Operators can also be overloaded in C++.
// Implementing operator overloading.
// Features of polymorphism.

#include <bits/stdc++.h>
using namespace std;

class Class1
{
public:
    int a;
    int b;
    void operator+(Class1 C)
    {
        cout << "The output is : " << this->a + C.a << "\n";
    }
    /*
    void operator::() {
        cout << "Nahi Use kr sakte\n";
    }
    */

    void operator()()
    {
        cout << "Use of Brackets\n";
    }
    void operator+(int a)
    {
        cout << "Sum: " << this->a + a << endl;
    }
};

int main()
{

    Class1 c1, c2;
    c1.a = 10;
    c2.a = 20;
    c1.b = 5;
    c2.b = 50;

    c1 + c2; // Does not show as error as overloading is possible.
    c1();    // Overloading of Brackets.
    c1 + 10;

    return 0;
}