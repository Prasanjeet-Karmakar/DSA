// Two sorted random length arrays are provided.
// Provide the sorted union of both the arrays.

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums)
{

    for (int i = 1; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void intersection(vector<int> &v1, vector<int> &v2)
{
    int i = 0, j = 0;
    int m = v1.size(), n = v2.size();
    vector<int> finalArray;
    finalArray.push_back(INT32_MIN);

    for (; i < m || j < n;)
    {
        if (v1[i] < v2[j])
        {
            if (finalArray.back() != v1[i])
                finalArray.push_back(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j])
        {
            if (finalArray.back() != v2[j])
                finalArray.push_back(v2[j]);
            j++;
        }
        else
        {
            if (finalArray.back() != v1[i])
                finalArray.push_back(v1[i]);
            i++;
            j++;
        }
    }

    if (i < m)
    {
        while (i < m)
        {
            if (finalArray.back() != v1[i])
                finalArray.push_back(v1[i]);
            i++;
        }
    }
    if (j < n)
    {
        while (i < m)
        {
            if (finalArray.back() != v2[j])
                finalArray.push_back(v2[j]);
            j++;
        }
    }

    printArray(finalArray);
}

int main()
{
    int m, n, temp;
    cin >> m >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v1.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        v2.push_back(temp);
    }

    intersection(v1, v2);
}