#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1005;

int n, path[maxn], cnt;
string s[maxn];
vector<int> adj[maxn];
bool can_go[maxn][maxn], vis[maxn];
int fa[maxn];

inline int find_fa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find_fa(fa[x]);
}

inline void Union(int x, int y)
{
    x = find_fa(x);
    y = find_fa(y);
    if (x != y)
        fa[y] = x;
}

bool dfs(int x, int dep)
{
    if (dep == n)
        return true;
    vis[x] = true;
    for (int v, i = 0; i < adj[x].size(); i++)
    {
        v = adj[x][i];
        path[cnt++] = v;
        if (!vis[v] && dfs(v, dep + 1))
            return true;
        cnt--;
    }
    vis[x] = false;
    return false;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (s[i][s[i].length() - 1] == s[j][0])
                adj[i].push_back(j), Union(i, j);
    for (int i = 2; i <= n; i++) //判断图是否联通
    {
        if (fa[1] != fa[i])
        {
            cout << "***" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
        adj[0].push_back(i);
    if (dfs(0, 0))
    {
        for (int i = 0; i < cnt - 1; i++)
            cout << s[path[i]] << ".";
        cout << s[path[cnt - 1]] << endl;
    }
    else
        cout << "***" << endl;

    return 0;
}