//SPFA算法，无向图
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

struct node
{
    int v;
    ll w;
    node() {}
    node(int _v, ll _w) : v(_v), w(_w) {}
};

ll n, m, d[maxn], num[maxn];
vector<node> adj[maxn];
bool inq[maxn];

bool spfa(int s)
{
    queue<int> q;
    fill(inq, inq + maxn, false);
    fill(d, d + maxn, inf);
    fill(num, num + maxn, 0);
    d[s] = 0;
    inq[s] = true;
    q.push(s);
    num[s]++; //记录顶点入队次数
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                    num[v]++;
                    if (num[v] >= n)
                        return false; //有可达负环
                }
            }
        }
    }
    return true;
}

int main()
{
    int u, v;
    ll w;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(node(v, w));
        adj[v].push_back(node(u, w));
    }
    if (spfa(1)) //无可达负环
        cout << d[n] << endl;
    else //有可达负环
        cout << "-inf" << endl;
    return 0;
}