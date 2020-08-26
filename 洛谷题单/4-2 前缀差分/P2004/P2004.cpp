#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 5;

long long n, m, c, g[maxn][maxn], sum[maxn][maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + g[i][j];
    long long ans = 0, tmp, x, y;
    for (int i = c; i <= n; i++)
        for (int j = c; j <= m; j++)
        {
            tmp = sum[i][j] - sum[i][j - c] - sum[i - c][j] + sum[i - c][j - c];
            if (ans < tmp)
            {
                ans = tmp;
                x = i, y = j;
            }
        }
    cout << x - c + 1 << " " << y - c + 1 << endl;
    return 0;
}