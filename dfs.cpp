#include <bits/stdc++.h>
using namespace std;
const int r = 500;
bool vis[r];
vector<int> v[r];
void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    // system : 1
    for (int child : v[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }

    /* system : 2 */
    /*

    for (int i = 0; i < v[src].size(); i++)
    {
        int child = v[src][i];
        if (!vis[child])
        {
            dfs(child);
        }
    }

    */
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
    dfs(src);
    return 0;
}