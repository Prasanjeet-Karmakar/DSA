// Understanding the concept of the dynamic memory allocation.

#include <bits/stdc++.h>
using namespace std;

int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(i + arr);

    return sum;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n]; // Total of n*4 bytes in heap and 8 bytes in stack for pointer is allocated.
    // Taking input..
    for (int i = 0; i < n; i++)
        cin >> i[arr];

    cout << getSum(arr, n) << endl;

    return 0;
}