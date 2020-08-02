#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 5005;

int m, n;
ll a[maxn], dp[maxn], t[maxn], ans;

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j] && dp[i] == dp[j])
                t[j] = 0;
            else if (dp[i] == dp[j] + 1 && a[i] < a[j])
            {
                t[i] += t[j];
            }
        }
        if (!t[i])
            t[i] = 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans == dp[i])
        {
            sum += t[i];
        }
    }
    cout << ans << " " << sum << endl;
    return 0;
}