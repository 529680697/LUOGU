#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 6e3 + 5;

struct node
{
    int v, nxt;
} edge[maxn];

int n, a[maxn], fa[maxn], head[maxn], total;
int dp[maxn][3];

inline void add_edge(int u, int v)
{
    edge[++total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
}

int dfs(int x)
{
    if (dp[x][0])
        return dp[x][0];
    dp[x][1] = a[x];
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        dp[x][2] += dfs(edge[i].v);
        dp[x][1] += dp[edge[i].v][2];
    }
    return dp[x][0] = max(dp[x][1], dp[x][2]);
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        add_edge(v, u);
        fa[u] = v;
    }
    int x = 1;
    while (fa[x])
        x = fa[x];
    cout << dfs(x) << endl;
    return 0;
}