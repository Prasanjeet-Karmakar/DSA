// Binary Search using Recursion.

#include <vector>
#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key)
{
    // Base Case..
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;
    // Different Conditions for Recursion.
    if (arr[mid] == key)
        return true;
    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, e, key);
    else
        return binarySearch(arr, s, mid - 1, key);
}

int main()
{

    int n, key;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> *(arr + i);

    cin >> key;
    cout << binarySearch(arr, 0, n - 1, key);
    delete[] arr;

    return 0;
}