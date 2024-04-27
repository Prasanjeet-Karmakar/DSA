// Flatten a binary tree to linked list according to preorder traversal.
// Approach 1: Using recursion: T.C = O(n) S.C = O(n)
// Approach 2: Using Morris Traversal: T.C = O(n) S.C = O(1)  -> Solved in LeetCode.

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *createTree(node *root)
{
    int val;
    cin >> val;

    root = new node(val);
    if (val == -1)
    {
        return NULL;
    }

    cout << "Enter the value of the node left of " << val << endl;
    root->left = createTree(root->left);

    cout << "Enter the value of the node right of " << val << endl;
    root->right = createTree(root->right);

    return root;
}

void flatten(node *root, node *&prev)
{
    if (root == NULL)
        return;

    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root = NULL, *prev = NULL;
    root = createTree(root);

    flatten(root, prev);
    preorder(root);

    return 0;
}