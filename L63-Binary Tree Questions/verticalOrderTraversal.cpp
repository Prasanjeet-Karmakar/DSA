// Impelementing vertical order traversal.

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

vector<vector<int>> verticalOrder(node *root)
{
    vector<vector<int>> ans;
    // mapping vector with col and row.
    map<int, map <int, vector<int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;

    while(root == NULL)
        return {};

    //storing queue contains node as well as row and col.
    q.push(make_pair(root, make_pair(0, 0)));



}

int main()
{

    node *root = NULL;

    return 0;
}