#include <bits/stdc++.h>
using namespace std;

int lastPos(vector<int> &nums, int s, int e, int target)
{
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return ans;
}

int firstPos(vector<int> &nums, int s, int e, int target)
{
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return ans;
}

vector<int> searchPos(vector<int> &nums, int target)
{
    vector<int> ans(2);
    ans[0] = firstPos(nums, 0, nums.size() - 1, target);
    ans[1] = lastPos(nums, 0, nums.size() - 1, target);

    return ans;
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

    cin >> temp;
    vector<int> ans = searchPos(v, temp);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}