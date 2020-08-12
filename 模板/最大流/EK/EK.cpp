// 时间复杂度为O(nm^2)，一般能处理10^3-10^4规模的网络
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = 5005;

int n, m, s, e, u, v, edge_total = 1, flag[maxn][maxn], head[maxn], pre[maxn];
bool vis[maxn];
ll w, ans, d[maxn];
struct EK
{
    int to, next;  //to为该边指向的节点，next为该边的下一条邻接边，即从u出发的另一条边
    ll w;          //该边的容量
} edge[maxm << 1]; //奇数代表正向边，偶数为反向边

void add_edge(int u, int v, ll w)
{
    edge[++edge_total].to = v;
    edge[edge_total].w = w;
    edge[edge_total].next = head[u]; //将该点插入到邻接表表头
    head[u] = edge_total;            //更新邻接表表头为该边
    edge[++edge_total].to = u;
    edge[edge_total].w = 0;
    edge[edge_total].next = head[v]; //将该点插入到邻接表表头
    head[v] = edge_total;            //更新邻接表表头为该边
}

bool bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;
    d[s] = inf;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            if (edge[i].w == 0)
                continue; //流量为0，忽略
            int v = edge[i].to;
            if (vis[v])
                continue;
            q.push(v), vis[v] = true;
            d[v] = min(d[now], edge[i].w);
            pre[v] = i; //记录节点前驱在所在边的存储位置
            if (v == e) //找到了一条增广路径
                return true;
        }
    }
    return 0;
}

void update() //更新边权
{
    int x = e, v;
    while (x != s)
    {
        v = pre[x];
        edge[v].w -= d[e];
        edge[v ^ 1].w += d[e];
        x = edge[v ^ 1].to;
    }
    ans += d[e]; //累加每一条增广路径的最小流量值
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        if (flag[u][v] == 0)
        {
            add_edge(u, v, w);
            flag[u][v] = edge_total;
        }
        else
            edge[flag[u][v] - 1].w += w;
    }
    while (bfs())
    {
        update();
    }
    cout << ans << endl;
    return 0;
}