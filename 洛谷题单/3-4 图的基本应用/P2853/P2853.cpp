#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 1005;

int k, n, m, cow[105], num[maxn];
vector<int> adj[maxn];
bool vis[maxn];

// void dfs(int x)
// {
//     num[x]++;
//     vis[x] = true;
//     for (int i = 0; i < adj[x].size(); i++)
//     {
//         dfs(adj[x][i]);
//     }
// }

void bfs(int s)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        num[now]++;
        for (int i = 0, v; i < adj[now].size(); i++)
        {
            v = adj[now][i];
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++)
        cin >> cow[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 0; i < k; i++)
    {
        bfs(cow[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (num[i] == k)
            ans++;
    cout << ans << endl;
    return 0;
}