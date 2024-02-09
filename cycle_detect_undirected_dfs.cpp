#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
bool vis[N];
bool path[N];
bool ans;
int parent[N];
vector<int> v[N];
void dfs(int src)
{
    vis[src] = true;
    path[src] = true;
    for (int child : v[src])
    {
        if (path[child])
        {
            ans = true;
        }
        if (!vis[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
    path[src] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    memset(v, 0, sizeof(v));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    memset(path, false, sizeof(path));

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (ans)
    {
        cout << "Cycle found";
    }
    else
        cout << "Cycle not found";

    return 0;
}