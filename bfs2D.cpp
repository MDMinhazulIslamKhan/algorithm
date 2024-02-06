#include <bits/stdc++.h>

using namespace std;
int r, c;
int dr, dc;
int sr, sc;
int value[20][20];
int dist[20][20];
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

void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    dist[sr][sc] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int pr = parent.first;
        int pc = parent.second;
        vis[pr][pc] = true;

        /* if we want to print all value */
        // cout << value[pr][pc] << endl;
        for (int i = 0; i < 4; i++)
        {
            int cr = pr + v[i].first;
            int cc = pc + v[i].second;
            if (isValid(cr, cc) && vis[cr][cc] == false)
            {
                q.push({cr, cc});
                vis[cr][cc] = true;
                dist[cr][cc] = dist[pr][pc] + 1;
            }
            else
                continue;
        }
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

    cin >> sr >> sc;
    cin >> dr >> dc;
    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    bfs(sr, sc);

    cout << dist[dr][dc];
    return 0;
}

/*
input
3 4
01 02 03 04
05 06 07 08
09 10 11 12
1 1
0 0
*/