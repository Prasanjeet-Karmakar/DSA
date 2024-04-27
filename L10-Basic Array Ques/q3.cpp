// Sort 0s and 1s
// Eg {0,1,1,0,0,1,1} => {0,0,0,1,1,1,1}
// Time Complexity = O(n)
// using 2 pointer method

#include <bits/stdc++.h>

using namespace std;

void sortArray(vector<int> &v, int size)
{

    int i = 0, j = size - 1;

    while (i < j)
    {

        while (v[i] == 0)
            i++;

        while (v[j] == 1)
            j--;

        if (i < j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;
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

    sortArray(v, v.size());

    return 0;
}