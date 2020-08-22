#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
const int maxn = 1e5 + 5;

int n, m;
set<int> node[maxn];
bool vis[maxn];

void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    cout << x << " ";
    // for (int i = 0; i < node[x].size(); i++)
    //     dfs(node[x][i]);
    for (set<int>::iterator it = node[x].begin(); it != node[x].end(); it++)
        dfs(*it);
    // vis[x] = false;
}

void bfs()
{
    fill(vis, vis + n + 1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (set<int>::iterator it = node[now].begin(); it != node[now].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        node[a].insert(b);
    }
    fill(vis, vis + n + 1, false);
    dfs(1);
    cout << endl;
    bfs();
    return 0;
}