/**
 * 给定一个 nn 个点 mm 条边有向图，每个点有一个权值，求一条路径，使路径经过的点权值之和最大。
 *   缩点之后拓扑排序，然后递推出最大的点权和
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;

struct node
{
    int u, v, nxt;
} edge[maxm];

int n, m, nw[maxn];                      //nw点权
int head[maxn], total_edge;              //链式向前星邻居数组、总边数
int low[maxn], dfn[maxn], times;         //回溯数组、时间戳数组、总时间
int cnt, color[maxn], count_color[maxn]; //强连通分量编号和种类标记、每种强连通分量的顶点数
stack<int> s;                            //求强连通分量辅助栈
bool vis[maxn];                          //顶点访问标记
vector<int> adj[maxn], radj[maxn], ans;  //缩点后的正向邻接表和反向邻接表、拓扑排序结果
int outdegree[maxn];                     //缩点后顶点入度
set<int> cow;

void add_edge(int u, int v)
{
    edge[++total_edge].v = v;
    edge[total_edge].u = u;
    edge[total_edge].nxt = head[u];
    head[u] = total_edge;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++times;
    s.push(x);
    vis[x] = true; //进栈标记
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        if (!dfn[edge[i].v]) //未访问该顶点，递归访问设置时间戳
        {
            tarjan(edge[i].v);
            low[x] = min(low[x], low[edge[i].v]); //回溯
        }
        else if (vis[edge[i].v])
            low[x] = min(low[x], low[edge[i].v]);
    }
    if (low[x] == dfn[x])
    {
        cnt++;
        while (x != s.top())
        {
            color[s.top()] = cnt;            //将该点染色为cnt号强连通图
            count_color[cnt] += nw[s.top()]; //统计当前强连通图点权和
            vis[s.top()] = false;            //进栈标记清空
            s.pop();
        }
        color[s.top()] = cnt;            //将该点染色为cnt号强连通图
        count_color[cnt] += nw[s.top()]; //统计当前强连通图点权和
        vis[s.top()] = false;            //进栈标记清空
        s.pop();
    }
}

int topo()
{
    for (int i = 1; i <= cnt; i++)
        if (outdegree[i] == 0)
            cow.insert(i);
    if (cow.size() > 1)
        return 0;
    int ans = 0, col = *(cow.begin());
    for (int i = 1; i <= n; i++)
        if (color[i] == col)
            ans++;
    return ans;
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 1; i <= n; i++) //缩点
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= total_edge; i++) //缩点后建图
    {
        if (color[edge[i].u] != color[edge[i].v])
        {
            u = color[edge[i].u], v = color[edge[i].v];
            outdegree[u]++, adj[u].push_back(v), radj[v].push_back(u); //统计入度并建反向图，方便后续dp
        }
    }
    cout << topo() << endl; //计算出度为0的连通块中点的个数
    return 0;
}