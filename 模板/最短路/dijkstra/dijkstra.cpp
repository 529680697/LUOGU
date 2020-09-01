#include <iostream>
#include <algorithm>

using namespace std;
const int maxv = 60;
const int inf = 0x3ffff;

int g[maxv][maxv];
bool vis[maxv] = {false};
int dis[maxv];
int n, m; //结点个数、边个数

void Dijkstra(int s)
{
    dis[s] = 0;
    for (int i = 0; i < n; i++) //循环n次
    {
        int u = -1; //使d[u]最小且还没有被访问的结点
        int MIN = inf;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < MIN)
            {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1)
        {
            break;
        }
        vis[u] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && g[u][i] != 0 && dis[i] > dis[u] + g[u][i])
            {
                dis[i] = dis[u] + g[u][i];
            }
        }
    }
}

int main()
{
    int u, v, w;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(dis, dis + maxv, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    int s = 0;
    Dijkstra(s);
    for (int i = 0; i < n; i++)
    {
        if (i != s && dis[i] != inf)
        {
            cout << dis[i] << ' ';
        }
        else if (i != s && dis[i] == inf)
        {
            cout << -1 << ' ';
        }
    }
    cout << endl;
    return 0;
}
