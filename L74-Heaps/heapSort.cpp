// Implementing Heap Sort.
// T.C = O(nlogn)

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &nums, int index, int size)
{
    int curr = index;
    int lindex = 2 * curr + 1, rindex = lindex + 1;

    if (lindex <= size && nums[curr] < nums[lindex])
        curr = lindex;
    if (rindex <= size && nums[curr] < nums[rindex])
        curr = rindex;

    if (curr != index)
    {
        swap(nums[curr], nums[index]);
        heapify(nums, curr, size);
    }
}

void heapSort(vector<int> &arr)
{
    int size = arr.size() - 1;
    int index = 0;

    while (size >= 1)
    {
        swap(arr[index], arr[size]);
        heapify(arr, index, --size);
    }
}

int main()
{

    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // arr.push_back(4);
    // arr.push_back(1);
    // arr.push_back(3);
    // arr.push_back(7);
    // arr.push_back(9);

    int size = arr.size() - 1;
    for (int i = size / 2; i >= 0; i--)
    {
        heapify(arr, i, size);
    }

    heapSort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}