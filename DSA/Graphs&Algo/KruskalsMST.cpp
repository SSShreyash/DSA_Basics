
#include <bits/stdc++.h>
using namespace std;

int nassignments = 0;
int nedges = 0;
int ncomparisons = 0;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void union_func(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());

        DSU s(V);
        int res = 0;
        cout << "Following are the edges in the constructed MST: " << endl;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            ncomparisons++;
            if (s.find(x) != s.find(y))
            {
                ncomparisons++;
                s.union_func(x, y);
                res += w;
                cout << x << " -> " << y << " == " << w << endl;
            }
        }

        cout << "Minimum Cost of Spanning Tree: " << res;
    }
};

int main()
{
    int n;
    cout << "Enter the no. of nodes to include in the graph:  ";
    cin >> n;
    Graph G(n);
    int x, y, w;
    srand(time(0));

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Enter the values for node x, node y and edge weight w between them.

    for (int i = 0; i < n * n; i++)
    {
        x = rand() % n;
        y = rand() % n;
        w = 5 + rand() % 155;

        if (visited[x][y] == false && x != y)
        {
            nassignments += 2;
            G.addEdge(x, y, w);
            nedges++;
            visited[x][y] = true;
            G.addEdge(y,x,w);
            visited[y][x] = true;
        }
        
    }

    G.kruskals_mst();

    cout << "\n\n"
         << "No. of assignments: " << nassignments << endl;
    cout << "No. of edges: " << nedges << endl;
    cout << "No. of comparisons: " << ncomparisons << endl;

    return 0;
}
