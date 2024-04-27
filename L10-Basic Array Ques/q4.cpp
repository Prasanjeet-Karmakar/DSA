// Sort 0s 1s and 2s
// Eg. {1,0,1,2,2,1,0,1,2} => {0,0,1,1,1,1,2,2,2}
// Time complexity O(n)


// OPTIMIZATION REQUIRED O(N^2)

#include <bits/stdc++.h>

using namespace std;

void sortElements(vector<int> &v, int size)
{

    int i = 0, j, k = size - 1;

    while (i < k)
    {
        while (v[i] == 0)
            i++;
        while (v[k] == 2)
            k--;

        if (v[i] == 1)
        {
            j = i + 1;
            while (v[j] != 0 && j < size)
                j++;
            if (v[j] == 0)
            {
                swap(v[i], v[j]);
            }
            i++;
        }

        else if (v[i] == 2)
        {
            swap(v[i], v[k]);
            k--;
        }

        if (v[k] == 0)
            swap(v[i], v[k]);

        else if (v[k] == 1)
        {
            j = k - 1;
            while (v[j] != 2 && j > 0)
                j--;

            if (v[j] == 2)
                swap(v[j], v[k]);
            k--;
        }
    }

    // Printing the array.

    for (int i = 0; i < size; i++)
        cout << v[i] << " ";

    cout << endl;
}

int main()
{

    vector<int> v;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sortElements(v, n);

    return 0;
}