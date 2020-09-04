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

int n, m, head[maxn], total_edge, d[maxn], st[maxn][22];

inline int get_num()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x;
}

inline void add_edge(int u, int v)
{
    no[++total_edge].v = v;
    no[total_edge].nxt = head[u];
    head[u] = total_edge;
}

void dfs(int u, int fa)
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

int lca(int a, int b)
{
    if (d[a] > d[b]) //保证a在b上方，即a的深度小于b
        swap(a, b);
    for (int i = 20; i >= 0; i--) //将b向上移到与a相同深度，从大到小依次试探
        if (d[a] <= d[b] - (1 << i))
            b = st[b][i];
    if (a == b) //a为两者祖先
        return a;
    for (int i = 20; i >= 0; i--)
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
    int a, b, c;
    freopen("in", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cin >> n >> m;
    n = get_num(), m = get_num();
    for (int i = 0; i < n - 1; i++)
    {
        // cin >> a >> b;
        a = get_num(), b = get_num();
        add_edge(a, b), add_edge(b, a);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        // cin >> a >> b >> c;
        a = get_num(), b = get_num(), c = get_num();
        int f1 = lca(a, b);
        int f2 = lca(b, c);
        if (d[f1] == d[f2])
            f2 = lca(a, c);
        if (d[f1] < d[f2])
            // cout << f2 << " " << d[a] + d[b] + d[c] - d[f1] - d[f2] - d[f1] << endl;
            printf("%d %d\n", f2, d[a] + d[b] + d[c] - d[f1] - d[f2] - d[f1]);
        else
            // cout << f1 << " " << d[a] + d[b] + d[c] - d[f1] - d[f2] - d[f2] << endl;
            printf("%d %d\n", f1, d[a] + d[b] + d[c] - d[f1] - d[f2] - d[f2]);
    }

    return 0;
}