#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int u, v, w;
} no[100005];

int n, m, fa1, fa2, fa[20005], enemy[20005];

bool cmp(node a, node b)
{
    return a.w > b.w;
}

inline int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

inline void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    fa[x] = y;
}

inline bool check(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> no[i].u >> no[i].v >> no[i].w;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(no, no + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (check(no[i].u, no[i].v))
        {
            cout << no[i].w << endl;
            return 0;
        }
        if (!enemy[no[i].u])
            enemy[no[i].u] = no[i].v;
        else
            Union(enemy[no[i].u], no[i].v);
        if (!enemy[no[i].v])
            enemy[no[i].v] = no[i].u;
        else
            Union(enemy[no[i].v], no[i].u);
    }
    cout << 0 << endl;
    return 0;
}