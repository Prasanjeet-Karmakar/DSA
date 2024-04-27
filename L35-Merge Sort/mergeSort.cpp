// merge sort using recursion.
// Approach1 - creating new array.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // Creating 2 new arrays for copying elements of original array to divided array.
    int llen = mid - s + 1;
    int rlen = e - mid;
    vector<int> larr(llen);
    vector<int> rarr(rlen);

    // Copying elements from original array to new arrays.
    for (int i = 0; i < llen; i++)
    {
        larr[i] = arr[s + i];
    }
    for (int i = 0; i < rlen; i++)
    {
        rarr[i] = arr[mid + 1 + i];
    }

    // Merging both the sorted arrays into original array.
    int i = 0, j = 0, index = s;
    while (i < llen && j < rlen)
    {
        if (larr[i] <= rarr[j])
            arr[index++] = larr[i++];

        else
            arr[index++] = rarr[j++];
    }

    while (i < llen)
        arr[index++] = larr[i++];

    while (j < rlen)
        arr[index++] = rarr[j++];
}

void mergeSort(vector<int> &arr, int s, int e)
{

    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
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

    mergeSort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}