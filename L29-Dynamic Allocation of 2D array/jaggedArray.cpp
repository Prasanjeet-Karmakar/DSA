// Creation and Working of jagged array.
// Jagged array is a type of 2D array which has different no of columns in different rows.

#include <iostream>
using namespace std;

int main()
{

    int n, temp;
    cin >> n;
    int *arr = new int[n];
    // Taking input for no of columns in a jagged array.
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int **jagged = new int *[n];

    // Creating n new arrays for respective pointers in jagged.
    for (int i = 0; i < n; i++)
    {
        jagged[i] = new int[arr[i]];
    }

    // Taking input for jagged array.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cin >> jagged[i][j];
        }
    }

    // Printing Output.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing or freeing memory.

    for (int i = 0; i < n; i++)
    {
        delete[] jagged[i];
    }

    delete[] jagged;
    delete[] arr;

    return 0;
}