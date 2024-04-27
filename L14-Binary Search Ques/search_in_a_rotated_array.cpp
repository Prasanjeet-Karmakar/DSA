// Find the index of the K in a sorted rotated array.
// Application Of Binary Search.
// Eg. [7,8,1,2,4,5], K=4
// Output: 4

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Pivot Element is itself a question of Binary Search.
int pivotElement(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (nums[mid] > nums[0])
            s = mid + 1;
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    cout << mid << endl;
    return mid;
}

int binarySearch(vector<int> &nums, int s, int e, int k)
{

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == k)
        {
            return mid;
        }
        else if (nums[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int search(vector<int> &nums, int k)
{
    int pivot = pivotElement(nums);
    int s = 0;
    int e = nums.size() - 1;

    if (k >= nums[pivot] && k <= nums[e])
    {
        s = pivot;
    }
    else if (k >= nums[0])
    {
        e = pivot - 1;
    }
    return binarySearch(nums, s, e, k);
}

// Approach 2

int Search(vector<int> &nums, int k)
{

    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == k)
            return mid;
        else if (nums[mid] > k)
        {
            if (k < nums[e])
                s = mid + 1;

            else
                e = mid - 1;
        }
        else
        {
            if (k > nums[e])
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> v;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << "Enter the element whose index you want to find." << endl;
    cin >> temp;
    cout << search(v, temp) << endl;
    cout << Search(v, temp) << endl;

    return 0;
}