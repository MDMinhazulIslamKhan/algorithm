#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    ll adjMax[n][n];

    // initialization with max value
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adjMax[i][j] = 0;
            else
                adjMax[i][j] = INT_MAX;
        }
    }

    // take input
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adjMax[u][v] = c;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMax[i][k] + adjMax[k][j] < adjMax[i][j])
                {
                    adjMax[i][j] = adjMax[i][k] + adjMax[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMax[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adjMax[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
input =>
4 6
3 2 8
2 1 5
1 0 2
3 0 20
0 1 3
1 2 2
*/