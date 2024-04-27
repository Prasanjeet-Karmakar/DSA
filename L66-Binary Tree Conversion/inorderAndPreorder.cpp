// Construct binary tree from preorder and inorder traversal.
// Approach 2: using hashmaps
// All nodes have unique values.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

unordered_map<int, int> pos;
Node *solve(vector<int> &inorder, vector<int> &preorder, int &index, int st, int e)
{
    // Base Case:
    if (st > e)
        return NULL;

    Node *node = new Node(preorder[index]);
    index++;

    if (st == e)
    {
        return node;
    }

    int loc = pos[node->val];

    node->left = solve(inorder, preorder, index, st, loc - 1);
    node->right = solve(inorder, preorder, index, loc + 1, e);

    return node;
}

Node *constructTree(vector<int> &inorder, vector<int> &preorder)
{
    int index = 0;
    // Storing pos of indexes acc to inorder.
    for (int i = 0; i <= inorder.size() - 1; i++)
        pos[inorder[i]] = i;

    Node *ans = solve(inorder, preorder, index, 0, preorder.size() - 1);

    return ans;
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "{}" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->val << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
    cout << endl;
}

int main()
{
    vector<int> preorder, inorder;
    int n, temp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        preorder.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        inorder.push_back(temp);
    }

    Node *root = constructTree(inorder, preorder);
    levelOrder(root);

    return 0;
}
