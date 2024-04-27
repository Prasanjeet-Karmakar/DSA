// Find the index of minimum element in rotated sorted array.
// Eg. {3,7,9,1,2} => 3

#include <iostream>
#include <vector>

using namespace std;

int minRotate(vector<int> &v)
{
    int f = 0, e = v.size() - 1;

    while (f < e)
    {
        int mid = f + (e - f) / 2;
        if (v[mid] >= v[0])
            f = mid + 1;

        else
            e = mid;
    }
    return e;
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

    int index = minRotate(v);

    cout << index << endl;

    return 0;
}