// Creation of 2D array using dynamic memory allocation.

#include <iostream>
using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;
    int **arr = new int *[m]; // Assigning m pointers to the heap.
    // Creation of arrays with m pointers.
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[m];
    }

    // Input...
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output...
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Freeing or deleting the dynamically allocated memory.
    // First remove the sub arrays created and then delete the pointers.

    for (int i = 0; i < m; i++)
    {
        delete[] arr[i]; // Deleting the sub arrays.
    }

    // Deleting the pointers array.
    delete[] arr;

    // Memory Released.

    return 0;
}