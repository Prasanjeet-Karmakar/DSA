// Implementing insertion sort using array.

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int len = arr.size();
    int j;

    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        j = i - 1;
        while (arr[j] < temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    insertionSort(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}