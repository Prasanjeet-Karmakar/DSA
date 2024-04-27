// Finding all the subsets using bit manipulation.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr)
{
    vector<vector<int>> ans;
    // Total mask will be 0 - 2^n-1 : n is the no of elements.
    int power = 1 << arr.size();

    // Iterating through every bit mask...
    for (int i = 0; i < power; i++)
    {
        vector<int> temp;
        for (int j = 0; j < arr.size(); j++) // Checking whether the mask present at jth position is set or not.
        {
            if (i & (1 << j)) // Condition for checking of set.
                temp.push_back(arr[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> ans = subsets(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}