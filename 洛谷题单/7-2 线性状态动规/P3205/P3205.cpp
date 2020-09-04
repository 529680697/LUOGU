#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;

int n, a[maxn], dp[maxn][maxn][2];

int main()
{
    int tmp;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = tmp - 1000;
    }
    for (int i = 0; i < n; i++)
        dp[i][i][0] = 1;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            if (a[i] < a[j])
                dp[i][j][0] = dp[i + 1][j][1], dp[i][j][1] = dp[i][j - 1][0];
            if (a[i] < a[i + 1])
                dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % 19650827;
            if (a[j - 1] < a[j])
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % 19650827;
        }
    }
    cout << (dp[0][n - 1][0] + dp[0][n - 1][1]) % 19650827 << endl;
    return 0;
}