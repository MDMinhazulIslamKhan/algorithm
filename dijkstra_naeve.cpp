#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];
int dist[N];
int parent[N];
void dijkstra(int src, int cost)
{
    queue<pair<int, int>> q;
    q.push({src, cost});
    dist[src] = cost;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int parNode = parent.first;
        int parCost = parent.second;
        for (pair<int, int> child : v[parNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            int childNewCost = childCost + parCost;
            if (childNewCost < dist[childNode])
            {
                dist[childNode] = childNewCost;
                q.push({childNode, childNewCost});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({b, cost});
        v[b].push_back({a, cost});
    }
    int src, cost;
    cin >> src >> cost;
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dijkstra(src, cost);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}

/* input ==>

5 8
0 1 10
0 2 7
0 3 4
1 4 3
2 4 5
2 1 1
3 4 5
3 2 1
0 0  -> this is source and cost

*/