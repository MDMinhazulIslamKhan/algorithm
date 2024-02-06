#include <bits/stdc++.h>

using namespace std;
// size of matrix
int r, c;
// value of matrix
int value[20][20];
// visit tracking
bool vis[20][20];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int cn, int cm)
{
    if (cn >= r || cn < 0 || cm >= c || cm < 0)
    {
        return false;
    }
    else
        return true;
}
void dfs(int sn, int sm)
{
    // cout << sn << " " << sm << endl;
    cout << value[sn][sm] << endl;
    vis[sn][sm] = true;
    for (int i = 0; i < 4; i++)
    {
        int cn = sn + v[i].first;
        int cm = sm + v[i].second;
        if (isValid(cn, cm) && vis[cn][cm] == false)
        {
            dfs(cn, cm);
        }
        else
            continue;
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> value[i][j];
        }
    }

    int sn, sm;
    cin >> sn >> sm;
    memset(vis, false, sizeof(vis));
    dfs(sn, sm);

    return 0;
}