#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXM 10005
#define MAXT 10000005

using namespace std;

int t, m, dp[MAXT], v[MAXM], c[MAXM];

int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i] >> v[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        for (int j = c[i]; j <= t; j++)
        {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}