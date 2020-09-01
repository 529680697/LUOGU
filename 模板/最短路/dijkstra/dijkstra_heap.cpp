#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> P;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct node
{
    int v, w, nxt;
} edge[maxn];

bool vis[maxn] = {false};
int dis[maxn];
int n, m, total_edge, head[maxn]; //结点个数、边个数

void add_edge(int u, int v, int w)
{
    edge[++total_edge].v = v;
    edge[total_edge].w = w;
    edge[total_edge].nxt = head[u];
    head[u] = total_edge;
}

void Dijkstra(int s)
{
    fill(dis, dis + maxn, inf);
    priority_queue<P, vector<P>, greater<P>> q;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty())
    {
        int now = q.top().second;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (int i = head[now]; i; i = edge[i].nxt)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (dis[now] + w < dis[v])
            {
                dis[v] = dis[now] + w;
                q.push(make_pair(dis[v], v));
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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        // g[u][v] = g[v][u] = w;
        add_edge(u, v, w);
        add_edge(v, u, w);
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
