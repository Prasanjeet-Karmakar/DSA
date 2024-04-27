// Find the index of the pivot element in the array
// The pivot element is the one whose left side array sum ==  right side array sum.
// Eg. {1,7,3,5,6,5} => 3 is the ans as left side from 3rd index is equal to right side from it.
// If no such index is present , return -1.

#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> &nums)
{

    int f = 0, l = nums.size() - 1;
    int fsum = 0, lsum = 0;

    for (int i = 0; i <= l; i++)
        lsum += nums[i];

    while ((fsum != lsum) && (f <= l))
    {
        if (f == 0)
            fsum = fsum + 0;
        else
            fsum += nums[f - 1];

        lsum -= nums[f];

        f++;
    }

    if (fsum == lsum)
        return f - 1;
    else
        return -1;
}

int main()
{

    vector<int> v;
    int k;

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int index = pivotIndex(v);

    cout << index << endl;

    return 0;
}