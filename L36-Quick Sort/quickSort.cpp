// Implementing Quick Sort.

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int s, int e)
{
    // Choosing the first array as pivot element, can also choose the last array or mid array as pivot.
    int p = v[s];
    int count = 0; // Storing the no. of elements smaller than the pivot.

    // Counting the no. of elements smaller than pivot.
    for (int i = s + 1; i <= e; i++)
        if (v[i] < p)
            count++;

    // Placing the pivot element to its correct position.
    swap(v[s], v[s + count]);
    int pivot = s + count;
    int i = s, j = e;

    // Arranging the array such that left contain smaller and right contain larger than pivot element.
    while (i < pivot && j > pivot)
    {
        while (v[i] < v[pivot])
            i++;
        while (v[j] > v[pivot])
            j--;

        swap(v[i], v[j]);
        i++;
        j--;
    }
    // returning the position of the pivot element.
    return s + count;
}

void quickSort(vector<int> &v, int s, int e)
{
    // Base Case ..
    if (s >= e)
        return;

    // Receiving the position of pivot element after its proper position in every sub array.
    int pivot = partition(v, s, e);

    // dividing the array into 2 parts: left sub array containing all the elements smaller than pivot,
    // right sub array containing all the elements greater than pivot.
    quickSort(v, s, pivot - 1);
    quickSort(v, pivot + 1, e);
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

    quickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}