// Implementing hybrid inheritance.

#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    int a, b;

    void func1()
    {
        cout << "Func1\n";
    }
};

class D
{
public:
    int c;

    void func2()
    {
        cout << "Func2\n";
    }
};

// Implementing hierarchical from A.
class B : public A
{
public:
    int d, e;

    void func3()
    {
        cout << "Func3\n";
    }
};

// Implementing C as hierarchical inheritance from A and single from D.
class C : public A, public D
{
public:
    int f, g, h;

    void func4()
    {
        cout << "Func4\n";
    }
};

int main()
{

    A a1;
    a1.func1();
    D d1;
    d1.func2();
    B b1;
    b1.func1();
    b1.func3();
    C c1;
    c1.func1();
    c1.func2();
    c1.func4();

    return 0;
}