// Heap is a complete binary tree which satisfy heap order property.
// Min and Max Heap.
// Implementation using array such that for ith index left child is 2*i index and right child is 2*i+1 index.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class Heap
{
public:
    vector<int> nodes;
    int size;

    Heap()
    {
        nodes.push_back(-1);
        size = 0;
    }

    void insert(int val)
    {
        size++;
        nodes.push_back(val);

        int temp = size;
        while (nodes[temp / 2] != -1 && nodes[temp / 2] < nodes[temp])
        {
            swap(nodes[temp], nodes[temp / 2]);
            temp /= 2;
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }

    void deletion()
    {
        if (size == 1)
        {
            nodes.pop_back();
            size--;
        }

        else
        {
            nodes[1] = nodes[size];
            size--;
            nodes.pop_back();

            int temp = 1;
            if (2 * temp + 1 <= size)
            {
                if (nodes[2 * temp] > nodes[2 * temp + 1])
                {
                    swap(nodes[temp], nodes[2 * temp]);
                }
                else
                    swap(nodes[temp], nodes[2 * temp + 1]);
            }

            else
            {
                swap(nodes[temp], nodes[2 * temp]);
            }
        }
    }
};

Node *constructHeap(vector<int> &nums, int index)
{
    if (index >= nums.size())
        return NULL;

    Node *temp = new Node(nums[index]);
    temp->left = constructHeap(nums, 2 * index);
    temp->right = constructHeap(nums, 2 * index + 1);

    return temp;
}

Node *heapFromArray(vector<int> &nums)
{
    return constructHeap(nums, 1);
}

Node *predecessor(Node *root)
{
    Node *temp = root->left;
    while (temp->right != NULL && temp->right != root)
    {
        temp = temp->right;
    }
    return temp;
}

void inorder(Node *root)
{
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *pred = predecessor(curr);
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

void heapify(vector<int> &nums, int index)
{
    int curr = index;
    int lindex = 2 * curr, rindex = 2 * curr + 1;

    if (lindex < nums.size() && nums[lindex] > nums[curr])
        curr = lindex;

    if (rindex < nums.size() && nums[rindex] > nums[curr])
        curr = rindex;

    if (curr != index)
    {
        swap(nums[index], nums[curr]);
        heapify(nums, curr);
    }
}

int main()
{
    Heap h1;
    h1.insert(60);
    h1.insert(50);
    h1.insert(40);
    h1.insert(30);
    h1.insert(20);
    h1.insert(55);
    h1.insert(75);
    h1.display();
    // h1.deletion();
    // h1.display();

    Node *root = heapFromArray(h1.nodes);
    inorder(root);
    vector<int> arr;
    arr.push_back(-1);
    arr.push_back(54);
    arr.push_back(55);
    arr.push_back(53);
    arr.push_back(52);
    arr.push_back(50);
    arr.push_back(60);

    int index = (arr.size() - 1) / 2;

    for (int i = index; i > 0; i--)
    {
        heapify(arr, i);
    }

    for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}