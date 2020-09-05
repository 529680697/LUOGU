#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

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
int indegree[maxn];                      //缩点后顶点入度
int dp[maxn];                            //DAGdp数组，表示以i结束的路径上顶点权值最大和

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

void topo()
{
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
}

int DAGdp()
{
    for (int i = 0; i < ans.size(); i++) //按拓扑排序后的顺序进行遍历，使得以之后的点结束的权值和必可以通过之前的dp求的
    {
        int w = ans[i];
        dp[w] = count_color[w];
        for (int j = 0; j < radj[w].size(); j++)
            dp[w] = max(dp[w], dp[radj[w][j]] + count_color[w]);
    }
    int _max = 0; //选出最大的权值
    for (int i = 1; i <= cnt; i++)
        _max = max(_max, dp[i]);
    return _max;
}

int main()
{
    int u, v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> nw[i];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 1; i <= n; i++) //缩点
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= total_edge; i++) //缩点后建图
    {
        if (color[edge[i].u] != color[edge[i].v])
        {
            u = color[edge[i].u], v = color[edge[i].v];
            indegree[v]++, adj[u].push_back(v), radj[v].push_back(u); //统计入度并建反向图，方便后续dp
        }
    }
    topo(); //拓扑排序
    cout << DAGdp() << endl;
    return 0;
}