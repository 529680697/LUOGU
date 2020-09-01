#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 205;

struct node
{
    int v, w;
    node(int _v, int _w) : v(_v), w(_w) {}
};
int n, m, no[maxn];
bool vis[maxn];
int D[maxn][maxn];

struct dis
{
    int d[maxn][maxn], cur_n;
    dis() { memcpy(d, D, sizeof(d)); }
};
map<int, dis> mp;

inline int deal(int x, int y, int t)
{
    map<int, dis>::iterator it = mp.upper_bound(t);
    it--;
    if (it->second.cur_n <= y || it->second.cur_n <= x || it->second.d[x][y] == inf)
        return -1;
    else
        return it->second.d[x][y];
}

void Dijkstra(int s, dis &d)
{
    // d.d[s][s] = 0;
    fill(vis, vis + maxn, 0);
    for (int i = 0; i < d.cur_n; i++) //循环n次
    {
        int u = -1; //使d[u]最小且还没有被访问的结点
        int MIN = inf;
        for (int j = 0; j < d.cur_n; j++)
        {
            if (!vis[j] && d.d[s][j] < MIN)
            {
                u = j;
                MIN = d.d[s][j];
            }
        }
        if (u == -1)
        {
            break;
        }
        vis[u] = true;
        for (int i = 0; i < d.cur_n; i++)
        {
            if (!vis[i] && d.d[u][i] != inf && d.d[s][i] > d.d[s][u] + d.d[u][i])
            {
                d.d[i][s] = d.d[s][i] = d.d[s][u] + d.d[u][i];
            }
        }
    }
}

inline void init()
{
    int cur_t, last_n;
    mp[-inf] = dis();
    mp[inf] = dis();
    for (int cur_n = 0; cur_n < n;)
    {
        last_n = cur_n;
        cur_t = no[cur_n];
        map<int, dis>::iterator it = mp.end();
        it--, it--;
        dis tmp = it->second;
        while (cur_t == no[cur_n])
        {
            tmp.cur_n = cur_n + 1;
            Dijkstra(cur_n, tmp);
            ++cur_n;
        }
        for (int k = last_n; k < cur_n; k++)
            for (int i = 0; i < cur_n; i++)
                for (int j = 0; j < cur_n; j++)
                    if (tmp.d[i][k] != inf && tmp.d[k][j] != inf && tmp.d[i][k] + tmp.d[k][j] < tmp.d[i][j])
                        tmp.d[i][j] = tmp.d[i][k] + tmp.d[k][j];
        mp[cur_t] = tmp;
    }
}

int main()
{
    int u, v, w, q, t;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(no, no + maxn, -1);
    for (int i = 0; i < n; i++)
        cin >> no[i];
    fill(D[0], D[0] + maxn * maxn, inf);
    for (int i = 0; i < n; i++)
        D[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        D[u][v] = D[v][u] = w;
    }
    init();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v >> t;
        cout << deal(u, v, t) << endl;
    }
    return 0;
}