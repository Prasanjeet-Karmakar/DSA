// Playing with pointers.

#include <iostream>
using namespace std;

int main()
{

    int num = 10;
    int *ptr = &num;
    /*
        Same as the above code.
        int *ptr = 0;
        ptr = &num;
    */

    cout << &ptr << endl; // Address of ptr variable.
    cout << ptr << endl;  // Address of num as ptr contains address of num.
    cout << *ptr << endl; // Derefrencing the pointer by using *.

    // copying a pointer.

    int *q = ptr; // not creating a new space like a pointer pointing to data type.
    cout << q << " " << ptr << endl;
    cout << *q << " " << *ptr << endl;
    cout << &q << " " << &ptr << endl;

    // Pointer airthmetics..

    cout << *ptr++ << endl;
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << (*ptr)++ << endl;
    cout << ptr << endl;
    cout << *(ptr++) << endl;
    cout << ptr << endl;

    // increementing pointer value by 1 means adding the size of the data type in the current address
    // ptr += 1 means ptr will point to next address space i.e &num + 4 as int takes 4 byte of data.

    ptr += 1;
    cout << ptr << endl;

    // Double Pointer.

    int **dptr = &ptr;
    cout << dptr << endl; // Same as &ptr

    // Triple pointer and similarly n pointers.
    int ***tptr = &dptr; // Same as &dptr

    // Wild pointer
    // int *wptr;
    // *wptr = 5;
    // cout << wptr << endl;
    // cout << *wptr << endl;

    return 0;
}