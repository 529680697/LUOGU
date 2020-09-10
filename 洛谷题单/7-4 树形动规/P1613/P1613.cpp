// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>

typedef long long ll;

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int n, m;
ll d[55][55];
bool g[55][55][65];

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cin.tie(nullptr);
    cin >> n >> m;
    fill(d[0], d[0] + 55 * 55, inf);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        d[a][b] = 1;
        g[a][b][0] = true;
    }
    for (int k = 1; k <= 64; k++)
        for (int l = 1; l <= n; l++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (g[i][l][k - 1] && g[l][j][k - 1])
                        g[i][j][k] = true, d[i][j] = 1;
    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
    cout << d[1][n] << endl;
    return 0;
}