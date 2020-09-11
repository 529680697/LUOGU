// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, K, i_to_king_num[160], to_i[160], cnt;
ll ans, dp[12][160][100];

inline int count_one_num(int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        if ((x >> i) & 1)
            ans++;
    return ans;
}

inline void init()
{
    for (int i = 0; i < (1 << n); i++)
        if (!((i << 1) & i))
            i_to_king_num[++cnt] = count_one_num(i), to_i[cnt] = i;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> K;
    init();
    for (int i = 1; i <= cnt; i++)
        dp[1][i][i_to_king_num[i]] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= cnt; j++)
            for (int k = 1; k <= cnt; k++)
            {
                if (to_i[j] & to_i[k])
                    continue;
                if ((to_i[j] << 1) & to_i[k])
                    continue;
                if ((to_i[k] << 1) & to_i[j])
                    continue;
                for (int l = K; l >= i_to_king_num[j]; l--)
                    dp[i][j][l] += dp[i - 1][k][l - i_to_king_num[j]];
            }
    for (int i = 1; i <= cnt; i++)
        ans += dp[n][i][K];
    cout << ans << endl;
    return 0;
}