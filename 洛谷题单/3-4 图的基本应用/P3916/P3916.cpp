#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;

int n, m;
int ans[maxn];
vector<int> v[maxn];
bool vis[maxn];

void dfs(int x, int now)
{
    if (vis[x] || ans[x] >= now)
        return;
    ans[x] = now;
    vis[x] = true;
    for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
        dfs(*it, now);
}
int main()
{
    int a, b;
    freopen("in", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        // cin >> a >> b;
        scanf("%d%d", &a, &b);
        v[b].push_back(a);
    }
    for (int i = n; i > 0; i--)
    {
        // fill(vis, vis + n + 1, false);
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << ans[i] << " ";
        printf("%d ", ans[i]);
    }
    // cout << endl;
    return 0;
}