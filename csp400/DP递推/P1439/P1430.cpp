#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, a, b, mp[maxn], c[maxn], dp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        mp[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        c[i] = mp[b];
    }
    int len = 1;
    // fill(dp + 1, dp + n + 1, INF);
    dp[1] = c[1];
    for (int i = 2; i <= n; i++)
    {
        if (c[i] > dp[len])
            dp[++len] = c[i];
        else
        {
            int j = lower_bound(dp + 1, dp + len + 1, c[i]) - dp;
            dp[j] = c[i];
        }
    }
    cout << len << endl;
    return 0;
}
