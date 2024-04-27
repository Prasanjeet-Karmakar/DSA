// Return the sum of maximum and minimum elements in all subarrays of window size k.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int findSum(vector<int> &arr, int k)
{
    int s = 0;
    deque<int> maxi, mini;

    // For first window.
    for (int i = 0; i < k; i++)
    {

        while (!maxi.empty() && arr[maxi.back()] < arr[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);

        while (!mini.empty() && arr[mini.back()] > arr[i])
        {
            mini.pop_back();
        }
        mini.push_back(i);
    }

    s += arr[maxi.front()] + arr[mini.front()];

    // For rest of the windows.
    for (int i = k; i < arr.size(); i++)
    {
        if (maxi.front() <= i - k)
        {
            maxi.pop_front();
        }
        if (mini.front() <= i - k)
        {
            mini.pop_front();
        }

        // Pushing maximum and minimum to the front for their respective queues.
        while (!maxi.empty() && arr[maxi.back()] < arr[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);

        while (!mini.empty() && arr[mini.front()] > arr[i])
        {
            mini.pop_back();
        }
        mini.push_back(i);

        s += arr[maxi.front()] + arr[mini.front()];
    }

    return s;
}

int main()
{

    vector<int> arr;
    int n, temp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    cin >> temp;
    cout << findSum(arr, temp) << endl;

    return 0;
}