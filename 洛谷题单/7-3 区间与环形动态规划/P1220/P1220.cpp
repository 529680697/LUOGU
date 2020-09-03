#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 55;

struct node
{
    int pos, w;
} no[maxn];
int n, c, w_sum[maxn], dp[maxn][maxn][2];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    fill(dp[0][0], dp[0][0] + maxn * maxn * 2, inf);
    for (int i = 1; i <= n; i++)
    {
        cin >> no[i].pos >> no[i].w;
        w_sum[i] += w_sum[i - 1] + no[i].w;
    }
    dp[c][c][0] = dp[c][c][1] = 0;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (no[i + 1].pos - no[i].pos) * (w_sum[i] + w_sum[n] - w_sum[j]),
                              dp[i + 1][j][1] + (no[j].pos - no[i].pos) * (w_sum[i] + w_sum[n] - w_sum[j]));
            dp[i][j][1] = min(dp[i][j - 1][1] + (no[j].pos - no[j - 1].pos) * (w_sum[i - 1] + w_sum[n] - w_sum[j - 1]),
                              dp[i][j - 1][0] + (no[j].pos - no[i].pos) * (w_sum[i - 1] + w_sum[n] - w_sum[j - 1]));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
    return 0;
}