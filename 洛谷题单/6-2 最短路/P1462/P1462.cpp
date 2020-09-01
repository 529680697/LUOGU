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
    ll b;
    node() {}
    node(int _v, ll _b) : v(_v), b(_b) {}
};

ll n, m, b, f[maxn], max_f, d[maxn];
vector<node> adj[maxn];
bool inq[maxn];

bool spfa(ll x)
{
    if (f[1] > x || f[n] > x)
        return false;
    queue<int> q;
    fill(inq, inq + n + 1, false);
    fill(d, d + n + 1, inf);
    d[1] = 0;
    inq[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            int w = adj[u][i].b;
            if (f[v] <= x && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return d[n] <= b;
}

int main()
{
    int u, v;
    ll w;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
        cin >> f[i], max_f = max(max_f, f[i]);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(node(v, w));
        adj[v].push_back(node(u, w));
    }
    ll l = 0, r = max_f, mid, ans = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (spfa(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    if (ans != -1)
        cout << ans << endl;
    else
        cout << "AFK" << endl;
    return 0;
}