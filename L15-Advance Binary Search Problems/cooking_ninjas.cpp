// Binary Search Question.
// m cooks whose rank are provided in the array of length m.
// Each cook take 1r for 1st dish, 2r for 2nd dish, 3r for 3rd dish and so on.
// You will be provided with the n no of dish.
// Find the minimum time taken by the cooks to complete the dish.

#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSoln(vector<int> &v, int n, int mid)
{
    int dishCount = 0;
    int cookTime = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int j = 1;
        while (cookTime + j * v[i] <= mid)
        {
            cookTime += j * v[i];
            j++;
            dishCount++;
            if (dishCount >= n)
            {
                return true;
            }
        }
        cookTime = 0;
    }
    if (dishCount >= n)
        return true;
    else
        return false;
}

int minSolution(vector<int> &v, int n)
{
    int s = 0;
    int e = INT32_MAX;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossibleSoln(v, n, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int m, n, temp;
    cin >> m >> n;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << minSolution(v, n) << endl;
}