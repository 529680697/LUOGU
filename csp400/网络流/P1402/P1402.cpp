#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 405;
const int maxm = 25005;

int n, p, q, s, e;
int u, v, edge_total = 1, cur[maxn], head[maxn];
ll w, ans, d[maxn];
struct EK
{
    int to, next;  //to为该边指向的节点，next为该边的下一条邻接边，即从u出发的另一条边
    ll w;          //该边的容量
} edge[maxm << 1]; //奇数代表正向边，偶数为反向边

inline void add(int u, int v, int w)
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

int dfs(int x, ll sum)
{
    if (x == e) //抵达汇点
        return sum;
    ll k, res = 0; //k为当前最小的剩余容量
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
    int a;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> p >> q;
    s = 0, e = 2 * n + p + q + 1;
    for (int i = 1; i <= q; i++) //源点到房间
        add(0, i, 1);
    for (int i = p + 1; i <= p + n; i++) //房间到人
        for (int j = 1; j <= p; j++)
        {
            cin >> a;
            if (a)
                add(j, i, 1);
        }
    for (int i = p + 1; i <= p + n; i++) //人到人
        add(i, i + n, 1);
    for (int i = p + n + 1; i <= p + 2 * n; i++)
        for (int j = p + 2 * n + 1; j <= p + q + 2 * n; j++) //人到菜
        {
            cin >> a;
            if (a)
                add(i, j, 1);
        }
    for (int i = p + 2 * n + 1; i <= p + q + 2 * n; i++) //菜到汇点
        add(i, e, 1);
    while (bfs())
    {
        ans += dfs(s, inf);
    }
    cout << ans << endl;
    return 0;
}