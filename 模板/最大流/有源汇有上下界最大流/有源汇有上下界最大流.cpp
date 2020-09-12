#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define N 205
#define M 10005
#define INF 0x7fffffff
#define min(a, b) a > b ? b : a
using namespace std;

struct Edge
{
    int to, next, cap;
} edge[M * 10];

int n, m, s, t, maxflow, cnt = -1;
int head[N], dep[N], cur[N];
queue<int> q;
inline void addEdge(int u, int v, int cost)
{
    edge[++cnt].cap = cost;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

bool bfs(int ss, int tt)
{
    while (!q.empty())
        q.pop();
    for (int i = 0; i <= n + 1; i++)
        cur[i] = head[i], dep[i] = -1;
    dep[ss] = 0;
    q.push(ss);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to, cap = edge[i].cap;
            if (cap > 0 && dep[v] == -1)
            {
                dep[v] = dep[x] + 1;
                q.push(v);
            }
        }
    }
    if (dep[tt] == -1)
        return 0;
    else
        return 1;
}

int dfs(int x, int tt, int mx)
{
    int flow;
    if (x == tt)
        return mx;
    for (int i = cur[x]; i != -1; i = edge[i].next)
    {
        cur[x] = i;
        int v = edge[i].to, cap = edge[i].cap;
        if (cap > 0 && dep[v] == dep[x] + 1 && (flow = dfs(v, tt, min(cap, mx))))
        {
            edge[i].cap -= flow;
            edge[i ^ 1].cap += flow;
            return flow;
        }
    }
    return 0;
}

void Dinic(int ss, int tt)
{
    int res = 0;
    while (bfs(ss, tt))
        while ((res = dfs(ss, tt, INF)))
            maxflow += res;
}
int main()
{
    int u, v, cost, st, ed, low, up, sum = 0;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    st = 0, ed = n + 1;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %d", &u, &v, &low, &up);
        addEdge(u, v, up - low), addEdge(v, u, 0);
        addEdge(u, ed, low), addEdge(ed, u, 0);
        addEdge(st, v, low), addEdge(v, st, 0);
        sum += low;
    }
    addEdge(t, s, INF);
    addEdge(s, t, 0);
    Dinic(st, ed); //先判断可行流
    if (sum > maxflow)
    {
        printf("please go home to sleep\n");
        return 0;
    }
    maxflow = 0;
    Dinic(s, t); //再判断最大流
    printf("%d\n", maxflow);
    return 0;
}
