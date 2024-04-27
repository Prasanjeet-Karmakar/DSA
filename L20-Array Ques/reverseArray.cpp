// Reverse the array in constant time complexity.

#include <bits/stdc++.h>
using namespace std;

void displayArray(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;
}

void reverseArray(vector<int> &v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        swap(v[i], v[v.size() - 1 - i]);
    }
}

// Approach 2

void reverseArray2(vector<int> &v)
{

    int s = 0, e = v.size() - 1;
    while (s < e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
}

int main()
{
    int n, temp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    reverseArray(v); // Approach 1
    displayArray(v);
    reverseArray2(v); // Approach 2
    displayArray(v);

    return 0;
}