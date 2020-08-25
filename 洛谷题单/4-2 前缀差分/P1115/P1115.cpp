#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 6;

int n, a[maxn], dp[maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = a[0];
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}