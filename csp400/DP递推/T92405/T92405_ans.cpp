#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define R register
#define LL __int128
const int inf = 0x3f3f3f3f;
const int MAXN = 100 + 10;

int n, k;
LL dp[MAXN][2];

inline void print(LL x)
{
    if (x > 9)
        print(x / 10);
    putchar('0' + x % 10);
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    while (cin >> n >> k)
    {
        k--;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[1][1] = k ? 1 : 0;
        for (R int i = 2; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            if (i <= k)
                dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            if (i == k + 1)
                dp[i][1] = dp[i - 1][0] + dp[i - 1][1] - 1;
            if (i > k + 1)
                dp[i][1] = dp[i - 1][0] + dp[i - 1][1] - dp[i - k - 1][0];
        }
        LL ans1 = (LL)pow(2.0, n);
        // for (R int i = 1; i <= n; i++)
        //     ans1 = ans1 * 2;
        print(ans1 - dp[n][0] - dp[n][1]);
        putchar('\n');
    }
    return 0;
}