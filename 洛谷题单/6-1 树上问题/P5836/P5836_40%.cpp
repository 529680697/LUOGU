#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct node
{
    int u, v, nxt;
} edge[maxn << 1];

int n, m, head[maxn], total;
int depth[maxn], fa[maxn];
bool vis[maxn];
char type[maxn];

void add_edge(int u, int v)
{
    edge[++total].u = u;
    edge[total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
}

void dfs(int x, int f)
{
    depth[x] = depth[f] + 1;
    fa[x] = f;
    vis[x] = true;
    for (int i = head[x]; i; i = edge[i].nxt)
        if (!vis[edge[i].v])
            dfs(edge[i].v, x);
}

bool deal(int x, int y, char c)
{
    if (type[x] == c || type[y] == c)
        return true;
    if (x == y)
        return false;
    if (depth[x] > depth[y])
        return deal(fa[x], y, c);
    else if (depth[x] < depth[y])
        return deal(x, fa[y], c);
    else
        return deal(fa[x], fa[y], c);
}

int main()
{
    int u, v;
    char c;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> (type + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        if (type[u] == c || type[v] == c)
        {
            cout << 1;
            continue;
        }
        if (deal(u, v, c))
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}