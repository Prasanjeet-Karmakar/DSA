// Occurs ambiguity in Diamond form inheritance.
//     A
//    / \
//   B   C
//    \ /
//     D
// When D wants to call member function of A, then compiler gets confused that through which class B or C can the function be accessed.

#include <iostream>
using namespace std;

class A
{
    int a, b;

public:
    void show()
    {
        cout << "A function.\n";
    }
};

class B : virtual public A
{
public:
};

class C : public virtual A
{
public:
};

class D : public B, public C
{
public:
};

int main()
{
    D d1;
    // Although having diamond inheritance, there occurs no ambiguity. Only one copy of A is transferred.
    d1.show();
    return 0;
}
