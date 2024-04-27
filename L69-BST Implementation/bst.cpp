// Implementing BST and its basic operations : Insert, Search, Delete
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        this->data = d;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *insertInBst(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (root->data > d)
    {
        root->left = insertInBst(root->left, d);
    }

    if (root->data < d)
    {
        root->left = insertInBst(root->right, d);
    }

    return root;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << " " << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

Node *insertIntoBst(Node *&root)
{
    int d;
    cout << "Enter value of nodes and -1 to stop \n";
    cin >> d;

    while (d != -1)
    {
        root = insertInBst(root, d);
        cin >> d;
    }

    return root;
}

int main()
{

    Node *root = NULL;
    root = insertIntoBst(root);
    levelOrderTraversal(root);
    inorder(root);

    return 0;
}