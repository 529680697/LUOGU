#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300;

int n, a[maxn], dp[maxn][maxn];
bool u[maxn][maxn];

int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    if (x == y)
    {
        u[x][y] = true;
        return dp[x][y] = a[x];
    }
    int tmp = 0;
    for (int i = x; i < y; i++)
    {
        int l = dfs(x, i), r = dfs(i + 1, y);
        if (l == r && u[x][i] && u[i + 1][y])
        {
            if (tmp <= l + 1)
            {
                tmp = l + 1;
                u[x][y] = true;
            }
        }
        else
        {
            if (tmp < l)
            {
                tmp = l;
                u[x][y] = false;
            }
            if (tmp < r)
            {
                tmp = r;
                u[x][y] = false;
            }
        }
    }
    return dp[x][y] = tmp;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs(0, n - 1) << endl;
    return 0;
}