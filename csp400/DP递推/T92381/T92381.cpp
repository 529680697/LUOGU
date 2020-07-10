#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const long long mod = 1000000007;
long long dp[1010][1010];
int n;
char s[1010];

void upd(long long &x)
{
    x = (x + mod) % mod;
}

int main()
{
    while (scanf("%s", s) != EOF)
    {
        n = strlen(s);
        dp[0][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i + 2; j++)
            {
                dp[i][j] = dp[i][j - 1];
                if (s[i - 1] != 'D')
                    upd(dp[i][j] += dp[i - 1][j - 1]);
                if (s[i - 1] != 'I')
                    upd(dp[i][j] += (dp[i - 1][i] - dp[i - 1][j - 1]));
            }
        }
        printf("%lld\n", dp[n][n + 1]);
    }
    return 0;
}