#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int n, m, a[maxn], sum[maxn][maxn];

int dfs(int x, int k)
{
    if (k == 0)
        return 1;
    if (x >= n)
        return 0;
    if (sum[x][k])
        return sum[x][k];
    int ans = 0;
    for (int i = 0; i <= a[x] && i <= k; i++)
    {
        sum[x + 1][k - i] = dfs(x + 1, k - i);
        ans = (ans + sum[x + 1][k - i]) % 1000007;
    }
    return ans;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs(0, m) << endl;
    return 0;
}