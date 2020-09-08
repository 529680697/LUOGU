#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

struct node
{
    int v, nxt;
} edge[maxn << 1];

int n, q, dp[maxn][maxn];
int head[maxn], total, wi[maxn][maxn];

inline void add_edge(int u, int v, int w)
{
    edge[++total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
    wi[u][v] = w;
}

int dfs(int x, int num, int fa)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return wi[fa][x];
    else if (dp[x][num])
        return dp[x][num];
    int child[2], j = 0;
    for (int i = head[x]; i; i = edge[i].nxt)
        if (edge[i].v != fa)
            child[j++] = edge[i].v;
    dp[x][num] = wi[fa][x];
    if (j == 0)
        return dp[x][num];
    for (int i = 0; i < num; i++)
    {
        dp[x][num] = max(dp[x][num], wi[fa][x] + dfs(child[0], i, x) + dfs(child[1], num - i - 1, x));
    }
    return dp[x][num];
}

int main()
{
    int a, b, c;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    cout << dfs(1, q + 1, 0) << endl;
    return 0;
}