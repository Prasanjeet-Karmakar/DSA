// Understanding the concept of Reference variable.
// Static and Dynamic Memory.

#include <iostream>
using namespace std;

int &function(int n) // returning local scope as a reference is a bad practise.
{
    int a = a;
    int &ans = a;

    return ans;
}

int *fun(int n) // returning local scope as a pointer is a bad practise.
{
    int *a = &n;
    return a;
}

void update(int n)
{
    n++;
}

void update2(int &n)
{
    n++;
}

int main()
{
    int n = 10;
    cout << n << endl;
    update(n);
    cout << n << endl; // No changes in n as copy of n is made with different address memory.
    // Using reference variable.
    update2(n); // Update is made in the same memory address.
    cout << n << endl;
    // cout << function(n); // Random garbage value is returned.
    return 0;
}