// Implementing Binary Tree

#include <iostream>
#include <queue>
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

void levelOrderTraversal(node *root)
{
    queue<node *> q;

    if (root == NULL)
    {
        cout << "Tree is Empty\n";
        return;
    }

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    cout << "\n";
}

node *createTreeFromLevelOrder(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }

    node *root = new node(arr[0]);
    int index = 1;
    queue<node *> q;
    q.push(root);

    while (index < arr.size())
    {
        node *temp = q.front();
        q.pop();
        temp->left = new node(arr[index]);
        q.push(temp->left);
        index++;
        if (index < arr.size())
        {
            temp->right = new node(arr[index]);
            index++;
            q.push(temp->right);
        }
    }

    return root;
}

void iterativeInorder(node *root)
{
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    return 1 + max(lheight, rheight);
}

int diameterUtil(node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = diameterUtil(root->left, maxi);
    int rheight = diameterUtil(root->right, maxi);

    maxi = max(maxi, lheight + rheight);

    return 1 + max(lheight, rheight);
}

int diameter(node *root)
{
    int maxi = -1;

    diameterUtil(root, maxi);

    return maxi;
}

int main()
{

    node *root = NULL;
    root = createTree(root);
    // levelOrderTraversal(root);
    // 1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 9 -1 10 -1 -1 11 -1 15 -1 -1
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    // root = createTreeFromLevelOrder(arr);
    // levelOrderTraversal(root);

    cout << diameter(root) << endl;

    return 0;
}