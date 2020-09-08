#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 16005;

struct node
{
    int v, nxt;
} edge[maxn << 1];

int n, a[maxn], dp[maxn][3];
int head[maxn], total;

inline void add_edge(int u, int v)
{
    edge[++total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
}

int dfs(int x, int fa)
{
    if (dp[x][0])
        return dp[x][0];
    dp[x][1] = a[x];
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        if (edge[i].v != fa)
        {
            dp[x][2] = max(dp[x][2], dfs(edge[i].v, x));
            dp[x][1] += max(0, dp[edge[i].v][1]);
        }
    }
    return dp[x][0] = max(dp[x][1], dp[x][2]);
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    cout << dfs(1, 0) << endl;
    return 0;
}