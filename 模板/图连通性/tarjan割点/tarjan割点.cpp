/**
 * 无向图割点：去了之后使其不连通
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxm = 1e5 + 5;
const int maxn = 2e4 + 5;

struct node
{
    int u, v, nxt;
} edge[maxm << 1];

int n, m, head[maxn], total_edge;
int low[maxn], dfn[maxn], times;
bool cut[maxn];     //割点标记
int cut_node[maxn]; //割点编号
int cnt;            //割点数目

void add_edge(int u, int v)
{
    edge[++total_edge].u = u;
    edge[total_edge].v = v;
    edge[total_edge].nxt = head[u];
    head[u] = total_edge;
}

void tarjan(int x, int fa)
{
    low[x] = dfn[x] = ++times;
    int child = 0;
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int v = edge[i].v;
        if (!dfn[v])
        {
            tarjan(v, fa);
            low[x] = min(low[x], low[v]);
            if (low[v] >= dfn[x] && x != fa)
                cut[x] = true;
            if (x == fa)
                child++;
        }
        low[x] = min(low[x], dfn[v]);
    }
    if (child > 1 && x == fa)
        cut[x] = true;
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
    for (int i = 1; i <= n; i++)
        if (cut[i])
            cut_node[cnt++] = i;
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << cut_node[i] << " ";
    cout << endl;
    return 0;
}