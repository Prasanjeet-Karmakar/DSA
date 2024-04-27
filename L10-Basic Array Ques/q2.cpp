// Intersection of elements of array of size n, m
// Time Complexity O(max(n,m))

// Eg. {1,2,3,4,5} and {1,3,5}
// {1,3,5} and -1 if no elements are common.
// Elements of array are in ascending order.

#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    vector<int> final;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (arr1[i] == arr2[j])
            {
                final.push_back(arr1[i]);
                j++;
                break;
            }
            else if (arr1[i] < arr2[j])
                break;

            else
                j++;
        }
    }

    return final;
}

int main()
{

    vector<int> arr1, arr2;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr1.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    vector<int> final = intersect(arr1, n, arr2, m);

    if (final.size() == 0)
        cout << "-1" << endl;

    else
    {
        for (int i = 0; i < final.size(); i++)
            cout << final[i] << " ";
    }

    return 0;
}
