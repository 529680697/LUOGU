// #pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <algorithm>

using namespace std;
const int inf = 0x7fffffff;
#define maxn 505

int n, a[maxn], dp[maxn][maxn];

int dfs(int l, int r)
{
    if (dp[l][r] != inf)
        return dp[l][r];
    if (l == r)
        return dp[l][r] = 1;
    if (a[l] == a[r] && r == l + 1)
        return dp[l][r] = 1;
    if (a[l] == a[r])
        dp[l][r] = dfs(l + 1, r - 1);
    for (int i = l; i < r; i++)
        dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i + 1, r));
    return dp[l][r];
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    fill(dp[0], dp[0] + maxn * maxn, inf);
    cout << dfs(1, n) << endl;
    return 0;
}