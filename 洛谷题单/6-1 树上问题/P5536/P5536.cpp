#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct node
{
    int v, nxt;
} edge[maxn << 1];

int n, k, head[maxn], total;
int deep[maxn], d, d_no, maxdeep[maxn]; //树深度、直径、最深节点号、从中点可达的最大深度
int f[maxn], ans[maxn];                 //树父结点、该节点向下最大距离

inline void add_edge(int u, int v)
{
    edge[++total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
}

void dfs1(int x, int fa)
{
    if (deep[x] > d)
    {
        d = deep[x];
        d_no = x;
    }
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        deep[v] = deep[x] + 1;
        dfs1(v, x);
    }
}

void dfs2(int x, int fa)
{
    if (deep[x] > d)
    {
        d = deep[x];
        d_no = x;
    }
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        deep[v] = deep[x] + 1;
        f[v] = x;
        dfs2(v, x);
    }
}

void dfs_k(int x, int fa)
{
    maxdeep[x] = deep[x];
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        deep[v] = deep[x] + 1;
        dfs_k(v, x);
        maxdeep[x] = max(maxdeep[x], maxdeep[v]);
    }
}

bool cmp(int x, int y)
{
    return y < x;
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        add_edge(u, v), add_edge(v, u);
    }
    //两边dfs求直径
    dfs1(1, 0);
    fill(deep, deep + maxn, 0);
    d = 0;
    dfs2(d_no, 0);
    int mid = d_no; //找树直径的中点
    for (int i = 1; i <= (deep[d_no] + 1) / 2; i++)
        mid = f[mid];
    fill(deep, deep + maxn, 0);
    dfs_k(mid, 0);
    for (int i = 1; i <= n; i++)
        ans[i] = maxdeep[i] - deep[i];
    sort(ans + 1, ans + n + 1, cmp);
    int anss = 0;
    for (int i = k + 1; i <= n; i++)
        // cout << ans[i] << endl,
        anss = max(anss, ans[i] + 1);
    cout << anss << endl;
    return 0;
}