#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int n;
vector<int> adj[maxn], aj[maxn];
int dfn[maxn], low[maxn], times;
int cnt, color[maxn], ans;
int indegree[maxn], outdegree[maxn];
stack<int> s;
bool vis[maxn], g[maxn][maxn];

void tarjan(int x)
{
    dfn[x] = low[x] = ++times;
    s.push(x);
    vis[x] = true;
    for (int i = 0; i < adj[x].size(); i++)
    {
        int v = adj[x][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if (vis[v])
            low[x] = min(low[x], low[v]);
    }
    if (low[x] == dfn[x])
    {
        cnt++;
        while (x != s.top())
        {
            color[s.top()] = cnt;
            vis[s.top()] = false;
            s.pop();
        }
        color[s.top()] = cnt;
        vis[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int a;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        while (cin >> a && a)
            adj[i].push_back(a);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++) //缩点后建图
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j];
            if (color[i] != color[v] && !g[i][v])
            {
                indegree[color[v]]++;
                outdegree[color[i]]++;
                aj[color[i]].push_back(color[v]);
                g[i][v] = true;
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (indegree[i] == 0)
            ans1++;
        if (outdegree[i] == 0)
            ans2++;
    }
    cout << ans1 << endl;
    if (cnt == 1)
        cout << 0 << endl;
    else
        cout << max(ans1, ans2) << endl;
    return 0;
}