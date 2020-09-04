#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxm = 5005;

struct node
{
    int p, q;
    char ef;
} tmp[maxm];

int n, m, fa[1005];
vector<int> e[1005];
bool isroot[1005];

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
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> tmp[i].ef >> tmp[i].p >> tmp[i].q;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        if (tmp[i].ef == 'F')
            Union(tmp[i].p, tmp[i].q);
        else
        {
            e[tmp[i].p].push_back(tmp[i].q);
            e[tmp[i].q].push_back(tmp[i].p);
        }
    }
    for (int i = 1; i <= n; i++)
        if (e[i].size() > 1)
            for (int j = 1; j < e[i].size(); j++)
                Union(e[i][j - 1], e[i][j]);
    for (int i = 1; i <= n; i++)
        isroot[find_fa(i)] = true;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (isroot[i])
            ans++;
    cout << ans << endl;
    return 0;
}