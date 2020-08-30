// 时间复杂度为O(nm^2)，一般能处理10^3-10^4规模的网络
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 5005;
const int maxm = 50005;

ll n, m, s, e, u, v, w, f, edge_total = 1, head[maxn]; //节点总数、每个节点的第一个邻居边在edge中的下标
ll pre[maxn], flow[maxn], d[maxn], maxflow, mincost;   //前驱、节点最大流量、节点最短距离(跑spfa)、最大流、最小费用
bool vis[maxn];
struct EK
{
    int to, next;  //to为该边指向的节点，next为该边的下一条邻接边，即从u出发的另一条边
    ll w, dis;     //该边的容量、花费
} edge[maxm << 1]; //奇数代表正向边，偶数为反向边

void add_edge(int u, int v, ll w, ll dis)
{
    edge[++edge_total].to = v;
    edge[edge_total].w = w;
    edge[edge_total].dis = dis;
    edge[edge_total].next = head[u]; //将该点插入到邻接表表头
    head[u] = edge_total;            //更新邻接表表头为该边
    edge[++edge_total].to = u;
    edge[edge_total].w = 0;
    edge[edge_total].dis = -dis;
    edge[edge_total].next = head[v]; //将该点插入到邻接表表头
    head[v] = edge_total;            //更新邻接表表头为该边
}

bool spfa()
{
    memset(vis, 0, sizeof(vis));
    fill(flow, flow + maxn, inf);
    fill(d, d + maxn, inf);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    d[s] = 0; //d存储节点花费
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now] = false;
        for (int i = head[now]; i; i = edge[i].next)
        {
            if (edge[i].w > 0 && d[edge[i].to] > d[now] + edge[i].dis)
            {
                int v = edge[i].to;
                d[v] = d[now] + edge[i].dis;
                pre[v] = i;
                flow[v] = min(flow[now], edge[i].w);
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return d[e] != inf;
}

void update() //更新边权
{
    int x = e, v;
    while (x != s)
    {
        v = pre[x];
        edge[v].w -= flow[e];
        edge[v ^ 1].w += flow[e];
        x = edge[v ^ 1].to;
    }
    maxflow += flow[e];        //累加每一条增广路径的最小流量值
    mincost += flow[e] * d[e]; //累加费用
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w >> f;
        add_edge(u, v, w, f);
    }
    while (spfa())
        update();
    cout << maxflow << " " << mincost << endl;
    return 0;
}