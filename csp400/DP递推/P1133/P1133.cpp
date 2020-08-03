#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100005;

int n, a[3][maxn], dp[maxn][3][2];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = max(dp[i - 1][1][1], dp[i - 1][2][1]) + a[0][i];
        dp[i][1][0] = dp[i - 1][2][1] + a[1][i];
        dp[i][1][1] = dp[i - 1][0][0] + a[1][i];
        dp[i][2][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + a[2][i];
    }
    dp[1][0][0] = max(dp[n][1][1], dp[n][2][1]) + a[0][1];
    dp[1][1][0] = dp[n][2][1] + a[1][1];
    dp[1][1][1] = dp[n][0][0] + a[1][1];
    dp[1][2][1] = max(dp[n][0][0], dp[n][1][0]) + a[2][1];
    cout << max(max(dp[1][0][0], dp[1][1][0]), max(dp[1][1][1], dp[1][2][1])) << endl;
    return 0;
}