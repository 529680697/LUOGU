#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = 5005;

int n, m, s, e, u, v, edge_total = 1, cur[maxn], head[maxn], connect[maxn];
int w, ans, d[maxn];
bool vis[maxn][maxn];
struct EK
{
    int to, next;  //to为该边指向的节点，next为该边的下一条邻接边，即从u出发的另一条边
    int w;         //该边的容量
} edge[maxm << 1]; //奇数代表正向边，偶数为反向边

void add_edge(int u, int v, int w)
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
    fill(d, d + maxn, inf);
    queue<int> q;
    q.push(s);
    d[s] = 0;         //d表示该节点位于的层级
    cur[s] = head[s]; //初始化当前弧
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].w > 0 && d[v] == inf) //当前节点剩余容量>0且未访问过
            {
                q.push(v);
                cur[v] = head[v];  //初始化当前弧
                d[v] = d[now] + 1; //设置节点层级
                if (v == e)        //找到了一条增广路径
                    return 1;
            }
        }
    }
    return 0;
}

int dfs(int x, int sum)
{
    if (x == e) //抵达汇点
        return sum;
    int k, res = 0; //k为当前最小的剩余容量
    for (int i = cur[x]; i && sum; i = edge[i].next)
    {
        cur[x] = i; //当前弧优化
        int v = edge[i].to;
        if (edge[i].w > 0 && (d[v] == d[x] + 1)) //找到下一层级的节点
        {
            k = dfs(v, min(sum, edge[i].w));
            if (k == 0)
                d[v] = inf; //剪枝，去掉增广完毕的点
            edge[i].w -= k; //回溯时更新节点容量
            edge[i ^ 1].w += k;
            res += k; //经过该点的流量和
            sum -= k; //该点的剩余流量
        }
    }
    return res;
}

int main()
{
    int a, b;
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    s = 0, e = n + 1;
    for (int i = 1; i <= m; i++) //源点到外籍飞行员
        add_edge(0, i, 1);
    cin >> a >> b;
    while (a != -1 || b != -1) //外籍飞行员到英国飞行员
    {
        if (!vis[a][b])
        {
            add_edge(a, b, 1);
            vis[a][b] = true;
        }
        cin >> a >> b;
    }
    for (int i = m + 1; i <= n; i++) //英国飞行员到汇点
        add_edge(i, n + 1, 1);
    int ans = 0;
    while (bfs())
        ans += dfs(0, inf);
    cout << ans << endl;
    //查找可行路径
    for (int i = 2; i < edge_total; i += 2)
        if (edge[i].to <= n && edge[i].to > m && edge[i].w == 0)
            cout << edge[i ^ 1].to << " " << edge[i].to << endl;
    return 0;
}