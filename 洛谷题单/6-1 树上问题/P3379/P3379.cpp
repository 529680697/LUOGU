#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e5 + 5;

struct node
{
    int v, nxt;
} no[maxn << 1];

int n, m, s, head[maxn], total_edge, d[maxn], st[maxn][20];

inline void add_edge(int u, int v)
{
    no[++total_edge].v = v;
    no[total_edge].nxt = head[u];
    head[u] = total_edge;
}

inline void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    st[u][0] = fa;
    for (int i = 1; (1 << i) <= d[u]; i++)
        st[u][i] = st[st[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = no[i].nxt)
    {
        int v = no[i].v;
        if (v != fa)
            dfs(v, u);
    }
}

inline int lca(int a, int b)
{
    if (d[a] > d[b]) //保证a在b上方，即a的深度小于b
        swap(a, b);
    for (int i = 16; i >= 0; i--) //将b向上移到与a相同深度，从大到小依次试探
        if (d[a] <= d[b] - (1 << i))
            b = st[b][i];
    if (a == b) //a为两者祖先
        return a;
    for (int i = 16; i >= 0; i--)
    {
        if (st[a][i] == st[b][i]) //a、b向上移2^i深度之后祖先相同
            continue;
        else //a、b向上移2^i深度后祖先不相同
            a = st[a][i], b = st[b][i];
    }
    return st[a][0]; //此时，a、b已经不能再上移，因此返回a的父亲即可
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        add_edge(u, v), add_edge(v, u);
    }
    dfs(s, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }

    return 0;
}