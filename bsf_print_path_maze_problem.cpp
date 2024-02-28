#include <bits/stdc++.h>

using namespace std;
int r, c;
int dr, dc;
int sr, sc;
char value[1005][1005];
bool vis[1005][1005];
pair<int, int> par[1005][1005];

vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

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

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int pr = parent.first;
        int pc = parent.second;
        vis[pr][pc] = true;
        for (int i = 0; i < 4; i++)
        {
            int cr = pr + v[i].first;
            int cc = pc + v[i].second;
            if (isValid(cr, cc) && !vis[cr][cc] && value[cr][cc] != '#')
            {
                q.push({cr, cc});
                vis[cr][cc] = true;
                par[cr][cc] = {pr, pc};
            }
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
            par[i][j] = {-1, -1};
            if (value[i][j] == 'R')
            {
                sr = i;
                sc = j;
            }
            if (value[i][j] == 'D')
            {
                dr = i;
                dc = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(sr, sc);
    // cout << par[2][1].first << " " << par[2][1].second << endl;

    while (par[dr][dc].first != -1)
    {
        if (value[dr][dc] == 'R')
        {
            break;
        }
        else if (value[dr][dc] != 'D')
        {
            value[dr][dc] = 'X';
        }
        int temp_dr = dr;
        dr = par[dr][dc].first;
        dc = par[temp_dr][dc].second;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << value[i][j];
        }
        cout << endl;
    }
    return 0;
}

/*

input =>

5 6
...D.#
.##..#
....#.
.R#...
.#.##.


output =>

...D.#
.##X.#
.XXX#.
.R#...
.#.##.

*/
