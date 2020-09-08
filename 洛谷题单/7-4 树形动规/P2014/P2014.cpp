#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 305;

struct node
{
    int v, nxt;
} edge[maxn];

int n, m, head[maxn], total, wi[maxn];

inline void add_edge(int u, int v)
{
    edge[++total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
}

int main()
{
    int v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> wi[i];
        add_edge(v, i);
    }

    return 0;
}