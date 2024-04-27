// Sum of the elements of array using recursion.
// Linear Search using recursion.

#include <iostream>
using namespace std;

int getSum(int arr[], int n)
{
    if (n == 0)
        return 0;
    else
        return arr[0] + getSum(arr + 1, n - 1);
}

bool linearSearch(int arr[], int n, int target)
{
    if (n < 0)
        return false;
    else if (arr[n] == target)
        return true;
    else
        linearSearch(arr, n - 1, target);
}

int main()
{

    int n, temp;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(i + arr);
    }

    cout << getSum(arr, n) << endl;
    cin >> temp;
    cout << linearSearch(arr, n - 1, temp) << endl;

    delete[] arr;

    return 0;
}