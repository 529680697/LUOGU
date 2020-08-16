#include <iostream>

using namespace std;

int n;
int dp[1000005][3];

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    dp[0][0] = 1, dp[0][1] = dp[0][2] = 0;
    dp[1][0] = 1, dp[1][1] = dp[1][2] = 0;
    dp[2][0] = 2, dp[2][1] = dp[2][2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][2] + dp[i - 1][1]) % 10000;
        dp[i][1] = (dp[i - 1][2] + dp[i - 2][0]) % 10000;
        dp[i][2] = (dp[i - 1][1] + dp[i - 2][0]) % 10000;
    }
    cout << dp[n][0] << endl;
}