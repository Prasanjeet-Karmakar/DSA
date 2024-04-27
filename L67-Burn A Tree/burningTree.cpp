// Approach 2: Minimum Time to Burn tree.
// Using queue and level order traversal.

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

void parentMapping(node *root, unordered_map<node *, node *> &parent, int target, node *&reqNode)
{
    queue<node *> q;
    q.push(root);
    parent[root] = NULL;

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->data == target)
            reqNode = temp;

        if (temp->left != NULL)
        {
            parent[temp->left] = temp;
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

int timeToBurnTree(node *root, unordered_map<node *, node *> &parent)
{
    queue<node *> q;
    // To check whether the node has previously been visited or not.
    unordered_map<node *, bool> visited;

    q.push(root);
    visited[root] = true;
    int ans = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            // Checking the left node.
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
                flag = 1;
            }
            // Checking the right node.
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
                flag = 1;
            }
            // checking parent.
            if (parent[temp] && !visited[parent[temp]])
            {
                q.push(parent[temp]);
                visited[parent[temp]] = true;
                flag = 1;
            }
        }

        // New node visited.
        if (flag == 1)
        {
            ans += 1;
        }
    }

    return ans;
}

int burnTree(node *root, int target)
{
    unordered_map<node *, node *> parent;
    node *reqNode = NULL;
    // Step 1: Mapping nodes with their respective parents.
    parentMapping(root, parent, target, reqNode);
    unordered_map<node *, bool> visited;
    int time = timeToBurnTree(reqNode, parent);

    return time;
}

int main()
{
    node *root = NULL;
    root = createTree(root);
    int target;
    cout << "\n Enter target Node \n";
    cin >> target;

    cout << burnTree(root, target) << "\n";

    return 0;
}