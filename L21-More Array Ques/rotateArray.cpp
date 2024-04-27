// Rotate array clockwise by k elements.
// Using mod is the best approach. as % n => [0,n-1]

#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &v, int k)
{
    vector<int> num(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        num[(i + k) % v.size()] = v[i];
    }

    v = num;
}

void printArray(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n, temp, k;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    cin >> k;
    rotateArray(arr, k);
    printArray(arr);

    return 0;
}