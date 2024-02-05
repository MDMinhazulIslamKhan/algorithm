#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
void bfsWithLevel(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        /* if i want to print in function */
        cout << par << ", level = " << level[par] << endl;

        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}
void bfsShortestPath(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}
void printPath(int dist)
{
    if (parent[dist] == -1)
    {
        return;
    }
    printPath(parent[dist]);

    cout << parent[dist] << endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(src);
    // bfsWithLevel(src);

    /* bfc traverse with node */
    /*
    for (int i = 0; i < n; i++)
    {
        cout << i << ", level = " << level[i] << endl;
    }
    */

    /* bfc shortest path printing */

    /*
    int dist;
    cin >> dist;
    memset(parent, -1, sizeof(parent));
    bfsShortestPath(src);
    */

    /* print : 1 */
    /*
    printPath(dist);
    cout << dist << endl;
    */
    /* print : 2 */
    /*
    int x = dist;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    for (int val : path)
    {
        cout << val << " ";
    }
    */
    return 0;
}