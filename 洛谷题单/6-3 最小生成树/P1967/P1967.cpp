#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 5e4 + 5;

struct node
{
    int v, w, nxt;
} edge[maxm << 1], edge1[maxn << 1];

int n, m, head[maxn], total, head1[maxn], total1;
int d[maxn], fa[maxn], fw[maxn];
int deep[maxn], st[maxn][20];
bool vis[maxn];

inline void add_edge(int u, int v, int w)
{
    edge[++total].v = v;
    edge[total].w = w;
    edge[total].nxt = head[u];
    head[u] = total;
}

inline void add_edge1(int u, int v, int w)
{
    edge1[++total1].v = v;
    edge1[total1].w = w;
    edge1[total1].nxt = head1[u];
    head1[u] = total1;
}

void prim()
{
    d[1] = inf;
    fa[1] = 0;
    fw[1] = inf;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MAX = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] > MAX)
                u = j, MAX = d[j];
        if (u == -1)
            return;
        vis[u] = true;
        add_edge1(u, fa[u], MAX);
        add_edge1(fa[u], u, MAX);
        for (int j = head[u]; j; j = edge[j].nxt)
        {
            int v = edge[j].v;
            int w = edge[j].w;
            if (!vis[v] && w > d[v])
                d[v] = w, fa[v] = u;
        }
    }
}

inline void dfs(int u, int f)
{
    deep[u] = deep[f] + 1;
    st[u][0] = f;
    for (int i = 1; (1 << i) <= deep[u]; i++)
        st[u][i] = st[st[u][i - 1]][i - 1];
    for (int i = head1[u]; i; i = edge1[i].nxt)
    {
        int v = edge1[i].v;
        if (v != f)
            dfs(v, u);
    }
}

inline int lca(int a, int b)
{
    if (deep[a] > deep[b]) //保证a在b上方，即a的深度小于b
        swap(a, b);
    for (int i = 16; i >= 0; i--) //将b向上移到与a相同深度，从大到小依次试探
        if (deep[a] <= deep[b] - (1 << i))
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
    int u, v, w;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w), add_edge(v, u, w);
    }
    prim();
    dfs(1, 0);
    cin >> w;
    for (int i = 0; i < w; i++)
    {
        cin >> u >> v;
        int root = lca(u, v);
        if (root == 0)
            cout << -1 << endl;
        else
        {
            int ans = inf;
            for (int j = u; j != root; j = fa[j])
                ans = min(ans, d[j]);
            for (int j = v; j != root; j = fa[j])
                ans = min(ans, d[j]);
            cout << ans << endl;
        }
    }

    return 0;
}