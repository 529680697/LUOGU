#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int n, a[maxn], dp[maxn][maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = (i + l - 1) % n;
            dp[i][j] = dp[i][i] + dp[(i + 1) % n][j] + a[i] * a[(i + 1) % n] * a[(j + 1) % n];
            for (int mid = 1; mid < l - 1; mid++)
            {
                dp[i][j] = max(dp[i][j], dp[i][(i + mid) % n] + dp[(i + mid + 1) % n][j] + a[i] * a[(i + mid + 1) % n] * a[(j + 1) % n]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i][(i + n - 1) % n]);
    cout << ans << endl;
    return 0;
}