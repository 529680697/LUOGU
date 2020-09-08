#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5505;

ll n, w, s, a[maxn];
ll dp[maxn][maxn];
deque<ll> q;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dp[0], dp[0] + maxn * maxn, -inf);
    cin >> n >> w >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= w; i++)
        dp[0][i] = 0;
    dp[1][1] = a[1];
    for (ll i = 2; i <= n; i++)
    {
        while (!q.empty())
            q.pop_back();
        for (int j = 1; j <= min(i - 1, s); j++)
        {
            while (!q.empty() && dp[i - 1][q.back()] < dp[i - 1][j])
                q.pop_back();
            q.push_back(j);
        }

        for (ll j = 1; j <= min(i, w); j++)
        {
            ll l = max(j - 1, (ll)1), r = min(j + s - 1, i - 1);
            while (!q.empty() && q.front() < l)
                q.pop_front();
            if (q.back() < r)
            {
                while (!q.empty() && dp[i - 1][q.back()] < dp[i - 1][r])
                    q.pop_back();
                q.push_back(r);
            }
            dp[i][j] = dp[i - 1][q.front()];
            dp[i][j] += j * a[i];
        }
    }
    ll ans = -inf;
    for (int i = 1; i <= min(n, w); i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}