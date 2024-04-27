// Check if the array is sorted and rotated.
// If it is return true otherwise false.
// [1,2,3,4,5] => true
// [3,4,5,1,2] => true

#include <bits/stdc++.h>
using namespace std;

bool rotateSorted(vector<int> &arr)
{
    int count = 0, n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            count++;
    }

    if (arr[n - 1] > arr[0])
        count++;

    return count <= 1;
}

int main()
{

    int n, temp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << rotateSorted(v) << endl;

    return 0;
}