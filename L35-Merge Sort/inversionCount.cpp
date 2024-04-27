// Inversion count problem.
// Inversion means how far the array is from being sorted.
// If the array is sorted, inversion count is 0 while if the array is opp. sorted the inversion count is maximum.
// Application of merge sort.

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &v, int s, int e)
{
    int count = 0;
    int mid = s + (e - s) / 2;
    int lLen = mid - s + 1, rLen = e - mid;
    vector<int> lArr(lLen);
    vector<int> rArr(rLen);

    // Copying elements into 2 arrays.
    for (int i = 0; i < lLen; i++)
        lArr[i] = v[s + i];
    for (int i = 0; i < rLen; i++)
        rArr[i] = v[mid + 1 + i];

    // Merging left and right sorted sub array.

    int i = 0, j = 0, index = s;
    while (i < lLen && j < rLen)
    {
        if (lArr[i] <= rArr[j])
            v[index++] = lArr[i++];
        else
        {
            v[index++] = rArr[j++];
            count++;
        }
    }

    while (i < lLen)
        v[index++] = lArr[i++];

    while (j < rLen)
        v[index++] = rArr[j++];

    return count;
}

int countInversion(vector<int> &v, int s, int e, int ans = 0)
{
    if (s >= e)
        return 0;

    int mid = s + (e - s) / 2;

    countInversion(v, s, mid, ans);
    countInversion(v, mid + 1, e, ans);
    ans += merge(v, s, e);
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << countInversion(v, 0, n - 1) << endl;

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}