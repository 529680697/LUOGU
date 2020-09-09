#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <queue>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e3 + 5;

struct node
{
    int v, w;
    node() {}
    node(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, d[maxn], vis[maxn], num[maxn];
vector<node> adj[maxn];

bool spfa(int s)
{
    queue<int> q;
    fill(d, d + maxn, inf);
    q.push(s);
    d[s] = 0;
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                    if (++num[v] == n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int a, b, c;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[0].push_back(node(i, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[b].push_back(node(a, c));
    }
    if (spfa(0))
        for (int i = 1; i <= n; i++)
            cout << d[i] << " ";
    else
        cout << "NO" << endl;
    return 0;
}