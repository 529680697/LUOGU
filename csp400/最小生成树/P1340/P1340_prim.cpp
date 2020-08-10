#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;
const int maxn = 205;
const int inf = 0x3f3f3f3f;

struct node
{
    int v, w;
    node(int _v, int _w) : v(_v), w(_w) {}
};

int n, w, d[maxn];
bool vis[maxn];
vector<node> adj[maxn];

inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    x = x * f;
}

int prim()
{
    fill(d, d + maxn, inf);
    memset(vis, false, sizeof(vis));
    d[1] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = -1, MIN = inf;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        }
        if (u == -1)
            return -1;
        vis[u] = true;
        ans += d[u];
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].v;
            if (!vis[v] && adj[u][j].w < d[v])
                d[v] = adj[u][j].w;
        }
    }
    return ans;
}

//判断是否已存在该邻接边，存在则置换为较短的距离，否则返回false
inline bool find(int a, int b, int dis, bool &unreplace)
{
    bool flag = false;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (adj[a][i].v == b)
        {
            if (adj[a][i].w > dis)
            {
                adj[a][i].w = dis;
                flag = true;
                break;
            }
            else
            {
                unreplace = true;
                return true;
            }
        }
    }
    if (!flag)
        return false;
    for (int i = 0; i < adj[b].size(); i++)
    {
        if (adj[b][i].v == a && adj[b][i].w > dis)
        {
            adj[b][i].w = dis;
            return true;
        }
    }
    return false;
}

int main()
{
    clock_t s, e;
    s = clock();
    int a, b, dis, ans;
    bool unreplace = false;
    freopen("in.txt", "r", stdin);
    read(n), read(w);
    for (int i = 0; i < w; i++)
    {
        read(a), read(b), read(dis);
        // if (find(a, b, dis, unreplace))
        // {
        //     if (unreplace)
        //         printf("%d\n", ans);
        //     else
        //     {
        //         printf("%d\n", (ans = prim()));
        //     }
        // }
        // else
        // {
        adj[a].push_back(node(b, dis));
        adj[b].push_back(node(a, dis));
        //     printf("%d\n", (ans = prim()));
        // }
        printf("%d\n", prim());
    }
    e = clock();
    cout << "The run time is: " << (double)(e - s) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}