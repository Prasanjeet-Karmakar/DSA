// In an array containing integers, transfer all the zeroes to the right side of the array.
// [0,1,2,0,3,4] => [1,2,3,4,0,0]

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &v) // Approach 1
{
    int len = v.size() - 1;
    for (int i = 0; i <= len; i++)
    {
        if (v[i] == 0)
        {
            int j = i + 1;
            while (j <= len)
            {
                if (v[j] != 0)
                {
                    swap(v[i], v[j]);
                    break;
                }
                j++;
            }
        }
    }
}

void movezeroes(vector<int> &nums) // Approach 2
{
    vector<int> arr1, arr2;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            arr1.push_back(nums[i]);
        else
            arr2.push_back(nums[i]);
    }

    for (int i = 0; i < arr2.size(); i++)
        nums[i] = arr2[i];

    for (int i = 0; i < arr1.size(); i++)
        nums[arr2.size() + i] = arr1[i];
}

void moveZeroes1(vector<int> &arr) // Approach 3
{
    int len = arr.size();

    int i = 0;
    for (int j = 0; j < len; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void printArray(vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int m, temp;
    cin >> m;
    vector<int> arr;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    // moveZeroes(arr);
    // movezeroes(arr);
    moveZeroes1(arr);
    printArray(arr);
}