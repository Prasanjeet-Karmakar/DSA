#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    int nodes;
    vector<vector<int>> adj;
    bool flag; // 1 -> Directed Graph,  0 -> Undirected Graph.

    Graph(int n, bool f)
    {
        nodes = n;
        for (int i = 0; i < n; i++)
        {
            adj.push_back({});
        }
        flag = f;
    }

    void insertEdge(int src, int des)
    {
        adj[src].push_back(des);
        if (flag == 1)
            adj[des].push_back(src);
    }

    void printGraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << "-> ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void topoSort()
    {
        queue<int> q;
        vector<int> indegree(nodes, 0);

        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        for (int i = 0; i < nodes; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;
                if (indegree[adj[temp][i]] == 0)
                    q.push(adj[temp][i]);
            }
        }

        cout << endl;
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    Graph g(v, 1);
    int src, dest;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        g.insertEdge(src, dest);
    }

    g.printGraph();

    return 0;
}
