// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 8e4 + 5;
const int maxm = 2e5 + 5;

struct node
{
    int u, v, w, nxt;
    double p;
} edge[maxm];

struct no
{
    int v, w;
    no() {}
    no(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, beg, head[maxn], total;
int low[maxn], dfn[maxn], times; //回溯数组、时间戳数组、总时间
int cnt, color[maxn];            //强连通分量编号和种类标记
stack<int> s, es;                //求强连通分量辅助栈、边栈
bool vis[maxn];                  //顶点访问标记
vector<no> adj[maxn];            //缩点后的正向邻接表
int nw[maxn];                    //缩点后各点点权

inline void add_edge(int u, int v, int w, double p)
{
    edge[++total].v = v;
    edge[total].u = u;
    edge[total].p = p;
    edge[total].nxt = head[u];
    edge[total].w = w;
    head[u] = total;
}

int count_sum(int x)
{
    double p = edge[x].p;
    int ans = edge[x].w, tmp = edge[x].w * p;
    while (tmp)
    {
        ans += tmp;
        tmp *= p;
    }
    return ans;
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
            es.push(i);
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
            color[s.top()] = cnt; //将该点染色为cnt号强连通图
            vis[s.top()] = false; //进栈标记清空
            s.pop();
        }
        color[s.top()] = cnt; //将该点染色为cnt号强连通图
        vis[s.top()] = false; //进栈标记清空
        s.pop();
    }
}

bool inq[maxn];
int d[maxn];

void spfa(int s)
{
    queue<int> q;
    fill(d, d + maxn, -1);
    d[s] = nw[s];
    inq[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (d[v] < d[u] + w + nw[v])
            {
                d[v] = d[u] + w + nw[v];
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int u, v, w;
    double p;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w >> p;
        add_edge(u, v, w, p);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        if (color[edge[i].v] == color[edge[i].u])
        {
            int id = color[edge[i].v];
            nw[id] += count_sum(i);
        }
        else
        {
            u = color[edge[i].u];
            v = color[edge[i].v];
            adj[u].push_back(no(v, edge[i].w));
        }
    }
    cin >> beg;
    beg = color[beg];
    spfa(beg);
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        ans = max(ans, d[i]);
    cout << ans << endl;
    return 0;
}