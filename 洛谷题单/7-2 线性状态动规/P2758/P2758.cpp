#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e3 + 5;

string a, b;
int dp[maxn][maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    for (int i = 0; i <= a.size(); i++)
        dp[i][0] = i;
    for (int i = 0; i <= b.size(); i++)
        dp[0][i] = i;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}