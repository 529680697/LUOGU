#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 35;

int n, a[maxn], dp[maxn][maxn], no[maxn][maxn];

int dfs1(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    if (x == y)
    {
        dp[x][y] = a[x];
        return a[x];
    }
    else if (x > y)
        return 1;
    int tmp_max = 0, no_max = x;
    for (int i = x; i <= y; i++)
    {
        int ttmp = dfs1(x, i - 1) * dfs1(i + 1, y) + a[i];
        if (tmp_max < ttmp)
        {
            tmp_max = ttmp;
            no_max = i;
        }
    }
    no[x][y] = no_max;
    dp[x][y] = tmp_max;
    return dp[x][y];
}

void dfs2(int x, int y)
{
    if (x > y)
        return;
    else if (x == y)
    {
        cout << x + 1 << " ";
        return;
    }
    cout << no[x][y] + 1 << " ";
    dfs2(x, no[x][y] - 1);
    dfs2(no[x][y] + 1, y);
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs1(0, n - 1) << endl;
    dfs2(0, n - 1);
    return 0;
}