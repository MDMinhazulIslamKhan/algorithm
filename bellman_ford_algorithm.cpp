#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    int u;
    int v;
    int c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e5 + 5;

int dist[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    int src;
    cin >> src;
    // initialization with max value
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }

    // initialize source
    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            c = ed.c;
            v = ed.v;
            if (dist[u] < INT_MAX && dist[u] + c < dist[v])
            {
                dist[v] = dist[u] + c;
            }
        }
    }

    // print
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;
}

/*
input =>
4 4
0 2 5
0 3 12
2 1 2
1 3 3
0
*/