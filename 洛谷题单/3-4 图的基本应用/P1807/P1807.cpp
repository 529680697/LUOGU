#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 5005;
const int inf = 0x3f3f3f3f;

struct node
{
    int v, w;
    node() {}
    node(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, d[maxn];
vector<node> adj[maxn];
bool inq[maxn];

bool spfa(int s)
{
    memset(inq, 0, sizeof(inq));
    fill(d, d + maxn, inf);
    queue<int> q;
    q.push(s);
    inq[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].v;
            int w = adj[u][j].w;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main()
{
    int a, b, w;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back(node(b, -w));
    }
    spfa(1);
    if (d[n] != inf)
        cout << -d[n] << endl;
    else
        cout << -1 << endl;
    return 0;
}