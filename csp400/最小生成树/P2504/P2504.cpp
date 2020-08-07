#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1005;

struct node
{
    int x, y;
} tree[maxn];

int m, n, a[maxn], g[maxn][maxn], d[maxn];
bool vis[maxn];

int prim()
{
    fill(d, d + maxn, INF);
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return -1;
        vis[u] = true;
        ans = max(ans, d[u]);
        for (int v = 0; v < n; v++)
            if (!vis[v] && g[u][v] < d[v])
                d[v] = g[u][v];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tree[i].x >> tree[i].y;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            g[j][i] = g[i][j] = (tree[i].x - tree[j].x) * (tree[i].x - tree[j].x) + (tree[i].y - tree[j].y) * (tree[i].y - tree[j].y);
    int ans = prim(), num = 0;
    // cout << ans << endl;
    for (int i = 0; i < m; i++)
    {
        if (ans <= a[i] * a[i])
            num++;
    }
    cout << num << endl;
    return 0;
}