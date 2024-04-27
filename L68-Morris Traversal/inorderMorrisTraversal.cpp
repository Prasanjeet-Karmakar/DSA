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

node *findPredecessor(node *root)
{
    node *temp = root;
    root = root->left;
    while (root->right != NULL && root->right != temp)
        root = root->right;

    return root;
}

void inorderMorrisTraversal(node *root)
{
    node *curr = root;

    while (curr != NULL)
    {
        // If left of current does not exists.
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        // If exists then find the predecessor.
        else
        {
            node *pred = findPredecessor(curr);

            // 2 Sub Cases.
            // Case 1: If predecessor right does not exists. Connect predecessor right to current.
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }

            // Case 2: Right exists, remove the link between the predecessor and its right node.
            else
            {
                cout << curr->data << " ";
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

void preorderMorrisTraversal(node *root)
{
    node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }

        else
        {
            node *pred = findPredecessor(curr);
            if (pred->right == NULL)
            {
                cout << curr->data << " ";
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout << "\n";
}

int main()
{

    node *root = NULL;
    root = createTree(root);

    inorderMorrisTraversal(root);
    preorderMorrisTraversal(root);

    return 0;
}