// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3005;

struct node
{
    int v, w;
    node() {}
    node(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, value[maxn], dp[maxn][maxn];
vector<node> adj[maxn];

int dfs(int u)
{
    if (u > n - m)
    {
        dp[u][1] = value[u];
        return 1;
    }
    int sum = 0, t;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i].v;
        t = dfs(v); //这个儿子为根的子树大小
        sum += t;   //当前节点u可选的用户数
        for (int j = sum; j > 0; j--)
            for (int k = 1; k <= t; k++)
                if (j - k >= 0)
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - adj[u][i].w);
    }
    return sum;
}

int main()
{
    int a, b, num;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    fill(dp[0], dp[0] + maxn * maxn, -inf);
    for (int i = 1; i <= n - m; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> a >> b;
            adj[i].push_back(node(a, b));
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> value[i];
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    dfs(1);
    for (int i = m; i > 0; i--)
    {
        if (dp[1][i] >= 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}