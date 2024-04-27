// Finding all duplicates elements in an array
// array of size n should contain element between 1 to n.
// Eg. {1,4,3,2,3,4,7,8} -> {3,4}
// Required time complexity O(n)

// Below Soloution's time complexity O(nlogn)

#include <bits/stdc++.h>

using namespace std;

vector<int> findDuplicate(vector<int> &nums)
{

    vector<int> final;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i + 1 < nums.size())
            if (nums[i] == nums[i + 1])
            {
                final.push_back(nums[i]);
                i += 1;
            }
    }

    return final;
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> final = findDuplicate(v);

    for (int i = 0; i < final.size(); i++)
        cout << final[i] << " ";

    return 0;
}