// Impelementing the bubble sort using array.

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v)
{

    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        int flag = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    for (int i = 0; i < len; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int m, temp;
    cin >> m;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    bubbleSort(v);
}