#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 5005;
const int INF = 0x3f3f3f3f;

int n, m, g[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};

int prim()
{
    fill(d, d + maxn, INF);
    d[1] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++)
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
        ans += d[u];
        for (int v = 1; v <= n; v++)
            if (!vis[v] && g[u][v] != INF && g[u][v] < d[v])
                d[v] = g[u][v];
    }
    return ans;
}

int main()
{
    int a, b, c;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    fill(g[0], g[0] + maxn * maxn, INF);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (g[a][b] > c)
            g[a][b] = g[b][a] = c;
    }
    int ans = prim();
    if (ans == -1)
        cout << "orz" << endl;
    else
        cout << ans << endl;
    return 0;
}