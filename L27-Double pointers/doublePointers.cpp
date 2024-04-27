// Understanding the concept of double pointers.

#include <iostream>
using namespace std;

void update(int **p)
{

    // p = p + 1; No change -> pointing to random address.
    //*p += 1; Changes.
    **p += 1; // Changes
}

int main()
{

    int n = 10;
    int *ptr = &n;
    int **dptr = &ptr;
    cout << ptr << endl;    // Printing the address of n.
    cout << *ptr << endl;   // Derefrencing the address present.
    cout << dptr << endl;   // Printing the address of ptr.
    cout << *dptr << endl;  // Derefrencing the contents present at the address.
    cout << **dptr << endl; // Derefrencing two times as *dptr is also a address pointing to another value.

    cout << dptr << endl;
    cout << *dptr << endl;
    update(dptr);
    cout << "After update " << endl;
    cout << dptr << endl;
    cout << *dptr << endl;
    cout << **dptr << endl;

    return 0;
}