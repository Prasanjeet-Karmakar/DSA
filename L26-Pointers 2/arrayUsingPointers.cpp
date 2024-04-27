// Observing array using pointers.

#include <iostream>
using namespace std;

int main()
{

    int arr[10] = {1, 6, 91, 101, 4};
    cout << arr << endl; // Starting address of arr
    cout << (*arr)++ << endl;
    cout << arr[0] << endl;

    // printing element at index i using pointer => *(arr + i) = arr[i]

    cout << *(arr + 3) << endl;

    // i[arr] = *(i + arr) will not result to error and it is same as arr[i]
    cout << 2 [arr] << endl;
    cout << *(arr + 2) << endl;

    cout << *arr << endl;
    cout << &arr << endl;

    return 0;
}