#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;

        /* for dsu_union_by_size */
        group_size[i] = 1;

        /* for dsu_union_by_level */
        level[i] = 0;
    }
}

int dsu_find(int node)
{
    int parent = par[node];
    if (parent == -1)
    {
        return node;
    }
    /* //  naive version, complexity O(n)
    return dsu_find(parent);
    */

    /* Path compression optimization, complexity almost O(log n) */
    int leader = dsu_find(parent);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    par[leader1] = leader2; // as requirement, select leader
}

void dsu_union_by_size(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] > group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

void dsu_union_by_level(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (level[leader1] > level[leader2])
    {
        par[leader2] = leader1;
    }
    else if (level[leader1] < level[leader2])
    {
        par[leader1] = leader2;
    }
    else
    {
        par[leader1] = leader2;
        level[leader2]++;
    }
}

int main()
{
    dsu_initialize(7);
    // dsu by size
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    dsu_union_by_size(4, 1);

    // dsu by level
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);
    dsu_union_by_level(4, 5);
    dsu_union_by_level(5, 6);
    dsu_union_by_level(4, 1);

    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}