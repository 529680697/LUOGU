#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int n, m, fa[maxn];
char type[maxn];

int find_fa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find_fa(fa[x]);
}

void Union(int x, int y)
{
    x = find_fa(x), y = find_fa(y);
    if (x != y)
        fa[x] = y;
}

int main()
{
    int u, v;
    char c;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> (type + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        if (type[u] == type[v])
            Union(u, v);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        if (find_fa(u) == find_fa(v) && type[u] != c)
            cout << 0;
        // u = v;
        else
            cout << 1;
        // u = v;
    }
    cout << endl;
    return 0;
}
