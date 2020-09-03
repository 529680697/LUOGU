#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e4 + 5;

struct ndoe
{
    int v, nxt;
} edge[maxn << 1];

int n, head[maxn], total, _size[maxn], d[maxn], dp[maxn], ans_node, ans = inf;
bool vis[maxn];

void add(int a, int b)
{
    edge[++total].v = b;
    edge[total].nxt = head[a];
    head[a] = total;
}

int dfs(int s, int dep)
{
    vis[s] = true;
    _size[s] = 1;
    d[s] = dep;
    dp[1] += d[s];
    for (int i = head[s]; i; i = edge[i].nxt)
        if (!vis[edge[i].v])
            _size[s] += dfs(edge[i].v, dep + 1);
    return _size[s];
}

void dfs1(int x, int f)
{
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int v = edge[i].v;
        if (!vis[v])
        {
            vis[v] = true;
            dp[v] = dp[x] + n - (_size[v] << 1);
            if (dp[v] < ans)
            {
                ans = dp[v];
                ans_node = v;
            }
            else if (dp[v] == ans && ans_node > v)
                ans_node = v;
            dfs1(v, x);
        }
    }
}

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << _size[i] << " ";
    // }
    // cout << dp[1] << endl;
    fill(vis, vis + maxn, 0);
    ans_node = 1;
    ans = dp[1];
    vis[1] = true;
    dfs1(1, 0);
    cout << ans_node << " " << ans << endl;
    return 0;
}