#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int n, a[maxn], dp[maxn], ans = 1;
bool vis[maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; cin >> a[i]; i++)
        n++;
    // cout << a[i] << endl;
    int len = 1;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= dp[len])
            dp[++len] = a[i];
        else
        {
            int j = upper_bound(dp + 1, dp + len + 1, a[i], greater<int>()) - dp;
            dp[j] = a[i];
        }
    }
    cout << len << endl;
    len = 1;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > dp[len])
            dp[++len] = a[i];
        else
        {
            int j = lower_bound(dp + 1, dp + len + 1, a[i]) - dp;
            dp[j] = a[i];
        }
    }
    cout << len << endl;
    return 0;
}