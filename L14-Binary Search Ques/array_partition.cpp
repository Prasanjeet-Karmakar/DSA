// Create every possible pair for an array and return the maximum of sum of every min element for that pair in that array.
// [1,4,3,2]
// Output = 4

// All possible pairings (ignoring the ordering of elements) are:
// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4.

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pairArraySum(vector<int> &nums)
{

    int sum = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }

    return sum;
}

int main()
{

    vector<int> v;
    int n, temp;
    cout << "Enter the value of n (multiple of 2)" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << pairArraySum(v);
}