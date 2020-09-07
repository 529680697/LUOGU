#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int mod = 998244353;

int n, a[maxn], dp[maxn][40005], inc = 20000, ans;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i][a[i] - a[j] + inc] = (dp[i][a[i] - a[j] + inc] + dp[j][a[i] - a[j] + inc] + 1) % mod;
            ans = (ans + dp[j][a[i] - a[j] + inc] + 1) % mod;
        }
    }
    ans = (ans + n) % mod;
    cout << ans << endl;
    return 0;
}